// Returns a list of points on the convex hull
// in counter-clockwise order
vector<Point> convex_hull(vector<Point> A)
{
    int n = A.size(), k = 0;

    if (n <= 3)
        return A;

    vector<Point> ans(2 * n);

    // Sort points lexicographically
    sort(A.begin(), A.end());

    // Build lower hull
    for (int i = 0; i < n; ++i) {

        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        while (
            k >= 2
            && cross_product(ans[k - 2], ans[k - 1], A[i])
                   <= 0)
            k--;
        ans[k++] = A[i];
    }

    // Build upper hull
    for (size_t i = n - 1, t = k + 1; i > 0; --i) {

        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        while (k >= t
               && cross_product(ans[k - 2], ans[k - 1],
                                A[i - 1])
                      <= 0)
            k--;
        ans[k++] = A[i - 1];
    }

    // Resize the array to desired size
    ans.resize(k - 1);

    return ans;
}