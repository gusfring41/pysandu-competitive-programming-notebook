// retorna: 1 (Dentro), -1 (Na borda), 0 (Fora)
// o poligono nao precisa ser convexo, mas os vertices devem estar em ordem.
int point_in_polygon(Point P, const vector<Point>& poly) {
    int n = poly.size();
    bool in = false;
    
    for (int i = 0; i < n; i++) {
        Point A = poly[i];
        Point B = poly[(i + 1) % n];
        if (on_segment(P, A, B)) return -1;
        if (A.y > B.y) swap(A, B); 
        if (A.y <= P.y + EPS && P.y + EPS < B.y) {
            if (cross_product(A, B, P) > EPS) {
                in = !in;
            }
        }
    }
    
    return in ? 1 : 0;
}