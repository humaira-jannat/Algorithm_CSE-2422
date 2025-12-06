#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int startNode, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    cout << "BFS Traversal starting from node " << startNode << ": ";
     while (!q.empty()) {
        int current = q.front();
        q.pop();
      cout << current << " ";   
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);}}}
       cout << endl;}
int main() {
    int nodes, edges;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(nodes);

    cout << "Enter edges (u v format):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cout << "Enter starting node for BFS: ";
    cin >> startNode;

    bfs(startNode, graph);

    return 0;
}
