#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void printAdjacencyList() {
        for (int i = 0; i < V; ++i) {
            cout << "Adjacency list of vertex " << i << ":\n";
            cout << "Head";
            for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
                cout << " -> " << *it;
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.printAdjacencyList();

    return 0;
}
