// peaks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cassert>

using namespace std;

template<typename Iter>
bool is_a_peak( Iter iter )
{
	return *std::prev(iter) < *iter && *iter < *std::next(iter); 
}

typedef vector < vector<int>::const_iterator > vector_int_iterator; 

vector_int_iterator npeaks(vector<int>& v)
{
	vector<vector<int>::const_iterator> peaks ; 
	for (auto i = std::next(begin(v)); i != std::prev(end(v)); ++i)
		if( is_a_peak(i) )
			peaks.push_back( i );

	return peaks;
}

int solution(vector<int>& v)
{
	vector_int_iterator peaks = npeaks(v);

			
	return peaks.size(); 
}


int main()
{
	vector<int> a{ 1,2,3,4,3,4,1,2,3,4,6,2 };
	vector<int> b{ 1,2,3 };

	int peaks = solution(b);
	assert(peaks == 1);

	peaks = solution(a);
	assert(peaks == 3);


    return 0;
}

