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

int solution(vector<int>& input)
{
	int N     = input.size(); 
	long total = sequence_total(N + 1); 
	long sum   = accumulate(input.begin(), input.end(), 0 );
	return total - sum ;
}

int main()
{
	/*
	{
		vector<int> data = { 1, 2, 4, 5 };
		int result = solution(data);

		assert(result == 3);
	}

	{
		vector<int> data = { 1, 2, 3, 5 };
		int result = solution(data);

		assert(result == 4);
	}
	*/
	/*
	{
		vector<int> data = { 1, 2, 3, 4 };
		int result = solution(data);

		assert(result == 5);
	}
	*/

	{
		int N = 100000;
		vector<int> data(N);
		for (int i = 0; i < N; ++i) data[i] = i+2; 
		int result = solution(data);

		assert(result == 1);
	}



    return 0;
}

