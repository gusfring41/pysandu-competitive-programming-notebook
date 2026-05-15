// Find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)
// Use cases: reachability, minimax distance, global negative cycle detection(dist[i][i] < 0)

void floydWarshall(vector<vector<int>>& dist) { // dist(INF)

    int n = dist.size() - 1;
    for(int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF and dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

