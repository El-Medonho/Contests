#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

ll dist(pair<ll,ll> a, pair<ll,ll> b) {
    return ((a.first-b.first) * (a.first-b.first) + (a.second-b.second) * (a.second-b.second));
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<ll,ll>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    ld ans = 0;

    for(int i = 0; i < n; i++){
        int j = (i+1)%n, k = (i+2)%n;
        ld cc = 0; cc -= sqrtl(dist(arr[i], arr[j])); cc -= sqrtl(dist(arr[j], arr[k]));
        cc += sqrtl(2) * sqrtl(dist(arr[i], arr[k]));
        cout << i << ' ' << k << ' ' << cc << '\n';
        ans = max(ans, cc);
    }
    
    cout << fixed << setprecision(10) << ans << '\n';

    

    return 0;
}