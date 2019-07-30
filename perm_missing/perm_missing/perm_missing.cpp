// perm_missing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>

using std::vector;
using std::sort;
using std::accumulate;

long sequence_total(int N)
{
	return ( N * ( N + 1 ) )/ 2;
}

int solution_wrong(vector<int>& input)
{
	int N     = input.size(); 
	long total = sequence_total(N + 1); 
	long sum   = accumulate(input.begin(), input.end(), 0 );
	return total - sum ;
}

int solution_a(vector<int> &A) 
{
	vector<bool> seen(A.size(), false);

	for (unsigned int i = 0; i < A.size(); i++) {
		seen[i] = false;
	}

	for (unsigned int i = 0; i < A.size(); i++) {
		if (!(0 < A[i] && A[i] <= A.size() && seen[A[i] - 1] == false)) {
			return 0;
		}
		else {
			seen[A[i] - 1] = true;
		}
	}

	return 1;
}


int solution(vector<int> &A)
{
	int64_t result = 0;

	for (unsigned int i = 0; i < A.size(); i++) 
	{
		if (A[i] < 0 || A[i] > A.size()) return 0;

		auto index = i + 1; // one based
		result ^=  index ^ A[i] ;
	}

	return result == 0 ;
}


int main()
{
	/*
	{
		vector<int> data = { 1, 2, 4, 5 };
		int result = solution(data);

		assert(result == 3);
	}
	*/
	{
		vector<int> data = { 1, 2, 3, 2 };
		int result = solution(data);

		assert(result == 0);
	}
	
	
	{
		vector<int> data = { 1, 2, 3, 4 };
		int result = solution(data);

		assert(result ==  1);
	}
	
	{
		vector<int> data = { 4, 2, 3, 1 };
		int result = solution(data);

		assert(result == 1);
	}
/*
	{
		int N = 100000;
		vector<int> data(N);
		for (int i = 0; i < N; ++i) data[i] = i+1; 
		int result = solution(data);

		assert(result == 1);
	}
*/




    return 0;
}

