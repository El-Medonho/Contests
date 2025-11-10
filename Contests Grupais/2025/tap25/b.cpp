#include "bits/stdc++.h"

#define endl '\n'

using namespace std;

const int MOD = 998244353;

typedef long long ll;

ll exp(ll b, ll e, ll mod = MOD){
    ll resp = 1;
    while(e){
        if(e&1) resp = (resp * b)%MOD;
        b = (b*b)%MOD;
        e>>=1;
    }
    return resp;
}

ll divv(ll x, ll y){
    ll baixo = exp(y, MOD-2);

    ll resp = (x * baixo)%MOD;
    
    return resp;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    vector<ll> fact(k+1);

    for(int i=1; i<=k; i++){
        fact[i] = (fact[i] * fact[i-1])%MOD;
    }

    for(int i=0; i<n-k; i++) cin >> v[i];

    cout << exp(v[0], k) << endl;

    ll resp = divv(exp(v[0], k), fact[k-1]);
    // for(int i=1; i<n; i++){
    //     if(v[i]<v[i-1]){
    //         ll agr = divv(exp(v[i]+1, k-1), fact[k-1]);
    //         agr = (agr * exp(k-1, v[i] - v[i-1]))%MOD;
    //         resp -= agr;
    //     }
    // }

    cout << resp << endl;
    return 0;
}