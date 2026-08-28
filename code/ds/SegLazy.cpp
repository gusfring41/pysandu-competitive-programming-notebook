// 0-based indexing, [l, r)
// SegLazy<int> seg

template <typename T>
struct SegLazy {
    int size; 
    vector<T> tree, lazy;
    const T NEUTRO = 0, LAZY_NEUTRO = 0;

    T merge(T a, T b) { return a + b; }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, NEUTRO);
        lazy.assign(2 * size, LAZY_NEUTRO);
    }

    void push(int x, int lx, int rx) {
        if (lazy[x] == LAZY_NEUTRO) return;
        
        tree[x] += lazy[x] * (rx - lx); 
    
        if (rx - lx > 1) {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = LAZY_NEUTRO;
    }

    void build(vector<T> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<T> &a) {
        init((int)a.size());
        build(a, 0, 0, size);
    }

    void update(int l, int r, T val, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r or rx <= l) return; 
        if (lx >= l and rx <= r) {      
            lazy[x] += val;
            push(x, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        update(l, r, val, 2 * x + 1, lx, m);
        update(l, r, val, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int l, int r, T val) { 
        update(l, r, val, 0, 0, size); 
    }

    T query(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r or rx <= l) return NEUTRO; 
        if (lx >= l and rx <= r) return tree[x]; 
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    T query(int l, int r) { 
        return query(l, r, 0, 0, size); 
    }
};