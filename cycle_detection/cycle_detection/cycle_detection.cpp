// cycle_detection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef int Node; 

/*
struct Node
{
	static int N;
	int x, y, n;

	Node(int xx, int yy) : x{ xx }, y{ yy }, n{ ++N } {}
};
*/

struct Graph
{
	int N;
	vector< vector<Node> > nodes; // each node is an integer

	Graph(int n) :N{ n }, nodes(n) {}

	void add_edge(Node a, Node b)
	{
		nodes[a].push_back(b);
	}


	// This function is a variation of DFSUytil() in http://www.geeksforgeeks.org/archives/18212
	bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
	{
		if (visited[v] == false)
		{
			// Mark the current node as visited and part of recursion stack
			visited[v] = true;
			recStack[v] = true;

			// Recur for all the vertices adjacent to this vertex

			for (auto i = nodes[v].begin(); i != nodes[v].end(); ++i)
			{
				if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
					return true;
				else if (recStack[*i])
					return true;
			}

		}
		recStack[v] = false; // remove the vertex from recursion stack
		return false;
	}

	// Returns true if the graph contains a cycle, else false.
	// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
	bool Graph::isCyclic()
	{
		// Mark all the vertices as not visited and not part of recursion
		// stack
		/*
		bool *visited = new bool[V];
		bool *recStack = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
			recStack[i] = false;
		}
		*/

		std::vector<bool> visited(N); // , false);
		std::vector<bool> recStack(N, false);

		fill( visited.begin(), visited.end(), false);




		// Call the recursive helper function to detect cycle in different
		// DFS trees
		//XXXfor (int i = 0; i < N; i++)
		//	if (isCyclicUtil(i, visited, recStack))
		//		return true;

		return false;
	}
};


int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}





