// fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <functional>
#include <vector>
#include <cassert>

using std::function; 
using std::vector;


// recursive lamba - likely not great for complexity
function<int(int)> fibonacci = [&](int n) -> int
{
	if (n < 1) return 0; 
	if (n == 1 || n == 2) return 1;

	else return fibonacci(n - 1) + fibonacci(n - 2); 
}; 

int fibonacci_dynamic(int n)
{
	vector<int> memo(n+2, 0);
	memo[1] = 1; 

	for (uint64_t i = 2; i < n + 1; ++i) memo[i] = memo[i - 1] + memo[i - 2];

	return memo[n];

}


int main()
{
	assert(fibonacci(0) == fibonacci_dynamic(0));
	assert(fibonacci(1) == fibonacci_dynamic(1));
	assert(fibonacci(2) == fibonacci_dynamic(2));
	assert(fibonacci(6) == fibonacci_dynamic(6));

	return 0;
}

