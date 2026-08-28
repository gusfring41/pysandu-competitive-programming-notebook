// Matrix Multiplication & Exponentiation Template
// Time Complexity: O(N^3) for multiplication, O(N^3 * log P) for exponentiation
// Space Complexity: O(N^2)
// Use cases: Nth Fibonacci, paths of length K in a graph, linear recurrences

struct Matrix {
    int r, c;
    vector<vector<long long>> mat;

    Matrix(int r, int c) : r(r), c(c) {
        mat.assign(r, vector<long long>(c, 0));
    }

    Matrix operator*(const Matrix &other) const {
        
        assert(c == other.r); 
        
        Matrix res(r, other.c);
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k++) {
                if (mat[i][k] == 0) continue; 
                for (int j = 0; j < other.c; j++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix power(Matrix base, long long exp) {
    assert(base.r == base.c); 
    int n = base.r;
    Matrix res(n, n);
    
    for (int i = 0; i < n; i++) {
        res.mat[i][i] = 1;
    }

    while (exp > 0) {
        if (exp % 2 == 1) res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}