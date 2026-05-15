// Find the length of the longest increasing subsequence in a given array
// Time complexity: O(n log n) where n is the length of the input array

int lis(vector<int>& arr) {
    vector<int> dp;
    for (int x : arr) {
        auto it = lower_bound(all(dp), x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}