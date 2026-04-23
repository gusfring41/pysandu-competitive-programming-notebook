// Find maximum flow in graph
// Time complexity: O(|V| * Eˆ2)
// Space complexity: O(V)

bool bfs(int residual[V][V], int start, int target, vi parent){
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0 ; v <= V ; v++){
            if(!visited[v] and residual[u][v] > 0){
                if(v == target){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int g[V][V], int start, int target){
    int u, v;
    int residual[V][V];

    for(u = 0 ; u < V ; u++)
        for(v = 0 ; v < V ; v++)
            residual[u][v] = g[u][v];

    vi parent(V);
    int maxFlow = 0;

    while(bfs(residual, start, target, parent)){
        int pathFlow = INT_MAX;
        for(v = target ; v != start ; v = parent[v]){
            u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for(v = target ; v != start ; v = parent[v]){
            u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}