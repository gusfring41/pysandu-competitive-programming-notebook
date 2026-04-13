// Find all prime numbers up to a given limit using the Sieve of Eratosthenes algorithm
// Time complexity: O(n log log n) where n is the limit
// This idea can also be used to construct a table for the smallest prime factors, O(log N) per query

vector<int> findPrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> buildSPF(int limit){
    vector<int> spf(limit+1);
    iota(spf.begin(), spf.end(), 0);
    for(int i = 2; i * i <= limit; i++) {
        if(spf[i] == i){
            for(int j = i * i; j <= limit; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

    return spf;
}

vector<int> getFactors(vector<int>& spf, int x){
    vector<int> factors;
    while(x > 1){
        factors.push_back(spf[x]);
        x /= spf[x];
    }

    return factors;
}