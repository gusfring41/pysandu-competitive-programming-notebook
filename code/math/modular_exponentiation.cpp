// Calculates (x^n) % MOD
// Time Complexity: O(log n)
// Space Complexity: O(1)

int fexp(int x, int b, int MOD){
    int res = 1;

    while(b > 0){
        if(b & 1) res = (res * x) % MOD;    
        x = (x * x) % MOD;
        b >>= 1;
    }
    return res;
}

