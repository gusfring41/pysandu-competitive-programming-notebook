// Counting DP (Sum of all ways / Unbounded Knapsack)
// Time Complexity: O(N * Target)
// Space Complexity: O(Target)
// Use case: Count number of ways to form a sum

int count_ways(vector<int>& items, int target) {

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int item : items) {
        for (int i = item; i <= target; i++) {
            dp[i] = (dp[i] + dp[i - item]) % MOD;
        }
    }

    return dp[target];
}