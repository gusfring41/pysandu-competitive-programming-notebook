
// Time complexity: O(n log log n) 
vector<int> spf(limit+1, 0);
void findPrimes(){
    iota(all(spf), 0);
    for(int i = 2; i*i <= limit; i++){
        if(spf[i] == i){
            for(int j=i*i; j <= limit; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    // prime: spf[i] == i
}

// Time complexity: O(log n) 
vector<int> getFactors(int x){
    vector<int> factors;
    while(x > 1){
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

// Time complexity: O(n log n) 
vi tot_div(limit+1, 0);
void count_mult(){
    for(int i=1; i <= limit; i++){
        for(int j=i; j <= limit; j += i){
            tot_div[j]++;
        }
    }
}
