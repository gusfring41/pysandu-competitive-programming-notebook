// Depth First Search (DFS)
// Time Complexity: O(V + E)
// Space Complexity: O(V)

// Recursive DFS
void dfs(const Graph& graph, int vertex, vector<bool>& visited) {
    visited[vertex] = true;

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

// Iterative DFS
void dfsIterative(const Graph& graph, int start) {
    int V = graph.size();
    vector<bool> visited(V, false);
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (!visited[vertex]) {
            visited[vertex] = true;

            for (int neighbor : graph[vertex]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }