#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<pair<ll,ll>> arr(n);
    vector<ll> h(n);

    ll l = 0, r = 1e10;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second >> h[i];
        l = max(l, h[i]);
    }

    ll ans = 1e10; pair<ll,ll> coord = {-1, -1};

    while(l <= r){
        ll md = (l+r)/2;

        ll xm = 1e10, xn = -1e10, ym = 1e10, yn = -1e10;
        
        for(int i = 0; i < n; i++){
            ll d = md - h[i];
            xm = min(xm, d+arr[i].first);
            xn = max(xn, arr[i].first-d);

            ym = min(ym, d+arr[i].second);
            yn = max(yn, arr[i].second-d);
        }
        if(ym < yn || xm < xn){
            l = md+1;
        } else{
            r = md-1;
            ans = md;
            coord = {xm, ym};
        }
    }

    cout << coord.first << ' ' << coord.second << ' ' << ans << endl;

    return 0;
}