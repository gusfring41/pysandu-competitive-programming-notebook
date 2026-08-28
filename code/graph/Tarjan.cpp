// Finds Strongly Connected Components (SCCs) in a directed graph.
// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Use cases: 2-SAT, shrinking cycles in directed graphs to form a DAG, finding reachability components.
// Note: SCC IDs are assigned in reverse topological order of the condensed DAG.

vector<int> tarjanSCC(const vector<vector<int>>& adj) {
    int n = adj.size() - 1; 
    
    vector<int> tin(n + 1, -1), low(n + 1, -1), scc_id(n + 1, -1);
    vector<bool> in_stack(n + 1, false);
    stack<int> st;
    int timer = 0, scc_cnt = 0;

    
    auto dfs = [&](auto& self, int u) -> void {
        tin[u] = low[u] = ++timer;
        st.push(u);
        in_stack[u] = true;

        for (int v : adj[u]) {
            if (tin[v] == -1) { 
                self(self, v);
                low[u] = min(low[u], low[v]);
            } else if (in_stack[v]) { 
                low[u] = min(low[u], tin[v]);
            }
        }

        if (low[u] == tin[u]) {
            while (true) {
                int v = st.top();
                st.pop();
                in_stack[v] = false;
                scc_id[v] = scc_cnt; 
                if (u == v) break;
            }
            scc_cnt++; 
        }
    };

    for (int i = 1; i <= n; i++) {
        if (tin[i] == -1) {
            dfs(dfs, i);
        }
    }

    // retorna o vetor contendo a qual SCC cada vertice pertence. 
    // o total de SCCs gerados é sempre: *max_element(scc_id.begin(), scc_id.end()) + 1
    return scc_id;
}