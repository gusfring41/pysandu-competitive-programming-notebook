// Sparse Table
// Time Complexity: O(n * log n) build, O(1) querie
// Space complexity: O(n * log n)
// Idempotent operation f(a, a) = a

struct SparseTable{

    int n, p;
    vector<vector<int>> st;

    SparseTable(vector<int> &arr){
        n = (int) arr.size();
        p = __lg(n);
        st.assign(p+1, vector<int>(n, 0));

        for(int j=0; j<n; j++) st[0][j] = arr[j];
        for(int i = 1; i <= p; i++){
            int k = (1ll << (i-1));
            int lim = n - 2*k + 1;
            for(int j=0; j<lim; j++){
                st[i][j] = op(st[i-1][j], st[i-1][j+k]);
            }
        }
    }

    int queries(int l, int r){
        int len = r  - l + 1;
        int p_local = __lg(len), k = (1ll << p_local);
        return op(st[p_local][l], st[p_local][r - k + 1]);
    }

};