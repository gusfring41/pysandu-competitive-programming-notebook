// Find the Eulerian path in a graph using Hierholzer's algorithm
// Time complexity: O(E) where E is the number of edges in the graph
// Use cases: visit every edge once, DNA sequencing, puzzles, drawing figures

vector<int> findEulerianPath(vector<vector<int>>& adj, int start) {

    vector<int> path;
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        if (adj[v].empty()) {
            path.push_back(v);
            s.pop();
        } else {
            int u = adj[v].back();
            adj[v].pop_back(); // Remove the edge from v to u
            s.push(u);
        }
    }

    reverse(path.begin(), path.end());
    return path;
}