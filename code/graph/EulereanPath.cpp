// Find the Eulerian path in a graph using Hierholzer's algorithm
// Time complexity: O(E) where E is the number of edges in the graph
// Use cases: visit every edge once, DNA sequencing, puzzles, drawing figures

vector<int> findEulerianPath(vector<vector<int>>& adj, int start) {

    vector<int> path;
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int i = s.top();
        if (adj[i].empty()) {
            path.push_back(i);
            s.pop();
        } else {
            int u = adj[i].back(); adj[i].pop_back(); 
            s.push(u);
        }
    }

    reverse(path.begin(), path.end());
    return path;
}