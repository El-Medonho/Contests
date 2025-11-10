#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const ll mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    map<ll,ll> mp; mp[0] = 1;

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        ll cc = 0;

        map<ll,ll> nmp;
        for(auto [val, q]: mp){
            nmp[val^x] = (nmp[val^x] + q);
            if(nmp[val^x] >= mod) nmp[val^x] -= mod;

            cc = (cc + q * ((val^x)%mod) % mod);
            // cout << (val^x) << endl;
            if(cc >= mod) cc -= mod;
        }

        nmp[0] = (nmp[0] + cc);
        if(nmp[0] >= mod) nmp[0] -= mod;
        mp = nmp;
        cout << cc << endl;
        ans = cc;
    }

    cout << ans << endl;

    return 0;
}