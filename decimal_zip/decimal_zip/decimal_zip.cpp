// decimal_zip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cassert>
#include <numeric>
#include <vector>

using std::string;
using std::vector;


static string itos(int n)
{
	char buffer[1024];
	sprintf_s(buffer, "%i", n);
	std::string s(buffer);

	return s;
}
int solution(int A, int B) {
	// write your code in C++11 (g++ 4.8.2)

	std::string a = itos(A);
	std::string b = itos(B);

	std::string result;
	uint32_t i, j;
	for (i = 0; i < a.size(); ++i)
	{
		result.push_back(a[i]);
		if (i < b.size())
			result.push_back(b[i]);
	}
	for (j = i; j<b.size(); ++j)
		result.push_back(b[j]);

	int64_t C = atoi(result.c_str());
	if (C > 100000000) return -1; 
	else               return C; 
}

int main()
{
	int32_t A=0, B=0;
	int64_t C = 0; 

	//A = 12; B = 67; 
	//C = solution(A, B);
	//assert(C == 1627);

	A = 12; B = 678;
	C = solution(A, B);
	assert(C == 16278);

	A = 12345; B = 678;
	C = solution(A, B);
	assert(C == 16273845);

	A = 12345; B = 6780;
	C = solution(A, B);
	assert(C == -1);


	A = 1234500; B = 6780;
	C = solution(A, B);
	assert(C == -1);


	/*
	int a_digit = A / 10; 
	int a_remainder = A % 10; 
	int a_N = a_v.size();
	int b_N = b_v.size(); 
	//assert(a_N == 5); 
	//assert(b_N == 5); 

	int factor = 1; 
	for (int i = 0; i < ( a_N + b_N - 1); ++i) factor *= 10;

	int i = 0; int j = 0; 
	for(i=a_N-1; i>=0; --i)
	{
		C += a_v[i] * factor; 
		if (i <= b_N)
		{
			factor /= 10; 
		}


	}
	*/
	return 0;
}

