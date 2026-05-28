template <typename T>

struct SegLazy{
    int n;
    vector<T> tree, lazy;
    const T NEUTRO = 0, LAZY_NEUTRO = 0;

    T merge(T a, T b) {return a + b;}

    SegLazy(int n){
        this->n = n;
        tree.assign(4*n, NEUTRO);
        lazy.assign(4*n, NEUTRO);
    }

    void push(int node, int l, int r){
        if(lazy[node] == LAZY_NEUTRO) return;
        tree[node] += lazy[node] * (r - l + 1);
        if(l != r){
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = LAZY_NEUTRO;
    }

    void build(int node, int l, int r, vector<T> &v){
        if(l == r){
            tree[node] = v[l]; return; 
        }
        int mid = (l+r)/2;
        build(2*node, l, mid, v);
        build(2*node + 1, mid+1, r, v);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    void update(int node, int l, int r, int ql, int qr, T val){
        push(node, l, r);
        if(ql > r or qr < l) return;
        if(ql <= l and r <= qr){
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l+r)/2;
        update(2*node, l, mid, ql, qr, val);
        update(2*node + 1, mid+1, r, ql, qr, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    T query(int node, int l, int r, int ql, int qr){
        push(node, l, r);
        if(ql > r or qr < l) return NEUTRO;
        if(ql <= l and r <= qr) return tree[node];
        int mid = (l+r)/2;
        return merge(query(2*node, l, mid, ql, qr), query(2*node + 1, mid + 1, r, ql, qr));
    }

    void build(const vector<T>& v) { build(1, 0, n - 1, v); }
    void update(int ql, int qr, T val) { update(1, 0, n - 1, ql, qr, val); }
    T query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
    

};