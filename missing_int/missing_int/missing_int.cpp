// missing_int.cpp : Defines the entry point for the console application.
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
	return (N * (N + 1)) / 2;
}

int solution(vector<int>& v)
{
	sort(v.begin(), v.end()); 

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		auto next = std::next(i); 
		int elementAtI = *i; 
		int elementAtN = *next; 
		if ( *i + 1 != *next) return *i + 1; 
	}
	
	return -1;
}


int main()
{
	{
		vector<int> data = { 5, 11, 1, 2, 3, 5, 43 };
		int result = solution(data);

		assert(result == 4);
	}
	{
		vector<int> data = { 5, 11, 1, 2, 3, 5, 43, 4 };
		int result = solution(data);

		assert(result == 6);
	}
	/*
	{
		int N = 100000;
		vector<int> data(N);
		for (int i = 0; i < N; ++i) data[i] = i + 2;
		int result = solution(data);

		assert(result == 1);
	}
	*/
    return 0;
}

