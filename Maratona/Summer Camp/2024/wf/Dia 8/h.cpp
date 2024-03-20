#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

struct P {
    ll x, y;

    P(ll xx = 0, ll yy = 0){
        x = xx;
        y = yy;
    }
};

signed solve(){

    P mn1,mn2,mx1,mx2;

    ll ans = 0;

    cin >> mn1.x >> mn1.y >> mx1.x >> mx1.y >> mn2.x >> mn2.y >> mx2.x >> mx2.y;

    ans = max(ans, (mx1.x - mn1.x) * (mx1.y - mn1.y));
    ans = max(ans, (mx2.x - mn2.x) * (mx2.y - mn2.y));

    // ans = max(ans, (mx1.y - mn1.y) * (mx2.x - mn2.x));
    // ans = max(ans, (mx2.y - mn2.y) * (mx1.x - mn1.x));

    bool ok = true;

    if(mx1.x <= mx2.x && mn1.x >= mn2.x) ok = false;
    if(mx1.y <= mx2.y && mn1.y >= mn2.y) ok = false;

    if(mx2.x <= mx1.x && mn2.x >= mn1.x) ok = false;
    if(mx2.y <= mx1.y && mn2.y >= mn1.y) ok = false;

    if(mn1.x > mx2.x || mn2.x > mx2.x) ok = false;
    if(mn1.y > mx2.y || mn2.y > mx2.y) ok = false;

    if(ok){
        ans = max(ans, (mx1.y - mn2.y) * (mx2.x - mn1.x));
        ans = max(ans, (mx2.y - mn1.y) * (mx1.x - mn2.x));
    }

    ll x1 = max(mn2.x, mn1.x), x2 = min(mx2.x, mx1.x);
    ll y1 = min(mn2.y, mn1.y), y2 = max(mx2.y, mx1.y);

    ans = max(ans, (x2-x1) * (y2-y1));

    x1 = min(mn2.x, mn1.x), x2 = max(mx2.x, mx1.x);
    y1 = max(mn2.y, mn1.y), y2 = min(mx2.y, mx1.y);

    ans = max(ans, (x2-x1) * (y2-y1));

    cout << ans << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);


    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }


    return 0;
}