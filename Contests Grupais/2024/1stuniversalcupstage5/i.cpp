#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mod = 998244353;

ll expo(ll b, ll e){
    ll resp = 1;
    while(e){
        if(e&1) resp = resp*b%mod;
        b = b*b%mod;
        e>>=1;
    }
    return resp;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll ans = 1;

    ll n; cin >> n;

    if(n >= 10){
        cout << expo(2, n) << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }

    cout << ans << endl;


    return 0;
}