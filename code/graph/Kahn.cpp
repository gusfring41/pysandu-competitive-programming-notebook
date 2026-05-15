// Topological Sort (Kahn's Algorithm)
// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Use cases: Dependency resolution, cycle detection in directed graphs, DP on DAGs

vector<int> TopologicalSort(vector<vector<int>>& adj, int n){
    vector<int> degree(n+1, 0);
    for(int i=1; i<=n; i++){
        for(auto u: adj[i]) degree[u]++;
    }

    // priority_queue in case of lexicographically smallest answer
    queue<int> q; vector<int> ans;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i); ans.push_back(i);
        }
    }

    
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(auto u: adj[i]){
            degree[u]--;
            if(degree[u] == 0){
                q.push(u); ans.push_back(u);
            }
        }
    }

    if((int)ans.size() != n) return {};
    return ans;

}