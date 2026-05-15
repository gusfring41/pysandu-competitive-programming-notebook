// General take/not take dp problem
// Time Complexity: aprox. O(n * m)
// Space Complexity: O(n * m) / O(m)
// Use cases: maximize/minimize sum

// Top-down
int knapsack_top_down(vector<int>& v, vector<int>& w, int x){
    int n = (int)v.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    auto rec = [&](auto self, int i, int m) -> int {
        if(i >= n || m == 0) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        int take = 0, not_take = self(self, i+1, m);
        if(m >= w[i]){
            take = v[i] + self(self, i+1, m - w[i]);
        }
        return dp[i][m] = max(take, not_take);
    };  

    return rec(rec, 0 , x);
}

// Bottom-up
int knapsack_bottom_up(vector<int>& v, vector<int>& w, int x){
    int n = (int)v.size();
    vector<int> dp(x+1, 0);

    for(int i=0; i < n; i++){
        for(int m=x; m >= w[i]; m--){
            dp[m] = max(dp[m], v[i] + dp[m - w[i]]);
        }
    }

    return dp[x];
}