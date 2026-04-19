// Psum2D
// Time Complexity: Query O(1)
// Space Complexity: O(N*M)

int n, m;
vector<vector<int>> arr(n+1, vector<int>(m+1, 0));
vector<vector<int>> psum(n+1, vector<int>(m+1, 0));

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        cin >> arr[i][j];
        psum[i][j] =  arr[i][j] 
                    + psum[i][j-1] 
                    + psum[i-1][j] 
                    - psum[i-1][j-1];
    }
}


// canto superior esquerdo (x1, y1) canto inferior direito (x2, y2)
int x1, y1, x2, y2; 
int res =   psum[x2][y2] 
          - psum[x1 - 1][y2] 
          - psum[x2][y1 - 1] 
          + psum[x1 - 1][y1 - 1];
