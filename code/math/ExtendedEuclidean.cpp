// Extended Euclidean Algorithm
// Returns (gcd(a, b), x, y) such that a*x + b*y = gcd(a, b)

int euclides(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int g = euclides(b, a%b, x1, y1);
    x = y1; y = x1 - y1*(a/b);
    return g;
}

int inverso_mod(int a, int m){
    int x, y;
    int g = euclides(a, m, x, y);
    if(g != 1) return -1;
    return (x%m + m) % m;
}