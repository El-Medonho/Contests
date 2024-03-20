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

    vector<ll> qtt(n, 0);

    int r; cin >> r;

    int sum = 0;
        for(int i = n-1; i > -1; i--){
            if(! (r & (1LL<<i)) ) continue;
            for(int j = 0; j <= i; j++){
                qtt[j+sum] = (qtt[j+sum] + pascal[i][j]) % mod;
            }
            sum++;
        }
        qtt[sum]++;

    for(ll i: qtt) cout << i << ' ';
    cout << endl;

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