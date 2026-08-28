// 0-based indexing, [l, r)
// SegTree<int> seg;

template <typename T> 
struct SegTree{
    
    int size; 
    vector<T> tree;
    const T NEUTRO = 0; // adapt

    T merge(T a, T b){
        return a + b; // adapt
    }

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size, NEUTRO);
    }

    void build(vector<T> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        tree[x] = merge(tree[2*x+1], tree[2*x + 2]);
    }

    void build(vector<T> &a){
        init((int)a.size());
        build(a, 0, 0, size);
    }

    void set(int i, T v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = v;
            return;
        }
        int m = (lx + rx)/2;
        if(i < m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x + 2, m, rx);
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }

    void set(int i, T v){
        set(i, v, 0 , 0, size);
    }

    T query(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l) return NEUTRO;
        if(lx >= l and rx <= r) return tree[x];
        int m = (lx + rx)/2;
        return merge(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
    }

    T query(int l, int r){
        return query(l, r, 0, 0, size);
    }

};