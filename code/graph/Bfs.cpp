// Breadth First Search (BFS)
// Time Complexity: O(V + E)
// Space Complexity: O(V)

void bfs(const Graph& graph, int start) {
    
    int V = graph.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}