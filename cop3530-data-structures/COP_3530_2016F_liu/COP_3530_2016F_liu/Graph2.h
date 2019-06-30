#pragma once

#include <iostream>
#include <queue>

using namespace std;

class Graph
{
private:
	int n;									//cardinality
	int **adjmatrix;						//adjacency matrix
	bool *discovered;						//keeps track of nodes that have been discovered
public:
	Graph();
	Graph(const int n, int** m);
	Graph(const Graph& rhs);
	~Graph();
	bool adj(int i, int j);					// return true if i --> j
	int outdegree(int i);					// return the outdegree of the node i
	int indegree(int i);					// return the outdegree of the node i

	// the following funcitons are bonus (can be used to replace the final)
	void BFS(int start);					// print according to Breadth-first search
	void DFS(int start);					// print according to Depth-first search
	void DFS_Vertex(int start);				// recursive helper function to DFS
	
	
	void ResetDiscovered();					// resets discovered node to all false
	bool isConnected();						// return true iff the graph is connected
	bool exist_cycle();						// return true iff the graph has a cycle
	bool DFS_Cycle(int start, vector<int>& white_set, vector<int>& grey_set, vector<int>& black_set);
};

Graph::Graph()
{
	n = 0;
	adjmatrix = 0;
	discovered = 0;
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

		discovered = new bool[n];
		for (int i = 0; i < n; i++)
		{
			discovered[i] = false;
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

		discovered = new bool[n];
		for (int i = 0; i < n; i++)
		{
			discovered[i] = false;
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

//https://www.youtube.com/watch?v=ls4cHglfc0g
void Graph::BFS(int start)
{
	//make a table of all of the discovered nodes.
	ResetDiscovered();
	discovered[start] = true;
	queue<int> q = queue<int>();
	
	int i = start;
	q.push(i);

	while (!q.empty())
	{
		i = q.front();
		q.pop();
		cout << i << " ";
		for (int j = 0; j < n; j++)
		{
			if ((adjmatrix[i][j] != 0) && (discovered[j] == false))
			{
				discovered[j] = true;
				q.push(j);
			}
		}
	}
}

//https://www.youtube.com/watch?v=qH-mHxkoK0Q
void Graph::DFS(int start)
{
	//make a table of all of the discovered nodes.
	ResetDiscovered();
	DFS_Vertex(start);
}

void Graph::DFS_Vertex(int start)
{
	discovered[start] = true;
	for (int j = 0; j < n; j++)
	{
		if ((adjmatrix[start][j] != 0) && (discovered[j] == false))
		{
			DFS_Vertex(j);
		}
	}
	cout << start << " ";
}



void Graph::ResetDiscovered()
{
	if (discovered != 0)
	{
		for (int i = 0; i < n; i++)
		{
			discovered[i] = false;
		}
	}
}

bool Graph::isConnected()
{
	//make a table of all of the discovered nodes.
	ResetDiscovered();
	discovered[0] = true;
	queue<int> q = queue<int>();

	int i = 0;
	int count = 0;
	q.push(i);

	while (!q.empty())
	{
		i = q.front();
		q.pop();
		count++;
		for (int j = 0; j < n; j++)
		{
			if ((adjmatrix[i][j] != 0) && (discovered[j] == false))
			{
				discovered[j] = true;
				count++;
			}
		}
	}
	return count == n;
}

bool Graph::exist_cycle()
{
	vector<int> white_set;
	vector<int> grey_set;
	vector<int> black_set;

	for (int i = 0; i < n; i++)
	{
		white_set.push_back(i);
	}

	int x = 0;
	while (!white_set.empty())
	{
		x = white_set.back();
		return DFS_Cycle(x, white_set, grey_set, black_set);
	}
	return false;
}

bool Graph::DFS_Cycle(int vertex, vector<int>& white_set, vector<int>& grey_set, vector<int>& black_set)
{
	start.pop_back();
	grey_set.push_back(vertex);

	bool black_contains_vertex = false;
	bool grey_contains_vertex = false;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < black_set.size(); i++)
		{
			black_contains_vertex = black_contains_vertex || (black_set[i] = j);
		}
		for (int i = 0; i < grey_set.size(); i++)
		{
			grey_contains_vertex = grey_contains_vertex || (grey_set[i] = j);
		}

		if (black_contains_vertex)
		{
			continue;
		}

		if (grey_contains_vertex)
		{
			return true;
		}

		return false || DFS_Cycle(j, white_set, grey_set, black_set);
	}
	black_set.push(start);
}

int graphTest() 
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

	int** m3 = new int*[9];
	int zer_b[9] = { 0, 1, 1, 0, 0, 0, 0, 0, 0 };
	int one_b[9] = { 0, 0, 0, 1, 1, 0, 0, 0, 0 };
	int two_b[9] = { 0, 0, 0, 0, 0, 1, 1, 0, 0 };
	int thr_b[9] = { 0, 1, 1, 0, 0, 0, 0, 0, 0 };
	int fou_b[9] = { 0, 0, 0, 0, 0, 0, 0, 1, 0 };
	int fiv_b[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int six_b[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	int sev_b[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int eig_b[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	m3[0] = zer_b;	m3[1] = one_b;	m3[2] = two_b;	m3[3] = thr_b;
	m3[4] = fou_b;	m3[5] = fiv_b;	m3[6] = six_b;	m3[7] = sev_b;	m3[8] = eig_b;

	int** m4 = new int*[6];
	int zer_g[6] = { 0, 1, 1, 0, 0, 0 };
	int one_g[6] = { 0, 0, 0, 0, 0, 0 };
	int two_g[6] = { 0, 0, 0, 0, 0, 0 };
	int thr_g[6] = { 0, 0, 0, 0, 1, 0 };
	int fou_g[6] = { 0, 0, 0, 0, 0, 1 };
	int fiv_g[6] = { 0, 0, 0, 1, 0, 0 };
	m4[0] = zer_g;	m4[1] = one_g;	m4[2] = two_g;	
	m4[3] = thr_g;	m4[4] = fou_g;	m4[5] = fiv_g;

	Graph g1 = Graph(cardinality, m1);
	cout << "GRAPH 1: Non-directional Graph with Cardinality 4" << endl;
	cout << "isConnected = " << g1.isConnected() << "\t";
	cout << "exist_cycle = " << g1.exist_cycle() << endl;
	for (int i = 0; i < cardinality; i++)
	{
		cout << "node " << i << " indegree " << i << " = " << g1.indegree(i) << "\t";
		cout << "outdegree " << i << " = " << g1.outdegree(i) << endl;
		for (int j = 0; j < cardinality; j++)
			cout << i << " adjacent to " << j << " = " << g1.adj(i, j) << "\t";
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "g1.BFS(0) = ";	 g1.BFS(0);		cout << endl;
	cout << "g1.BFS(1) = ";	 g1.BFS(1);		cout << endl;
	cout << "g1.BFS(2) = ";	 g1.BFS(2);		cout << endl;
	cout << "g1.BFS(3) = ";	 g1.BFS(3);		cout << endl;
	cout << endl << endl;

	cout << "g1.DFS(0) = ";	 g1.DFS(0);		cout << endl;
	cout << "g1.DFS(1) = ";	 g1.DFS(1);		cout << endl;
	cout << "g1.DFS(2) = ";	 g1.DFS(2);		cout << endl;
	cout << "g1.DFS(3) = ";	 g1.DFS(3);		cout << endl;
	cout << endl << endl;

	Graph g2 = Graph(cardinality, m2);
	cout << "GRAPH 2: Directional Graph with Cardinality 4" << endl;
	cout << "isConnected = " << g2.isConnected() << "\t";
	cout << "exist_cycle = " << g2.exist_cycle() << endl;
	for (int i = 0; i < cardinality; i++)
	{
		cout << "indegree " << i << " = " << g2.indegree(i) << "\t";
		cout << "outdegree " << i << " = " << g2.outdegree(i) << endl;
		
		for (int j = 0; j < cardinality; j++)
			cout << i << " adjacent to " << j << " = " << g2.adj(i, j) << "\t";
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "g2.BFS(0) = ";	 g2.BFS(0);		cout << endl;
	cout << "g2.BFS(1) = ";	 g2.BFS(1);		cout << endl;
	cout << "g2.BFS(2) = ";	 g2.BFS(2);		cout << endl;
	cout << "g2.BFS(3) = ";	 g2.BFS(3);		cout << endl;
	cout << endl << endl;

	cout << "g2.DFS(0) = ";	 g2.DFS(0);		cout << endl;
	cout << "g2.DFS(1) = ";	 g2.DFS(1);		cout << endl;
	cout << "g2.DFS(2) = ";	 g2.DFS(2);		cout << endl;
	cout << "g2.DFS(3) = ";	 g2.DFS(3);		cout << endl;
	cout << endl << endl;

	Graph g3 = Graph(9, m3);
	cout << "GRAPH 3: Binary Tree with Cardinality 9" << endl;
	cout << "isConnected = " << g3.isConnected() << "\t";
	cout << "exist_cycle = " << g3.exist_cycle() << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "indegree " << i << " = " << g3.indegree(i) << "\t";
		cout << "outdegree " << i << " = " << g3.outdegree(i) << endl;

		for (int j = 0; j < 9; j++)
			cout << i << " adjacent to " << j << " = " << g3.adj(i, j) << "\t";
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "g3.BFS(0) = ";	 g3.BFS(0);		cout << endl;
	cout << "g3.BFS(1) = ";	 g3.BFS(1);		cout << endl;
	cout << "g3.BFS(2) = ";	 g3.BFS(2);		cout << endl;
	cout << "g3.BFS(3) = ";	 g3.BFS(3);		cout << endl;
	cout << "g3.BFS(4) = ";	 g3.BFS(4);		cout << endl;
	cout << "g3.BFS(5) = ";	 g3.BFS(5);		cout << endl;
	cout << "g3.BFS(6) = ";	 g3.BFS(6);		cout << endl;
	cout << "g3.BFS(7) = ";	 g3.BFS(7);		cout << endl;
	cout << "g3.BFS(8) = ";	 g3.BFS(8);		cout << endl;
	cout << endl << endl;

	cout << "g3.DFS(0) = ";	 g3.DFS(0);		cout << endl;
	cout << "g3.DFS(1) = ";	 g3.DFS(1);		cout << endl;
	cout << "g3.DFS(2) = ";	 g3.DFS(2);		cout << endl;
	cout << "g3.DFS(3) = ";	 g3.DFS(3);		cout << endl;
	cout << "g3.DFS(4) = ";	 g3.DFS(4);		cout << endl;
	cout << "g3.DFS(5) = ";	 g3.DFS(5);		cout << endl;
	cout << "g3.DFS(6) = ";	 g3.DFS(6);		cout << endl;
	cout << "g3.DFS(7) = ";	 g3.DFS(7);		cout << endl;
	cout << "g3.DFS(8) = ";	 g3.DFS(8);		cout << endl;
	cout << endl << endl;

	Graph g4 = Graph(6, m4);
	cout << "GRAPH 4: Graph with a Cycle with Cardinality 6" << endl;
	cout << "isConnected = " << g4.isConnected() << "\t";
	cout << "exist_cycle = " << g4.exist_cycle() << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "indegree " << i << " = " << g4.indegree(i) << "\t";
		cout << "outdegree " << i << " = " << g4.outdegree(i) << endl;

		for (int j = 0; j < 6; j++)
			cout << i << " adjacent to " << j << " = " << g3.adj(i, j) << "\t";
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "g4.BFS(0) = ";	 g4.BFS(0);		cout << endl;
	cout << "g4.BFS(1) = ";	 g4.BFS(1);		cout << endl;
	cout << "g4.BFS(2) = ";	 g4.BFS(2);		cout << endl;
	cout << "g4.BFS(3) = ";	 g4.BFS(3);		cout << endl;
	cout << "g4.BFS(4) = ";	 g4.BFS(4);		cout << endl;
	cout << "g4.BFS(5) = ";	 g4.BFS(5);		cout << endl;
	cout << endl << endl;

	cout << "g4.DFS(0) = ";	 g4.DFS(0);		cout << endl;
	cout << "g4.DFS(1) = ";	 g4.DFS(1);		cout << endl;
	cout << "g4.DFS(2) = ";	 g4.DFS(2);		cout << endl;
	cout << "g4.DFS(3) = ";	 g4.DFS(3);		cout << endl;
	cout << "g4.DFS(4) = ";	 g4.DFS(4);		cout << endl;
	cout << "g4.DFS(5) = ";	 g4.DFS(5);		cout << endl;
	cout << endl << endl;

	Graph g0;
	Graph g5 = g1;
	Graph g6 = g2;
	return 0;
}

