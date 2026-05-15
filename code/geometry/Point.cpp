
const double EPS = 1e-9;
// EPS = 0 -> int

struct Point {
    double x, y;
    
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double c) const { return Point(x * c, y * c); }
    Point operator/(double c) const { return Point(x / c, y / c); }

    bool operator<(const Point& p) const {
        if (abs(x - p.x) > EPS) return x < p.x;
        return y < p.y - EPS;
    }

    bool operator==(const Point& p) const {
        return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
    }
};

// > 0: B esq. vetor OA, < 0: B dir. vetor OA, 0: Colineares
double cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// distancia euclidiana
double dist(Point A, Point B) {
    return hypot(A.x - B.x, A.y - B.y); 
}

// distancia quadrada
double dist2(Point A, Point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

// produto escalar, dot == 0 perpendiculares
double dot_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.x - O.x) + (A.y - O.y) * (B.y - O.y);
}

int get_half(Point O, Point P) {
    if (P.y - O.y > EPS or (abs(P.y - O.y) <= EPS and P.x - O.x > EPS)) return 1;
    return 0;
}

// ordenacao por perimetro
void sort_by_angle(vector<Point>& p, Point center) {
    sort(p.begin(), p.end(), [&](const Point& A, const Point& B) {
        int halfA = get_half(center, A);
        int halfB = get_half(center, B);
        
        if (halfA != halfB) {
            return halfA > halfB;
        }
        
        double cross = cross_product(center, A, B); 
        if (abs(cross) > EPS) {
            return cross > 0;
        }
        
        return dist2(center, A) < dist2(center, B) - EPS;
    });
}

// shoelace formula, vértices do polígono ordenados pelo perímetro.
double polygon_area(const vector<Point>& p) {
    double area = 0.0;
    int n = p.size();
    
    for (int i = 0; i < n; i++) {
        int next_i = (i + 1) % n;
        area += (p[i].x * p[next_i].y) - (p[next_i].x * p[i].y);
    }
    
    // return abs(area) -> int
    return abs(area) / 2.0;
}

// aux func
int orientation(Point O, Point A, Point B) {
    double val = cross_product(O, A, B);
    if (abs(val) <= EPS) return 0; // Colinear
    return (val > 0) ? 1 : -1;     // 1: Esquerda, -1: Direita
}

// 2. P in seg AB?
bool on_segment(Point P, Point A, Point B) {
    return P.x >= min(A.x, B.x) - EPS && P.x <= max(A.x, B.x) + EPS &&
           P.y >= min(A.y, B.y) - EPS && P.y <= max(A.y, B.y) + EPS;
}

// Ab seg cross CD?
bool segments_intersect(Point A, Point B, Point C, Point D) {
    // Calcula as 4 orientações necessárias
    int o1 = orientation(A, B, C);
    int o2 = orientation(A, B, D);
    int o3 = orientation(C, D, A);
    int o4 = orientation(C, D, B);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && on_segment(C, A, B)) return true; // C toca AB
    if (o2 == 0 && on_segment(D, A, B)) return true; // D toca AB
    if (o3 == 0 && on_segment(A, C, D)) return true; // A toca CD
    if (o4 == 0 && on_segment(B, C, D)) return true; // B toca CD

    return false; // Não se cruzam
}