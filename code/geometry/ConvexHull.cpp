
// pontos colineares na borda, mude <= EPS para < -EPS.
vector<Point> convex_hull(vector<Point>& pts) {
    int n = pts.size(), k = 0;
    if (n <= 2) return pts;
    
    vector<Point> h(2 * n);
    sort(pts.begin(), pts.end()); 
    
    // lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross_product(h[k-2], h[k-1], pts[i]) <= EPS) k--;
        h[k++] = pts[i];
    }
    
    // upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross_product(h[k-2], h[k-1], pts[i]) <= EPS) k--;
        h[k++] = pts[i];
    }
    
    h.resize(k - 1); // remove o ponto duplicado no final
    return h;
}