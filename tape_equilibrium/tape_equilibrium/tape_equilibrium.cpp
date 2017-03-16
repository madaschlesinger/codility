// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <numeric>
#include <vector>
#include <iostream>

using namespace std; 
int solution(vector<int>& input)
{
	int total = accumulate(begin(input), end(input), 0); 
	int sum_l = input[0], sum_r=0, least = _MAX_INT_DIG ;
	//int sum_r = 0; 
	//int least = _MAX_INT_DIG; 
	for (auto i = ++begin(input); i !=end(input); ++i )
	{
		sum_r = total - sum_l; 
		int diff = abs(sum_r - sum_l);
		least = (least > diff) ? diff : least; 
		sum_l += *i; 
	}

	return least; 

}

int main()
{
	vector<int> data = { 3,1,2,4,3 }; 

	int least = solution(data); 
	cerr << least << endl;
    return 0;
}

