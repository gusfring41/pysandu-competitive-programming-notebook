// Find the shortest path from a source vertex to all other vertices in a graph with negative weight edges and detect negative weight cycles.
// Time Complexity: O(V * E)
// Space Complexity: O(V)
// Use cases: SSSP with negative edges, negative cycle detection, system of difference constraints, shortest path with at most K edges

void bellmanFord(vector<vector<pair<int, int>>>& adj, int src) {

    int n = adj.size() - 1;
    vector<int> dist(n+1, INF);
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto& [v, w] : adj[u]) {
                if (dist[u] != INF and dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 1; u <= n; u++) {
        for (auto& [v, w] : adj[u]) {
            if (dist[u] != INF and dist[u] + w < dist[v]) {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }
    }
}