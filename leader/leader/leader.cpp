// leader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <cassert>

using std::stack; 
using std::vector; 
using std::pair; 



int via_sort(vector<int> data)
{
	std::sort(begin(data), end(data)); 

	int leader = -1; 
	int N = data.size();
	int Nmajority = (N / 2) ; 
	int count = 0; 
	int candidate = INT_MAX; 

	for (auto i : data)
	{
		if (i == candidate)
		{
			++count; 
			if (count > Nmajority)
			{
				leader = candidate; 
				break;
			}
		}
		else
		{
			candidate = i; 
			count = 1;
			if (count > Nmajority)
			{
				leader = candidate;
				break;
			}
		}
	}

	return leader; 
}


int candidate(vector<int> data)
{
	stack<int> s; 
	for (auto i : data)
	{
		if (s.empty())
		{
			s.push(i);
			continue;
		}
		int top = s.top();
		if (top != i) s.pop(); 
		else s.push(i);
	}

	if( s.empty() ) return -1; 
	else            return s.top(); 

}


int golden(vector<int>& data)
{
	int c = candidate(data); 

	int leader = -1;
	int N = data.size();
	int count = 0;
	int candidate = INT_MAX;
	for (auto i : data)	if (i == c) ++count; 
	
	if (count > N / 2) return  c; 
	else               return -1; 
}


int equileaders(vector<int>& data)
{
	int c = candidate(data);

	int N = data.size();
	int count = 0;

	vector<pair<int,int>> index_N; 
	for (int i = 0; i < N; ++i)
	{
		if (data[i] == c)
		{
			++count;
			pair<int, int> p(i, count); 
			index_N.push_back( p ); 
		}
	}

	if (count <= N / 2)  return 0 ;

	int Neq = 0; 
	int total = count; 
	// we know the leader and the count - 
	// now see how many equileaders there are 
	for (auto i : index_N)
	{
		int Nl = i.first +1; 
		int Nr = N - Nl; 
		int Tl = i.second; 
		int Tr = total - Tl; 
		if (Tl > Nl / 2 && Tr > Nr / 2)
		{
			++Neq; 
		}
	}

	return Neq; 
}


int main()
{
	vector<int> data; 
	int leader = -1;
	int NeqLeaders = 0; 

	data = { 4,3,4,4,4,2 };
	NeqLeaders = equileaders(data);
	assert( NeqLeaders == 2); 

	data = { 4,3,4,4,4,2,4 };
	NeqLeaders = equileaders(data);
	assert( NeqLeaders == 3 );

	data = { 4,3,4,5 };
	NeqLeaders = equileaders(data);
	assert(NeqLeaders == 0);

	data = { 2,4,3,4,4,4,2,4 };
	NeqLeaders = equileaders(data);
	assert(NeqLeaders == 1);



	/*
	data = { 8, 4, 6, 6, 6, 6, 8, 8,6 };
	leader = via_sort(data); 
	assert(leader == 6 );

	leader = golden(data);
	assert(leader == 6);

	data = { 8, 4, 6, 6, 6, 6, 8, 8 };
	leader = via_sort(data);
	assert(leader == -1);

	leader = golden(data);
	assert(leader == -1);

	*/
	data = { 8 };
	leader = via_sort(data);
	assert(leader == 8);

	leader = golden(data);
	assert(leader == 8);

	data = { 8 , 3};
	leader = via_sort(data);
	assert(leader == -1);

	leader = golden(data);
	assert(leader == -1);


    return 0;
}

