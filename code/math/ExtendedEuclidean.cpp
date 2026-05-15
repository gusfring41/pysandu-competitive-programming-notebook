// Extended Euclidean Algorithm
// Returns (gcd(a, b), x, y) such that a*x + b*y = gcd(a, b)

int extendedEuclidean(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, x1, y1);
    x = y1;
    y = x1 - (b / a) * y1;
    return gcd;
}