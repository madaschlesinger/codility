// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"


#include <numeric>
#include <vector>
#include <iostream>
#include <functional>

using std::vector; 
using std::cerr; 
using std::endl; 

int solution(vector<int>& data)
{
	int result = 0; 

	for(auto i : data) 	result = result^i ; 

	return result;

}

int main()
{
	vector<int> data = { 3,1,2,4,3 ,1, 33, 4, 2};

	int odd = solution(data);
	cerr << odd << endl;
	return 0;
}

