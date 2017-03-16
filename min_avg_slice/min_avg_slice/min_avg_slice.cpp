// min_avg_slice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <assert.h>

using std::vector; 

int solution(vector<int>& data)
{
	int N = data.size(); 
	int P = 0, Q = 0; 
	double avg = DBL_MAX; 

	for (int i = 0; i <= N - 1 - 1; ++i)
	{
		double l2avg = (data[i] + data[i + 1]) / 2.0; 
		double l3avg = (i+2<N) ? (data[i] + data[i + 1] + data[i+2] ) / 3.0 : DBL_MAX;
		double lavg = (l2avg > l3avg) ? l3avg : l2avg; 
		if (lavg < avg)
		{
			avg = lavg; 
			P = i; 
		}
	}

	return P; 
}

int main()
{
	int result = 0; 
	vector<int> data; 
	/*
	data = { -100, 200  , 0 , 10 , -2, 9 };
	result = solution(data); 
	assert(result == 2); 

	data = { -100, -200  , 0 , 10 , -2, 9 };
	result = solution(data);
	assert(result == 0);

	data = { 1, -200  , 0 , -100 , -200, 9, 0 , 0 , 0  };
	result = solution(data);
	assert(result == 3);

	data = { 100, -200  , 0 , -100 , 200, 9, 0 , 0 , 0 };
	result = solution(data);
	assert(result == 1);

	data = { 100, 200  , 0 , -100 , 200, 9, 0 , 0 , 0 };
	result = solution(data);
	assert(result == 2);
	*/
	data = { 100, 200  , 900 , -100 , 200, 9, 0 , 0 , 0 };
	result = solution(data);
	assert(result == 6);

	data = { 100, 200  , 900 , -100 , 200, 9, 0 , 0 , -1 };
	result = solution(data);
	assert(result == 7);

	data = { 0 , -1 };
	result = solution(data);
	assert(result == 0);

    return 0;
}

