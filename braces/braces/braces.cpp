// braces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <assert.h>

using std::string;
using std::stack;
using std::vector;

static const string opening = "{[(";
static const string closing = "}])";

int solution(std::string input)
{
	stack<char> punc;
	std::vector<char> data(input.begin(), input.end());
	int matched = 0;

	for (const char i : data)
	{
		if (opening.find(i) != string::npos)
		{
			punc.push(i);
		}
		else
		{
			if (closing.find(i) != string::npos)
			{
				if (punc.empty())
				{
					matched = 0;
					break;
				}
				const char brace = punc.top();
				if ((brace == '{' && i == '}') ||
					(brace == '[' && i == ']') ||
					(brace == '(' && i == ')'))
				{
					++matched;
					punc.pop();
				}
				else
				{
					matched = 0;
					break;
				}
			}
		}
	}

	return matched;
}

using namespace std; 
int main()
{
	string input;
	int result = 0;

	queue<int> q;

	q.push(1); 
	q.push(2);

	int front = q.front(); 
	assert(front == 1); 
	q.pop(); 
	assert(q.front() == 2); 


	/*
	input = "[]{}([]){[ppp]}{(})";
	result = solution(input);

	assert(result == 0);

	input = "{[()()]}";
	result = solution(input);
	assert(result == 4);

	input = "";
	result = solution(input);
	assert(result == 0);

	input = "([)()]";
	result = solution(input);
	assert(result == 0);
	*/
	input = "())";
	result = solution(input);
	assert(result == 0);


	return 0;
}

