// Disjoint Set Union(DSU)
// Time Complexity: aprox. O(1)
// Space Complexity: O(n)

struct DSU{

    vector<int> parent, size;

    DSU(int n){
        parent.assign(n+1, 0);
        size.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool same(int a, int b){
        return find(a) == find(b);
    }

    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }

};