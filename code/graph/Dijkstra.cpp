// Find shortest path from a source vertex to all other vertices in a graph with non-negative edge weights
// Time Complexity: O((V + E) log V)
// Space Complexity: O(V)
// Use cases: shortest path in non-negative weighted graphs

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {

    int n = adj.size() - 1;
    vector<int> dist(n+1, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue
    pq.push({0, src});

    while (!pq.empty()) {

        auto [d, i] = pq.top();
        pq.pop();

        if(d > dist[i]) continue;

        for (auto [u, w] : adj[i]) {

            if (dist[i] + w < dist[u]) {
                dist[u] = dist[i] + w;
                pq.push({dist[u], u});
            }
        }
    }

    return dist;
}