// inclusion exclusion principle using bitmaks
int count_union(vi &tot, vi &conj){
    int m = (int)conj.size(), ans = 0;
    int mx = (1ll << m) - 1;
    for(int i=mx; i > 0; i--){
        int cnt = __builtin_popcount(i), prod = 1;
        for(int j=0; j<m; j++){
            if(1 & (i >> j)) prod *= conj[j];
        }  

        if(prod >= (int)tot.size()) continue;
        if(cnt%2 == 0) ans -= tot[prod];
        else ans += tot[prod]; 
    }
    return ans;
}