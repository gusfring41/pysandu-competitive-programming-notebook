// Kruskal algorithm for finding the Minimum Spanning Tree
// Time Complexity: O(E log E)
// Space complexity: O(V + E) 
// Use ds/dsu.cpp template

// edges: {weight, u, v}
vector<vector<int>> kruskalMST(vector<array<int, 3>>& edges, int n){
    int m = (int)edges.size();
    sort(edges.begin(), edges.end()); 
    vector<vector<int>> mst(n+1);
    DSU dsu(n+1);
    for(int i=0; i<m; i++){
        int a = edges[i][1], b = edges[i][2];
        if(dsu.merge(a, b)){
            mst[a].push_back(b);
            mst[b].push_back(a);
        }
    }
    return mst;
}