#include <iostream>
#include <vector>
#include <stack>

class Graph {
public:
    int V; // Number of vertices
    std::vector<std::vector<int>> adj; // Adjacency list

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Depth-First Search (DFS) function
    void DFS(int startVertex) {
        std::vector<bool> visited(V, false); // Initialize all vertices as not visited
        std::stack<int> stack;

        visited[startVertex] = true;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            std::cout << char('A' + currentVertex) << " ";

            for (const auto& neighbor : adj[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V = 5; // Number of vertices

    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4); // Additional edge
    g.addEdge(3, 4); // Additional edge

    std::cout << "DFS starting from vertex A: ";
    g.DFS(0);

    return 0;
}
