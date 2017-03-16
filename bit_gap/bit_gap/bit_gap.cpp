// bit_gap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <numeric>
#include <iostream>
#include <string>
#include <bitset>

int solution(int N)
{
	int sz     = sizeof(N) * 8 ;
	std::bitset<sizeof(N) * 8> bs(N); 
	std::string ss = bs.to_string();
	bool start = false; // have we even started
	int Ngap   = 0; // largest gap found so far
	int Ncurr  = 0; // current gap being counted 

	for (short i = 0; i < sz; ++i)
	{
		bool b = (N >> i) & 1;
		start = start || b; 
		if (!start) continue; 
		if(b)
		{
			if (Ncurr && Ncurr > Ngap) Ngap = Ncurr; 
			Ncurr = 0; 
			continue; 
		}

		// bit was zero & we are in counting mode
		++Ncurr; 
	}

	return Ngap;
}



int main()
{
	int N = 8 + 512+ 1024 * 1024 ; 
	int gap = solution(N); 
    return 0;
}

