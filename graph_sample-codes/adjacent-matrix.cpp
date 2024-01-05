#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    // Constructor to initialize the graph with 'V' vertices
    Graph(int vertices) : V(vertices) {
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // Function to add an edge between two vertices
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
    }

    // Function to print the adjacency matrix
    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices

    // Adding edges as per the input
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // Display the adjacency matrix
    g.printAdjMatrix();

    return 0;
}
