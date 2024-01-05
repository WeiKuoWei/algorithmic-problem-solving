// sample code from:
// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edge;
};

Graph* createGraph(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge.resize(E);
    return graph;
}

void BellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; ++i) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "possible" << endl;
            return;
        }
    }

    cout << "not possible" << endl;
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph* graph = createGraph(V, E);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph->edge[i].src = u;
        graph->edge[i].dest = v;
        graph->edge[i].weight = w;
    }

    BellmanFord(graph, 0);

    return 0;
}

/*

Input
The first line of the input contains two integers N (1 <= N <= 1000) and M (0 <= M <= 2000), indicating the
number of cities and the number of highways. Each of the following M lines contains three integers u, v and w,
indicating there is a highway by which you can travel from city u to city v and you can earn w dollars. (0 <= u,v <
N, u != v, -1000 <= w <= 1000)
Output
Print one line containing possible or not possible to indicate if there exists a deficit cycle. (There is a new line
character after the output string.)
Example 1
Input:
3 3
0 1 1000
1 2 15
2 1 -42
Output:
possible
Example 2
Input:
4 4
0 1 10
1 2 20
2 3 30
3 0 -60
Output:
not possible

*/