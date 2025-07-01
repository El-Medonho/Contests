#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ld;

signed solve(){

    ll R,w,h; cin >> R >> w >> h; 

    ld W = w, H = h;

    if(H/2*H/2 + W/2*W/2 > R*R){
        cout << 0 << endl;
        return 0;
    }

    ll l = 1, r = 1e9;

    ll A = w*h;

    ll ans = w*h;

    auto f = [&](auto&& self, ll md) -> ll {
        ld b = md*w;
        if(md*w > 2*R) return 0;
        b /= 2;
        ll x = 2*sqrtl(R*R-b*b);

        ans = max(ans, ((x/h)*h) * (md*w));

        return ((x/h)*h) * (md*w);
    };

    while(r-l >= 5){
        ll mid = (l+r)/2;
        if(f(f, mid) == 0){
            r = mid;
            continue;
        }
        while(f(f, mid) != 0 && f(f,mid) == f(f,mid+1)){
            mid++;
        }
        if(f(f, mid) != 0 && f(f,mid) < f(f,mid+1)) l = mid;
        else r = mid;
    }

    for(ll i = l; i <= r; i++){
        if(f(f,l) < f(f,i)) l = i;
    }

    cout << ans/(w*h) << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}