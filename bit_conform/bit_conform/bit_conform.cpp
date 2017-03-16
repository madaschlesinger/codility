// bit_conform.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include <algorithm>

using std::max;
using std::min;

bool conform(int A, int B)
{
	bool result = ((A & B) == A);
	return ((A & B ) == A);
}

int solution(int A, int B, int C) {
	// write your code in C++11 (g++ 4.8.2)
	int count = 0;
	int lmin = min(min(A, B), C);
	int lmax = 1073741823;

	for (int i = lmin; i <= lmax; ++i)
	{		
		if (conform(A, i) || conform(B, i) || conform(C, i))
			++count;
	}
	
	return count;
}

int main()
{
	int A, B, C;
	{
		assert(conform(1, 2) == false);
		assert(conform(4, 6) == true);
		assert(conform(6, 4) == false);
		B = 16244239;
		A = 13032961;
		assert(conform(A, B) == true);

		A = 1073741727;
		B = 1073741631;
		C = 1073741679;

		assert(conform(A, A) == true);

		int D = 1073741807; 
		bool DA = conform(A,D); 
		bool DB = conform(B,D);
		bool DC = conform(C,D);

		assert( (DA || DB || DC) == true );
	}

	A = 1073741727;
	B = 1073741631;
	C = 1073741679;
	int count = solution(A, B, C);
	assert(count == 8); 
    return count;
}

