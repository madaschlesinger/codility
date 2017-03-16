// ropes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int solution(int K, vector<int>& r)
{
	int Nropes = 0; 

	/*
	start at the begining - Bi
		iterate from Bi and tie ropes together - until length > K -> add to Nreopes
		continue until end of input ropes
		s -- start of segment
		e -- start of next segment ( not inclusive ) - end()/N for last
		l -- length of rope segment
		Nr -- # of ropes
		nri -- # of ropes in iteration ; 

		when you tie a rope - if l>K - 
			++nri ; 
			s = e++ ; 
			Nr = max( Nr, nri
			check if done; 

		next iteration; 
	*/
	int N = r.size(); // of total ropes

	int Nr = 0;

	for (int i = 0; i < N ;++i)
	{
		int s = i; 
		int e = i + 1; 
		int nri = 0;
		int l = 0; 

		for (int j = i; j < N; ++j)
		{
			l += r[j]; 
			if(l >= K)
			{
				++nri; 
				l = 0;
			}
		}

		Nr = max(Nr, nri); 

	}


	return Nr; 
}

int main()
{
	int K, expected, Nropes ; 

#if 1
	{
		vector<int> ropes = { 1,2,3,4,1,1,6 };

		K = 4; expected = 3;
		assert(ropes.size() == 7);

		Nropes = solution(K, ropes);
		assert(Nropes == expected);
	}
#endif


#if 1
	{
		vector<int> ropes = { 1,2 };

		K = 4; expected = 0;
		Nropes = solution(K, ropes);
		assert(Nropes == expected); 
	}
#endif


#if 1
	{
		vector<int> ropes = { 4 };

		K = 4; expected = 1;
		Nropes = solution(K, ropes);
		assert(Nropes == expected);
	}
#endif 

#if 1
	{
		vector<int> ropes = { 4,4 };

		K = 4; expected = 2;
		Nropes = solution(K, ropes);
		assert(Nropes == expected);
	}

	{
		vector<int> ropes = { 4,1,1,1,2,2,2,2,2,2 };

		K = 4; expected = 4;
		Nropes = solution(K, ropes);
		assert(Nropes == expected);
	}

	{
		vector<int> ropes = {2,3,4,6,4,6,4,6 };

		K = 10; expected = 3;
		Nropes = solution(K, ropes);
		assert(Nropes == expected);
	}


#endif

    return 0;
}

