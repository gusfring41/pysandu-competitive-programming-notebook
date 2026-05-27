template <typename T>

struct SegTree{
    int n;
    vector<T> tree;
    const T NEUTRO = 1e18;

    T merge(T a, T b) {return min(a, b);}
    SegTree(int n){
        this->n = n;
        tree.assign(2*n, NEUTRO);
    }

    void build(vector<T>& v){
        for(int i=0; i<n; i++) tree[n+i] = v[i];
        for(int i=n-1; i>0; i--) tree[i] = merge(tree[2*i], tree[2*i + 1]);
    }

    void update(int pos, T val){
        pos += n;
        tree[pos] = val;
        for(pos /= 2; pos > 0; pos /= 2) tree[pos] = merge(tree[pos*2], tree[pos*2 + 1]);
    }

    T query(int l, int r){
        T res_l = NEUTRO, res_r = NEUTRO;
        for(l += n, r += n; l <= r; l /= 2, r /= 2){
            if(l%2 != 0) res_l = merge(res_l, tree[l++]);
            if(r%2 == 0) res_r = merge(tree[r--], res_r);
        }
        return merge(res_l, res_r);
    }

};