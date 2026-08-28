// Time complexity: query and update log N
// 1-based indexing, [l, r]

struct BIT{

    int n; vector<int> bit;
    BIT(int n){
        this->n = n;
        bit.assign(n+1, 0);
    }

    void update(int i, int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    int queryRange(int l, int r){
        return query(r) - query(l-1);
    }

    // retorna o indice do k-esimo elemento da bit
    int find_kth(int k){

        int idx = 0;
        int max_bit = __lg(n);

        for(int i = max_bit; i>= 0; i--){
            int next_idx = idx + (1ll << i);
            if(next_idx <= n and bit[next_idx] < k){
                idx = next_idx;
                k -= bit[next_idx];
            }
        }

        return idx+1;
    }

};