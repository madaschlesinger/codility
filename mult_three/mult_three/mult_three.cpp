// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using std::vector;
using std::sort; 
using std::accumulate;

int solution(vector<int> v)
{
	int N = v.size(); 
	int M = 3; // multiply 3 numbers
	std::sort(v.begin(), v.end()); 
	int upper2 = v[N - 2] * v[N - 3];
	int upper2a = accumulate(v.rbegin()+1, v.rbegin() + M, 1, std::multiplies<int>() ); 
	int lower2 = v[0] * v[1]; 
	int product = v[N-1];

	if (lower2 > upper2 && product > 0 ) product *= lower2; 
	else product *= upper2; 

	return product; 
}

int main()
{
	// vector<int> data = { 6, 1, 2, 3, 5 , 0 , -10 }; 
	vector<int> data = { -5, -6, -4, -7, -10 }; 
	int result = solution(data); 
    return 0;
}

