
// Pre-processing: O(N log N) | Query: O(log N)

int timer, k;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> tin, tout;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i=1; i <= k; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u: adj[v]){
        if(u != p) dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i=k; i >= 0; i--){
        if(!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void pre_process(int n, int root){
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    k = __lg(n+1);
    up.assign(n+1, vector<int>(k+1));
    dfs(root, root);
}