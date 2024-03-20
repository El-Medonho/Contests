#include "bits/stdc++.h"

#define endl '\n'

typedef long long ll;

typedef double ld;

using namespace std;

const int mxn = 1e5;

signed solve(){

    int n; cin >> n;

    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    vector<int> div(0);

    div.push_back(1);

    for(int i = 2; i * i <= n; i++){
        div.push_back(i);
        div.push_back(n/i);
    }


    pair<ld, pair<ll,ll>> resp = {1e18, {1e18, -1e18}};

    for(int k: div){
        vector<ll> pr(n, 0), pl(n, 0);

        pair<ll,ll> l = {1e18, -1e18};

        vector<pair<ll,ll>> r(n , {1e18, -1e18});

        for(int i = 1; i < n; i+=k){
            for(int j = i; j < i+k && j < n; j++) pl[i] += arr[j];
        }

        for(int i = k; i < n; i+=k){
            for(int j = i; j < i+k && j < n; j++) pr[i] += arr[j];
        }

        for(int i = n-k; i > -1; i-=k){
            r[i] = {1e18, -1e18};
            if(i != n-k) r[i] = r[i+k];

            r[i] = {min(r[i].first, pr[i]), max(r[i].second, pr[i])};
        }

        for(int i = 1; i < n; i += k){
            pair<ll,ll> ans = {1e18, -1e18};    //{min, max}

            ll sum = arr[0];
            for(int j = i; j < i+k-1; j++) sum += arr[j];

            ans = {min(ans.first, sum), max(ans.second, sum)};
            ans = {min(ans.first, l.first), max(ans.second, l.second)};

            int h = i-1+k;

            if(h < n) ans = {min(ans.first, r[i].first), max(ans.second, r[i].second)};

            ld ratio = ((ld)ans.second) / ans.first;

            if(ratio < resp.first){
                resp = {ratio, ans};
            }

            l.first = min(l.first, pl[i]);
            l.second = max(l.second, pl[i]);
        }

    }

    ll a = resp.second.first, b = resp.second.second;

    cout << b / __gcd(a,b) << ' ' << a / __gcd(a,b) << endl;

    

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