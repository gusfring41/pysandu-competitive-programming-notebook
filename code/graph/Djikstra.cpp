// Find shortest path from a source vertex to all other vertices in a graph with non-negative edge weights
// Time Complexity: O((V + E) log V)
// Space Complexity: O(V)
// Use cases: shortest path in non-negative weighted graphs

void dijkstra(vector<vector<pair<int, int>>>& adj, int src) {

    int n = adj.size() - 1;
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue
    pq.push({0, src});

    while (!pq.empty()) {

        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for (auto p : adj[u]) {

            int v = p.first;
            int weight = p.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}