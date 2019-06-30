#pragma once

#include <iostream>
#include <queue>

using namespace std;

class Graph
{
public:
	int n;									//cardinality
	int **adjmatrix;						//adjacency matrix
	bool *discovered;						//keeps track of nodes that have been discovered

	Graph();
	Graph(const int n, int**& m);
	Graph(const Graph& rhs);
	~Graph();
	bool adj(int i, int j);					// return true if i --> j
	int outdegree(int i);					// return the outdegree of the node i
	int indegree(int i);					// return the outdegree of the node i

	// the following funcitons are bonus (can be used to replace the final)
	void BFS(int vertex);					// print according to Breadth-first search
	void DFS(int vertex);					// print according to Depth-first search
	void DFS_Vertex(int start);				// recursive helper function to DFS


	void ResetDiscovered();                     // resets discovered node to all false
	bool isConnected();                         // return true iff the graph is connected
	int DFS_Connected(int start);               // recursive helper function to isConnected
	bool exist_cycle();                         // return true iff the graph has a cycle
	bool DFS_Cycle(int vertex, bool*& white_set, bool*& grey_set, bool*& black_set);
	// recursive helper function to exist_cycle
};

Graph::Graph()
{
	n = 0;
	adjmatrix = 0;
	discovered = 0;
}

Graph::Graph(const int n, int**& m)
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

		delete[] discovered;
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
void Graph::BFS(int vertex)
{
	//make a table of all of the discovered nodes.
	ResetDiscovered();
	discovered[vertex] = true;
	queue<int> q = queue<int>();

	int i = vertex;
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
void Graph::DFS(int vertex)
{
	//make a table of all of the discovered nodes.
	ResetDiscovered();
	DFS_Vertex(vertex);
}

void Graph::DFS_Vertex(int vertex)
{
	discovered[vertex] = true;
	for (int j = 0; j < n; j++)
	{
		if ((adjmatrix[vertex][j] != 0) && (discovered[j] == false))
		{
			DFS_Vertex(j);
		}
	}
	cout << vertex << " ";
}

void Graph::ResetDiscovered()
{
	//this resets the discovery matrix of nodes
	//useful when printing DFS or BFS
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
	int count = 0;
	//for each of the nodes, check how many nodes
	//are reached through the DFS method.
	//if one path doesn't reach all nodes, reject it
	for (int vertex = 0; vertex < n; vertex++)
	{
		ResetDiscovered();
		count = DFS_Connected(vertex);
		if (count != n) return false;
	}
	return true;
}

int Graph::DFS_Connected(int vertex)
{
	discovered[vertex] = true;
	int count = 1;
	for (int j = 0; j < n; j++)
	{
		if ((adjmatrix[vertex][j] != 0) && (discovered[j] == false))
		{
			count = count + DFS_Connected(j);
		}
	}
	return count;
}

//https://www.youtube.com/watch?v=rKQaZuoUR4M&t
bool Graph::exist_cycle()
{
	bool cycle = false;
	int vertex = 0;

	bool* white_set = new bool[n];		//not traversed yet
	bool* grey_set = new bool[n];		//currently traversing
	bool* black_set = new bool[n];		//fully traversed, children and all

	bool white_set_has_data = false;

	//initialize the sets
	for (int i = 0; i < n; i++)
	{
		white_set[i] = true;
		white_set_has_data = true;
		grey_set[i] = false;
		black_set[i] = false;
	}

	vertex = 0;
	while (white_set_has_data)
	{
		cycle = cycle || DFS_Cycle(vertex, white_set, grey_set, black_set);
		if (cycle == true)
		{
			delete[] white_set;
			delete[] grey_set;
			delete[] black_set;
			return cycle;
		}

		//calculate if the white set has data in it.
		white_set_has_data = false;
		for (int i = 0; i < n; i++)
		{
			if (white_set[i] == true)
			{
				vertex = i;
				white_set_has_data = true;
				break;
			}
		}
	}
	delete[] white_set;
	delete[] grey_set;
	delete[] black_set;

	return cycle;
}

bool Graph::DFS_Cycle(int vertex, bool*& white_set, bool*& grey_set, bool*& black_set)
{
	bool cycle = false;
	//move the vertex from white set to grey set
	white_set[vertex] = false;
	grey_set[vertex] = true;
	for (int j = 0; j < n; j++)
	{
		//if the current tested connection is the same as the vertex
		//generally ignore it
		if ((j == vertex) && (n > 1))
		{
			continue;
		}

		//if the connection leads to another vertex,
		if (adjmatrix[vertex][j] != 0)
		{
			//check if that new vertex has already been exhausted
			if (black_set[j] == true)
			{
				continue;
			}

			//check if that new vertex is already being visited
			if (grey_set[j] == true)
			{
				return true;
			}

			//visit this new vertex
			cycle = cycle || DFS_Cycle(j, white_set, grey_set, black_set);
		}
	}
	//we're done visiting this vertex, so move it from
	//grey set to black set
	grey_set[vertex] = false;
	black_set[vertex] = true;
	return cycle;
}


void graph_print(const int cardinality, int**& matrix)
{
	if (cardinality > 0)
	{
		Graph g = Graph(cardinality, matrix);

		//print adjacency matrix
		cout << "adjmatrix: " << endl;
		for (int i = 0; i < cardinality; i++)
		{
			for (int j = 0; j < cardinality; j++)
				cout << g.adjmatrix[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;

		//print strong connection and cycle presence
		cout << "nodes  = " << cardinality << "\t";
		cout << "strong = " << g.isConnected() << "\t";
		cout << "cyclic = " << g.exist_cycle() << "\t";
		cout << endl << endl;

		//print degrees and adjacency matrix all nodes
		for (int i = 0; i < cardinality; i++)
		{
			cout << "node " << i << endl;
			cout << "in_d = " << g.indegree(i) << "\t";
			cout << "out_d = " << g.outdegree(i) << endl;
			for (int j = 0; j < cardinality; j++)
			{
				if (g.adj(i, j))
				{
					cout << i << "->" << j << "\t";
				}
			}
			cout << endl << endl;
		}
		cout << endl << endl;

		//print Breadth First Search of all nodes
		for (int i = 0; i < cardinality; i++)
		{
			cout << "BFS(" << i << ") = ";	 g.BFS(i);		cout << endl;
		}
		cout << endl << endl;

		//print Depth First Search of all nodes
		for (int i = 0; i < cardinality; i++)
		{
			cout << "DFS(" << i << ") = ";	 g.DFS(i);		cout << endl;
		}
		cout << endl << endl;


	}
	else
	{
		cout << "INVALID SIZE OF GRAPH." << endl << endl;
	}
}

int main()
{
	int cardinality = 4;
	int** m = 0;


	/*
		.--.
		|  |
		0<-*
	*/
	cardinality = 1;
	m = new int*[cardinality];
	//                  0
	int zer_ssrn[1] = { 1 };
	m[0] = zer_ssrn;
	cout << "Graph 0: Single Self Referenced Node" << endl;
	graph_print(cardinality, m);

	/*
		0---->1---->2---->3---->4
	*/
	cardinality = 5;
	m = new int*[cardinality];
	//                 0  1  2  3  4
	int zer_sll[5] = { 0, 9, 0, 0, 0 };
	int one_sll[5] = { 0, 0, 8, 0, 0 };
	int two_sll[5] = { 0, 0, 0, 2, 0 };
	int thr_sll[5] = { 0, 0, 0, 0, 6 };
	int fou_sll[5] = { 0, 0, 0, 0, 0 };
	m[0] = zer_sll;	m[1] = one_sll;	m[2] = two_sll;	m[3] = thr_sll;	m[4] = fou_sll;
	cout << "Graph 1: Singly Linked List" << endl;
	graph_print(cardinality, m);


	/*
		0<--->1<--->2
	*/
	cardinality = 3;
	m = new int*[cardinality];
	//                 0  1  2
	int zer_dll[3] = { 0, 7, 0 };
	int one_dll[3] = { 5, 0, 4 };
	int two_dll[3] = { 0, 8, 0 };
	m[0] = zer_dll;	m[1] = one_dll;	m[2] = two_dll;
	cout << "Graph 2: Doubly Linked List" << endl;
	graph_print(cardinality, m);

	/*
		0---->1---->2
		|     |     |
	   \|    \|    \|
		3---->4---->5---->9
		^     ^     ^
		|     |     |
		6---->7---->8
	*/
	cardinality = 10;
	m = new int*[cardinality];
	//                   0  1  2  3  4  5  6  7  8  9
	int zer_slrs[10] = { 0, 1, 0, 7, 0, 0, 0, 0, 0, 0 };
	int one_slrs[10] = { 0, 0, 5, 0, 9, 0, 0, 0, 0, 0 };
	int two_slrs[10] = { 0, 0, 0, 0, 0, 8, 0, 0, 0, 0 };
	int thr_slrs[10] = { 0, 0, 0, 0, 7, 0, 0, 0, 0, 0 };
	int fou_slrs[10] = { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 };
	int fiv_slrs[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 };
	int six_slrs[10] = { 0, 0, 0, 6, 0, 0, 0, 1, 0, 0 };
	int sev_slrs[10] = { 0, 0, 0, 0, 2, 0, 0, 0, 1, 0 };
	int eig_slrs[10] = { 0, 0, 0, 0, 0, 6, 0, 0, 0, 0 };
	int nin_slrs[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	m[0] = zer_slrs;	m[1] = one_slrs;	m[2] = two_slrs;	m[3] = thr_slrs;	m[4] = fou_slrs;
	m[5] = fiv_slrs;	m[6] = six_slrs;	m[7] = sev_slrs;	m[8] = eig_slrs;	m[9] = nin_slrs;
	cout << "Graph 3: Singly Linked River Stream" << endl;
	graph_print(cardinality, m);

	/*
					.--.
					|  |
		1---->0<----3<-*
		^     |     |
		|    \|/    |
		*-----2<----*
	*/
	cardinality = 4;
	m = new int*[cardinality];
	//                  0  1  2  3
	int zer_dgmn[4] = { 0, 0, 7, 0 };
	int one_dgmn[4] = { 8, 0, 0, 0 };
	int two_dgmn[4] = { 0, 2, 0, 0 };
	int thr_dgmn[4] = { 4, 0, 6, 7 };
	m[0] = zer_dgmn;	m[1] = one_dgmn;	m[2] = two_dgmn;	m[3] = thr_dgmn;
	cout << "Graph 4: Directional Graph with a Marooned Node" << endl;
	graph_print(cardinality, m);

	/*
			 .------0------.
			 |             |
		 .---1---.     .---2---.
		 |       |     |       |
		 3     .-4     5     .-6
			   |             |
			   7             8
	*/
	cardinality = 9;
	m = new int*[cardinality];
	//                  0  1  2  3  4  5  6  7  8
	int zer_slbt[9] = { 0, 1, 1, 0, 0, 0, 0, 0, 0 };
	int one_slbt[9] = { 0, 0, 0, 1, 1, 0, 0, 0, 0 };
	int two_slbt[9] = { 0, 0, 0, 0, 0, 1, 1, 0, 0 };
	int thr_slbt[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int fou_slbt[9] = { 0, 0, 0, 0, 0, 0, 0, 1, 0 };
	int fiv_slbt[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int six_slbt[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	int sev_slbt[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int eig_slbt[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	m[0] = zer_slbt;	m[1] = one_slbt;	m[2] = two_slbt;	m[3] = thr_slbt;
	m[4] = fou_slbt;	m[5] = fiv_slbt;	m[6] = six_slbt;	m[7] = sev_slbt;	m[8] = eig_slbt;
	cout << "Graph 5: Singly Linked Binary Tree" << endl;
	graph_print(cardinality, m);


	/*
			 .------0------.
			 |             |
		 .---1---.     .---2---.
		 |       |     |       |
		 3     .-4     5     .-6
			   |             |
			   7             8
	*/
	cardinality = 9;
	m = new int*[cardinality];
	//                  0  1  2  3  4  5  6  7  8
	int zer_dlbt[9] = { 0, 1, 1, 0, 0, 0, 0, 0, 0 };
	int one_dlbt[9] = { 1, 0, 0, 1, 1, 0, 0, 0, 0 };
	int two_dlbt[9] = { 1, 0, 0, 0, 0, 1, 1, 0, 0 };
	int thr_dlbt[9] = { 0, 1, 0, 0, 0, 0, 0, 0, 0 };
	int fou_dlbt[9] = { 0, 1, 0, 0, 0, 0, 0, 1, 0 };
	int fiv_dlbt[9] = { 0, 0, 1, 0, 0, 0, 0, 0, 0 };
	int six_dlbt[9] = { 0, 0, 1, 0, 0, 0, 0, 0, 1 };
	int sev_dlbt[9] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
	int eig_dlbt[9] = { 0, 0, 0, 0, 0, 0, 1, 0, 0 };
	m[0] = zer_dlbt;	m[1] = one_dlbt;	m[2] = two_dlbt;	m[3] = thr_dlbt;
	m[4] = fou_dlbt;	m[5] = fiv_dlbt;	m[6] = six_dlbt;	m[7] = sev_dlbt;	m[8] = eig_dlbt;
	cout << "Graph 5: Double-Linked Binary Tree" << endl;
	graph_print(cardinality, m);


	/*
		5---------->3---->0---------->1
		^           |     |           |
		|           |     |           |
		*-----4<----*     *---->2<----*
	*/
	cardinality = 6;
	m = new int*[cardinality];
	//                  0  1  2  3  4  5
	int zer_dgti[6] = { 0, 1, 1, 0, 0, 0 };
	int one_dgti[6] = { 0, 0, 1, 0, 0, 0 };
	int two_dgti[6] = { 0, 0, 0, 0, 0, 0 };
	int thr_dgti[6] = { 1, 0, 0, 0, 1, 0 };
	int fou_dgti[6] = { 0, 0, 0, 0, 0, 1 };
	int fiv_dgti[6] = { 0, 0, 0, 1, 0, 0 };
	m[0] = zer_dgti;	m[1] = one_dgti;	m[2] = two_dgti;
	m[3] = thr_dgti;	m[4] = fou_dgti;	m[5] = fiv_dgti;
	cout << "Graph 7: Directional Graph of Two Islands" << endl;
	graph_print(cardinality, m);


	/*
		5---------->3<--->0---------->1
		^           |     |           |
		|           |     |           |
		*-----4<----*     *---->2<----*
	*/
	cardinality = 6;
	m = new int*[cardinality];
	//                  0  1  2  3  4  5
	int zer_bgti[6] = { 0, 1, 1, 1, 0, 0 };
	int one_bgti[6] = { 0, 0, 1, 0, 0, 0 };
	int two_bgti[6] = { 1, 0, 0, 0, 0, 0 };
	int thr_bgti[6] = { 1, 0, 0, 0, 1, 0 };
	int fou_bgti[6] = { 0, 0, 0, 0, 0, 1 };
	int fiv_bgti[6] = { 0, 0, 0, 1, 0, 0 };
	m[0] = zer_bgti;	m[1] = one_bgti;	m[2] = two_bgti;
	m[3] = thr_bgti;	m[4] = fou_bgti;	m[5] = fiv_bgti;
	cout << "Graph 8: Bidirectional Graph of Two Islands" << endl;
	graph_print(cardinality, m);

	/*
		pentagram with no self references
	*/
	cardinality = 5;
	m = new int*[cardinality];
	//                 0  1  2  3  4
	int zer_bgp[5] = { 0, 1, 1, 1, 1 };
	int one_bgp[5] = { 1, 0, 1, 1, 1 };
	int two_bgp[5] = { 1, 1, 0, 1, 1 };
	int thr_bgp[5] = { 1, 1, 1, 0, 1 };
	int fou_bgp[5] = { 1, 1, 1, 1, 0 };
	m[0] = zer_bgp;	m[1] = one_bgp;	m[2] = two_bgp;
	m[3] = thr_bgp;	m[4] = fou_bgp;
	cout << "Graph 9: Bidirectional Graph of a Pentagram" << endl;
	graph_print(cardinality, m);
	return 0;




}

