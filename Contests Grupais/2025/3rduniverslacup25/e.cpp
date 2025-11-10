#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const ll mod = 998244353;

ll expo(ll b, ll e){
    ll resp = 1;
    while(e){
        if(e&1) resp = resp*b%mod;
        b = b*b%mod;
        e>>=1;
    }

    return resp;
}
vector<ll> pot(1e4, 1);

signed solve(){
    ll a, b;
    cin >> a >> b;

    
    int cont = 100;

    if(a>b) swap(a, b);

    while(a!=b && cont){
        cont--;
        ll menor = min(2*a, b - a);
        ll maior = max(2*a, b - a);

        a = menor, b = maior;
    }

    if(a == b){
        int total = 101 - cont;
        // cout << total << ' ';

        ll sum = 0;

        for(int i=1; i<total; i++){
            sum += pot[total-i]*i;
        }
        sum += total*pot[1];

        sum %= mod;
        // cout << sum << ' ' << pot[total] << ' ';

        sum = sum * expo(pot[total], mod-2) % mod;


        cout << sum << endl;
        return 0;
    }

    cout << 2 << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    for(int i = 1; i < 1e4-5; i++){
        pot[i] = pot[i-1]*2%mod;
    }

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}