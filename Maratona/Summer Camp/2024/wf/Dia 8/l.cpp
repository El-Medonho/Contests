#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mod = 1e9+7;

signed solve(){

    
    int n = 32;

    int q; cin >> q;

    vector<vector<ll>> pascal(32, vector<ll>(32, 0));

    pascal[0][0] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < i; j++){
            pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
            pascal[i][j] %= mod;
        }
        pascal[i][0] = 1;
        pascal[i][i] = 1;
    }


    vector<ll> vals(n, 0);

    while(q--){
        int op; cin >> op;

        if(op == 0){
            ll l,r,x; cin >> l >> r >> x; l--; r--;

            if(r <= l) continue;

            vector<ll> qtt(n+1, 0), mqtt(n+1, 0);


            int sum = 0;


            if(l >= 0){
                for(int i = n-1; i > -1; i--){
                    if(! (l & (1LL<<i)) ) continue;
                    for(int j = 0; j <= i; j++){
                        mqtt[j+sum] = ((mqtt[j+sum] + pascal[i][j]))% mod;
                    }
                    sum++;
                }
                mqtt[sum] = (mqtt[sum]+1 % mod);            
            }

            sum = 0;
            for(int i = n-1; i > -1; i--){
                if(! (r & (1LL<<i)) ) continue;
                for(int j = 0; j <= i; j++){
                    qtt[j+sum] = (qtt[j+sum] + pascal[i][j]) % mod;
                }
                sum++;
            }
            qtt[sum] = (qtt[sum]+1)%mod;
        
            for(int i = 0; i < n; i++){
                qtt[i] = ((qtt[i] - mqtt[i]) % mod + mod) % mod;
                vals[i] = (vals[i] + (qtt[i] * x % mod)) % mod;
                // cout << vals[i] << ' ';
            }
            // cout << endl;
        }

        else{
            ll ans = 0;

            int l,r; cin >> l >> r; r--; 
            if(r < l) {
                cout << 0 << endl;
                continue;
            }
            l = 30-l; r = 30-r;

            for(int i = r; i <= l; i++){
                ans = (ans + vals[i]) % mod;
            }

            cout << ans << endl;
        }
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);


    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }


    return 0;
}