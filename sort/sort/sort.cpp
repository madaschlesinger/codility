// sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <iostream>

using std::vector;
using std::sort;
using std::accumulate;
using std::cerr; 
using std::endl;

std::vector<int>::const_iterator F;
std::vector<int>::const_iterator L;

// TODO - lambda....
template<typename Iter>
void print(Iter first, Iter last)
{
	cerr << "{ ";
	for (auto i = first; i != last; ++i)
		std::cerr << *i << ", ";

	std::cerr << "}" << std::endl;
}


template<typename Iter>
int pivot(Iter first, Iter last) 
{
	auto f = *first; 
	int  N = std::distance(first, last);
	auto l = *std::prev(last);

	return (f + l) / 2; 
}


template<typename Iter, typename Compare = std::less<> >
auto quick_swap(Iter first, Iter last, Compare cmp = Compare{}) -> void
{
	auto p = pivot(first, last);
	auto iter_r = std::next(last, -1);  

	// iter_l - left, iter_r is right we walk in from both directions
	// and compare to pivot w/cmp == lt, if left>p && right <p - swap(left,right)

	for(auto iter_l = first; iter_l < iter_r; ++iter_l )
	{
		if( cmp( p, *iter_l ) && !cmp( p, *iter_r ) )
		{
			auto swap = *iter_l;
			*iter_l   = *iter_r; 
			*iter_r   = swap; 

			iter_r    = std::next(iter_r, -1);
		}
	}

}


template<typename Iter, typename Compare = std::less<> >
auto quick_sort(Iter first, Iter last, Compare cmp = Compare{}) -> void
{
	int N = std::distance(first, last);
	if (N <= 1) return;

	std::cerr << "N: " << N << endl;
	print(first, last);

	auto val = *first; 
	std::vector<decltype(val)> copy(first, last);

	const auto middle = std::next(first, N / 2);

	auto left  = first, right = std::prev(last); 
	auto l     = left, r = right; 
	auto pivot = *std::next(first, N / 2); 

	while (l <= r)
	{
		while (*l < pivot) ++l;
		while (*r > pivot) --r;

		if (l <= r)
		{
			//std::cerr << "*** Sorted N: " << N << " **** start swap ****" << *l << " < " << pivot << " < " << *r << " left:" << *left << " right:" << *right << endl;
			//print(left, right+1);

			std::swap(*l++, *r--);

			//print(F, L);
			//std::cerr << "*** Sorted N: " << N << " **** done  swap ****" << endl;

		}
	}


	quick_sort(first,  ++r,  cmp); 
	quick_sort(l,      last, cmp);

	std::cerr << "*** Sorted N: " << N << " **** start ****" << endl;
	print(first, last);
	print(F, L);
	std::cerr << "*** Sorted N: " << N << " **** done  ****" << endl;

}



template<typename Iter,typename Compare = std::less<> >
 auto merge_sort(Iter first, Iter last, Compare cmp = Compare {}) -> void 
{
	int N = std::distance(first, last);

	std::cerr << "N: " << N << endl;
	print(first, last); 

	if (N == 1) return; 

	const auto middle = std::next(first, N / 2); 

	merge_sort(first, middle, cmp); 
	merge_sort(middle, last, cmp); 

	std::inplace_merge(first, middle, last, cmp); 

	std::cerr << "*** Sorted N: " << N << " **** start ****" << endl;
	print(first, last);
	print(F, L);
	std::cerr << "*** Sorted N: " << N << " **** done  ****" << endl;

}


template<typename Iter, typename Compare = std::less<> >
auto bubble_sort(Iter first, Iter last, Compare cmp = Compare{}) -> void 
{
	int N = std::distance(first, last);
	if (N == 1) return;

	for(auto i=first; i != last ; ++i )
		for (auto j = std::next(i); j != last; ++j)
		{
			auto left = *i;
			auto right = *j;

			if(cmp(*j, *i))
			{
				auto swap = *i; 
				*i = *j; 
				*j = swap; 
			}
		}
}




int main()
{

	{
		vector<int> v = { 3 , 2,  1 };
		
		auto cmp = std::less<int>();

		F = v.begin();
		L = v.end();

		bubble_sort(v.begin(), v.end(), cmp);
		print(v.begin(), v.end());

	}

#if 0 

	{
		vector<int> v = { 15 , 9,  1 , 53, 23, 11, 2 };
		auto aaa = *v.begin(); 
		std::vector< decltype(aaa) > vv(v.begin(), v.end());
		auto cmp = std::less<int>();

		F = v.begin();
		L = v.end();

		quick_sort(v.begin(), v.end(), cmp);
		print(v.begin(), v.end());

	}

#endif 

#if 0

	{
		auto cmp = std::less<int>();
		auto eq = cmp(5, 5);
		auto lt = cmp(0, 3); 
		auto gt = std::greater<int>()(4, 2);
		assert( cmp(5,5) == 0 );
	}
#endif
#if 0 
	{
		vector<int> v   = { 5, 11, 1, 2, 3, 5, 43 };
		auto cmp = std::less<int>();

		bubble_sort(v.begin(), v.end(), cmp);
		print(v.begin(), v.end() );

	}
	{
		vector<int> v = { 5, 11, 1, 2, 3, 5, 43 };
		auto cmp = std::greater<int>();

		bubble_sort(v.begin(), v.end(), cmp);
		print(v.begin(), v.end());

	}
#endif
#if 0

	{
		vector<int> v = { 11, 5, 12, 22, 19, 2, 8, -1  };
		auto cmp = std::less<int>();

		F = v.begin(); 
		L = v.end(); 

		merge_sort(v.begin(), v.end(), cmp);
		print(v.begin(), v.end());

	}
	{, 8 
		vector<int> v = { 5, 11, 1, 2, 3, 5, 43 };
		auto cmp = std::greater<int>();

		merge_sort(v.begin(), v.end(), cmp);
		print(v.begin(), v.end());

	}
#endif

	getchar();
    return 0;
}

