// This code is adapted from 
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/


#include <iostream>
#include <list> 
#include <queue>
#include <climits>

using namespace std;
// #define INT_MAX 0x3f3f3f3f


// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using adjacency list representation
class Graph {
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex and weight pair for every
	// edge
	list<pair<int, int> >* adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// prints shortest path from s
	int shortestPath(int s, int B);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	// adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
int Graph::shortestPath(int src, int B)
{
	// Create a priority queue to store vertices that are being preprocessed.
	priority_queue<iPair, vector<iPair>, greater<iPair> >
		pq;

	// Create a vector for distances and initialize all distances as (INT_MAX)
	vector<int> dist(V, INT_MAX);

	// Insert source itself in priority queue and initialize its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all distances are not
	finalized) */
	while (!pq.empty()) {
		// The first vertex in pair is the minimum distance vertex, extract it
		// from priority queue. vertex label is stored in second of pair (it has
		// to be done this way to keep the vertices sorted distance (distance
		// must be first item in pair)
		int u = pq.top().second;
		pq.pop();

		// 'i' is used to get all adjacent vertices of a vertex
		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			// Get vertex label and weight of current adjacent of u.
			int v = (*i).first;
			int weight = (*i).second;

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight) {
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	int count = 0;
	for (int i = 0; i < V; ++i){
        if(dist[i] <= B){
            count++;
        }
    }

    return count;
}

int main(){
    int n, E, B, m;
    cin >> n >> E >> B >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // here might need to consider parallel edges and self loops
        g.addEdge(u-1, v-1, w);
    }

    cout << g.shortestPath(E-1, B) << endl;

    return 0;
}

/*

Input
The first line contains 4 integer n, E, B, m. n is the number of nodes, E is the node number for the destination node,
B is the limit, and m is the number of edges. 1 <= n <= 100, 1 <= E <= n, 1 <= B <= 10ˆ9, 0 <= m <= n*n
In each of the following m lines, there are 3 integers u,v,w, which means there is an edge from u to v with weight w.
1<=u,v<=n, 0 < w < 10ˆ9
There may be parallel edges or self loops in the input graph.
Output A integer, the number of nodes that have desired paths to E.
Example 1
Input:
100 1 123 0
Output:
1
There is no edge in the graph, the only node that has a path to E is E itself.
Example 2
Input:
5 1 1 4
2 1 1
3 1 1
4 5 1
5 3 1
Output:
3

Example 3
Input:
5 1 2 7
2 1 1
3 1 1
4 5 1
5 3 1
5 3 2
5 3 3 
1 4 2
Output:
4


*/