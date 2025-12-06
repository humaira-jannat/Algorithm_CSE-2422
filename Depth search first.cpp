#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int nodes;
    vector<vector<int>> adj;
    vector<bool> visited;

    // Recursive DFS function
    void dfsUtil(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next]) {
                dfsUtil(next);
            }
        }
    }

public:
    Graph(int n) : nodes(n) {
        adj.resize(n);
        visited.assign(n, false);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // remove this if graph is directed
    }

    // Start DFS from a given source
    void dfs(int start) {
        cout << "DFS Traversal: ";
        dfsUtil(start);
        cout << endl;
    }
};

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Graph g(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    g.dfs(start);

    return 0;
}
