// Time Complexity: O(N) for precompute, O(1) for nCr
// Space Complexity: O(N)
// Use cases: calculating combinations, permutations, probabilities

const int MAXN, MOD;
vector<int> fact(MAXN), ifact(MAXN);

void precompute(){

    fact[0] = 1; ifact[0] = 1;
    for(int i=1; i<MAXN; i++){
        fact[i] = (i * fact[i-1]) % MOD;
    } 

    ifact[MAXN-1] = fexp(fact[MAXN-1], MOD-2, MOD);
    for(int i=MAXN-2; i >= 1; i--){
        ifact[i] = (ifact[i+1]*(i+1)) % MOD;
    }
}

int choose(int n, int r){
    if(r < 0 or r > n) return 0;
    int num = fact[n];
    int den = (ifact[r] * ifact[n - r]) % MOD;
    return (num * den) % MOD;
}



