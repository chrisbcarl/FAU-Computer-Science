/*
Kevin Seepaul
Dr. Feng-Hao Liu
hw6.cpp
*/
#pragma once

#include <iostream>

using namespace std;

class Graph
{
private:
	int n;									//cardinality
	int **adjmatrix;						//adjacency matrix
public:
	Graph();
	Graph(const int n, int** m);
	Graph(const Graph& rhs);
	~Graph();
	bool adj(int i, int j);					// return true if i --> j
	int outdegree(int i);					// return the outdegree of the node i
	int indegree(int i);					// return the outdegree of the node i

											// the following funcitons are bonus (can be used to replace the final)
	void BFS();								// print according to Breadth-first search
	void DFS();								// print according to Depth-first search
	bool isConnected();						// return true iff the graph is connected
	bool exist_cycle();						// return true iff the graph has a cycle
};

Graph::Graph()
{
	n = 0;
	adjmatrix = 0;
}

Graph::Graph(const int n, int** m)
{
	this->n = n;
	if (m != 0)
	{
		//copy the input 2d matrix to prevent 
		//reference clashes or null reference issues
		adjmatrix = new int*[n];
		for (int i = 0; i < n; i++)
		{
			adjmatrix[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				adjmatrix[i][j] = m[i][j];
			}
		}
	}
}

Graph::Graph(const Graph& rhs)
{
	n = rhs.n;
	if (rhs.n != 0)
	{
		//copy the rhs 2d matrix to prevent 
		//reference clashes or null reference issues
		adjmatrix = new int*[rhs.n];
		for (int i = 0; i < rhs.n; i++)
		{
			adjmatrix[i] = new int[rhs.n];
			for (int j = 0; j < rhs.n; j++)
			{
				adjmatrix[i][j] = rhs.adjmatrix[i][j];
			}
		}
	}
}

Graph::~Graph()
{
	if (adjmatrix != 0)
	{
		//delete 1D arrays from the last to first.
		for (int i = n - 1; i > -1; i--)
		{
			delete[] adjmatrix[i];
		}
		delete[] adjmatrix;
	}
}

// return true if i --> j
bool Graph::adj(int i, int j)
{
	if (adjmatrix != 0)
	{
		//if the adjacency matrix doesn't have a 0,
		//they are adjacent
		return adjmatrix[i][j] != 0;
	}
	else return 0;
}

// return the outdegree of the node i
int Graph::outdegree(int i)
{
	if (adjmatrix != 0)
	{
		int outdegree = 0;
		for (int j = 0; j < n; j++)
		{
			//add the truth value of adjacency from i to j.
			outdegree += adj(i, j);
		}
		return outdegree;
	}
	else return -1;
}

// return the outdegree of the node i
int Graph::indegree(int i)
{
	if (adjmatrix != 0)
	{
		int indegree = 0;
		for (int j = 0; j < n; j++)
		{
			//add the truth value of adjacency from j to i.
			indegree += adj(j, i);
		}
		return indegree;
	}
	else return -1;
}

int main()
{
	int cardinality = 4;
	int** m1 = new int*[cardinality];
	int zer[4] = { 0, 5, 4, 7 };
	int one[4] = { 2, 0, 3, 0 };
	int two[4] = { 8, 9, 0, 1 };
	int thr[4] = { 3, 0, 5, 2 };
	m1[0] = zer;	m1[1] = one;	m1[2] = two;	m1[3] = thr;

	int** m2 = new int*[cardinality];
	int zer_d[4] = { 0, 0, 7, 0 };
	int one_d[4] = { 8, 0, 0, 0 };
	int two_d[4] = { 0, 2, 0, 0 };
	int thr_d[4] = { 4, 0, 6, 7 };
	m2[0] = zer_d;	m2[1] = one_d;	m2[2] = two_d;	m2[3] = thr_d;

	Graph g1 = Graph(cardinality, m1);
	for (int i = 0; i < cardinality; i++)
	{
		cout << "node " << i << " indegree " << i << " = " << g1.indegree(i) << "\t";
		cout << "outdegree " << i << " = " << g1.outdegree(i) << endl;
		for (int j = 0; j < cardinality; j++)
			cout << i << " adjacent to " << j << " = " << g1.adj(i, j) << "\t";
		cout << endl << endl;
	}
	cout << endl << endl;

	Graph g2 = Graph(cardinality, m2);
	for (int i = 0; i < cardinality; i++)
	{
		cout << "indegree " << i << " = " << g2.indegree(i) << "\t";
		cout << "outdegree " << i << " = " << g2.outdegree(i) << endl;

		for (int j = 0; j < cardinality; j++)
			cout << i << " adjacent to " << j << " = " << g2.adj(i, j) << "\t";
		cout << endl << endl;
	}
	cout << endl << endl;

	Graph g0;
	Graph g3 = g1;
	Graph g4 = g2;
	return 0;
}