// non_overlapping_segements.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// this code is not correct.......

int segments(const vector<int>& a, const vector<int>& b, int i, vector<int>& cache)
{
	assert(i >= 0); 
	if (cache[i]) return cache[i]; 

	int N = 0, cost = -1, L = b[i]-a[i]; 
	
	if (i > 0)
	{
		int nOfMinusOne  = segments(a, b, i - 1, cache);
		int nOfMinusL = 0; 
		
		if( i - L > 0 && L >0 ) nOfMinusL = segments(a, b, i - L, cache) ;
		else if (L == 0)        nOfMinusL = 1;

		N = std::max(1 + nOfMinusL, nOfMinusOne); 
	}
	if (i == 0) N = 1;


	cache[i] = N; 

	return cache[i];
}


int solution(vector<int>& a, vector<int>& b)
{
	vector<int> cache(b.size()); 

	int N = segments(a, b, b.size() - 1, cache); 

	return N;
}


int main()
{
	// line segment denoted by (a[i],b[i]) - segment 
	// can be a single point
	// solution - max non overllapping line segemnts == 3
	{
		vector<int> a{ 1,3,7,9,9 };
		vector<int> b{ 5,6,8,9,10 };

		int N = solution(a, b);
		assert(N == 3);
	}

	{
		vector<int> a{ 6 };
		vector<int> b{ 6 };

		int N = solution(a, b);
		assert(N == 1);
	}

	{
		vector<int> a{ 6,6 };
		vector<int> b{ 6,9 };

		int N = solution(a, b);
		assert(N == 1);
	}

	{
		vector<int> a{ 1 };
		vector<int> b{ 6 };

		int N = solution(a, b);
		assert(N == 1);
	}

	getchar();

	return 0;
}



