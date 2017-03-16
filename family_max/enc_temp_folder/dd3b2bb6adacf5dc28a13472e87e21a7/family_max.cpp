// family_max.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <cassert>
using std::vector;
using std::string;
/*
int solution_family(int N)
{
	vector<int> digits = count(N);

	string res;
	char buffer[6];
	for (int i = digits.size() - 1; i >= 0; --i)
	{
		if (digits[i])
		{
			for (int j = 0; j < digits[i]; ++j)
			{
				sprintf_s(buffer, "%i", i + 1);
				res.push_back(buffer[0]);
			}
		}
	}
	return atoi(res.c_str());
}

*/

vector<int> factors()
{
	vector<int> result = { 1 };
	int N = 10; 
	for (int i = 1; i < N; ++i)
		result.push_back(result[i - 1] * -2);
	return result; 

}


int solution(vector<int> &A)
{
	int N = A.size(); 
	vector<int> powers = factors();

	assert(powers[0] == 1); 
	assert(powers[1] == -2);
	assert(powers[2] == 4);
	assert(powers[3] == -8);
	assert(powers[7] == -128);

	int result = 0; 
	for (int i = 0; i < N; ++i)
	{
		result += powers[A[i]];
	}


	return result; 
}

int main()
{
	vector<int> A = { 5,4,7 };

	int result = solution(A); 
	assert(result == -144);


	/*
	int N = 355; 
	int result = solution(N); 
	assert(result = 553);

	assert(solution(123) == 321);
	assert(solution(78328) == 88732);
	*/
    return 0;
}

