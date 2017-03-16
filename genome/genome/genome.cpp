// genome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cassert>

using std::string; 
using std::vector;
using std::min;
using std::max;
using namespace std; 

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
	int N = S.size();
	vector<int> A(N+1,0), C(N+1,0), G(N+1,0), T(N+1,0);

	// 0 element - reserved for starting '0' index in the prefix_sum is one based
	for( uint32_t i =1; i<=S.size(); ++i)
	{
		int a =  A[i - 1]; 
		int c =  C[i - 1];
		int g =  G[i - 1];
		int t =  T[i - 1];
		A[i] = a+( 1* (int)(S[i-1] == 'A')); 
		C[i] = c+( 2* (int)(S[i-1] == 'C'));
		G[i] = g+( 3* (int)(S[i-1] == 'G'));
		T[i] = t+( 4* (int)(S[i-1] == 'T'));
	}

	if (S == "CAGCCTA")
	{
		assert(A.size()==8);
		assert(A[0] == 0); 
		assert(A[1] == 0);
		assert(A[2] == 1);
		assert(A[3] == 1);
		assert(A[4] == 1);
		assert(A[5] == 1);
		assert(A[6] == 1);
		assert(A[7] == 2);

		assert(C[0] == 0);
		assert(C[1] == 2);
		assert(C[2] == 2);
		assert(C[3] == 2);
		assert(C[4] == 4);
		assert(C[5] == 6);
		assert(C[6] == 6);
		assert(C[7] == 6);

	}

	
	vector<int> results;

	for( uint32_t i = 0 ; i < P.size();  ++ i )
	{
		int factor = A[0] + C[0] + G[0] + T[0]; 

		int p = P[i];  // P is zero based, index to A,C etc. is one based thus 'p' is one before desired input 
		int q = Q[i]+1;

		if      (A[p] != A[q]) factor = 1;
		else if (C[p] != C[q]) factor = 2;
		else if (G[p] != G[q]) factor = 3;
		else if (T[p] != T[q]) factor = 4;
		else factor = -1; // error
		
		results.push_back(factor);
	}

	
	return results; 
}

int main()
{
	string S = "CAGCCTA"; 
#if 1
	{
		vector<int> P = { 2,5,0 };
		vector<int> Q = { 4,5,6 };

		vector<int> result = solution(S, P, Q);

		assert(result[0] == 2);
		assert(result[1] == 4);
		assert(result[2] == 1);

		;
	}
#endif 
#if 1 
	{
		vector<int> P = {0,1};
		vector<int> Q = {0,1};

		vector<int> result = solution(S, P, Q);

		assert(result[0] == 2);
		assert(result[1] == 1);

		//auto print = [&](vector<int>&result) { for (auto i : result) cerr << i << '\t'; cerr << endl;  }; 
		//print(result); 

	}
#endif 
    return 0;
}

