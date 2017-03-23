



#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>

using namespace std;


vector<int> solution(vector<int>& input, int K )
{
	if (K > input.size()) 
		K = K % input.size(); 

	vector<int> r(input.size());

	std::copy(input.end() - K,  input.end(), r.begin()     ); 
	std::copy(input.begin(),    input.end() - K, r.begin() + K );

	
	return r;
}

int main()
{

#if 0

	{
		//vector<int> data   = { 1, 2, 4, 5 };
		//vector<int> data = { 3, 8, 9, 7, 6 };
		vector<int> data = { 100, 6 };
		vector<int> result = solution(data, 1 );
 

	}

	{
		//vector<int> data   = { 1, 2, 4, 5 };
		//vector<int> data = { 3, 8, 9, 7, 6 };
		vector<int> data = {};
		vector<int> result = solution(data, 0);
	}
#endif

	{
		//vector<int> data   = { 1, 2, 4, 5 };
		vector<int> data = { 3, 8, 9, 7, 6 };
		vector<int> result = solution(data, 3);
	}


	getchar(); 

    return 0;
}

