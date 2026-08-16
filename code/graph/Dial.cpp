// Dial, optimized dijkstra for low W
// Time-complexity: O(E + V*W), W : max weight

vector<int> dial(int n, int w, int src, vector<vector<pii>> &adj){
     
    vector<int> dist(n+1, INF); 
    vector<queue<int>> a(w+1); 
    dist[src] = 0; a[0].push(src); 
    int pos = 0, qnt = 1; 
    
    while(qnt){
        while(a[pos%(w+1)].empty()) pos++;

        int i = a[pos%(w+1)].front(); a[pos%(w+1)].pop(); qnt--;

        if(dist[i] < pos) continue;

        for(auto [u, d_u]: adj[i]){
            if(dist[i] + d_u < dist[u]){
                dist[u] = dist[i] + d_u;
                a[(dist[u])%(w+1)].push(u); qnt++;
            }
        }
    }

    return dist;
}

// especial case: max W = 1
vector<int> bfs01(int n, int src, vector<vector<pii>> &adj){
    
    vector<int> dist(n+1, INF);
    deque<int> dq;
    
    dist[src] = 0;
    dq.push_front(src);
    
    while(!dq.empty()){
        int i = dq.front();
        dq.pop_front();
        
        for(auto [u, w] : adj[i]){
            if(dist[i] + w < dist[u]){
                dist[u] = dist[i] + w;                
                if(w == 0) dq.push_front(u); 
                else dq.push_back(u); 
            }
        }
    }
    
    return dist;
}