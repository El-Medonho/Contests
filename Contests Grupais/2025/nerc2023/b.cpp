#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const ll mod = 998244353;

const ll NM = 3e5+5;
vector<ll> fat(NM, 1);
vector<ll> inv(NM, 1);

ll expo(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = ans*b%mod;
        b = b*b%mod;
        e>>=1;
    }
    return ans;
}

signed solve(){

    ll n,k; cin >> n >> k;

    k++;
    ll h = n/(2*k-2);
    ll I = ((h-1)*h/2) * (2*k-2) + (n %(2*k-2))*h;

    ll kl = k-2;
    int cnt = 3;
    ll m = n%(2*k-2);

    if(m == 0){
        cout << I << ' ' << 1 << endl;
        return 0;
    }

    if(m == 1){
        cout << I << ' ' << k << endl;
        return 0;
    }

    ll ans = 0;

    while(m >= 0 && cnt--){
        if(h == 0 && cnt > 0) {m--; continue;}
        ll cans = 0;
        for(int i = 0; i <= kl; i++){
            int j = m-2*i;
            if(j < 0 || j+i > kl) continue;
            if(h == 0 && j+i != kl) continue;

            cans += (fat[kl] * inv[i] % mod * inv[kl-i] % mod) * (fat[kl-i] * inv[j] % mod * inv[kl-i-j] % mod) % mod;     
            cans %= mod;        
        }

        if(cnt == 1) cans = cans*2 % mod;
        // cout << cans << endl;


        ans = (ans + cans) % mod;
        m--;
    }

    cout << I << ' ' << ans << endl;


    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    for(ll i = 1; i < NM; i++) fat[i] = fat[i-1]*i%mod;
    for(ll i = 0; i < NM; i++) inv[i] = expo(fat[i], mod-2);

    int t; cin >> t;
    while(t--) solve();
    


    return 0;
}