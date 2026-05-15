// Binary Indexed Tree(BIT) 2D
// Time complexity: query and update log N * log M
// Space complexity: O(N*M)
// Use cases: dynamic 2D prefix sums, counting active points in a dynamic rectangle

struct BIT2D {

    int n, m; vector<vector<int>> bit;
    BIT2D(int n, int m) : n(n), m(m) {
        bit.assign(n+1, vector<int>(m+1, 0));
    }

    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }

    int query(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

    int queryRange(int x1, int y1, int x2, int y2) {
        return query(x2, y2) 
             - query(x1 - 1, y2) 
             - query(x2, y1 - 1) 
             + query(x1 - 1, y1 - 1);
    }

};