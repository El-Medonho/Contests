#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

ll m = 998244353;

ll sum(ll a, ll b) {
    if(a+b >= m) return a+b-m;
    return a+b;
}

ll sub(ll a, ll b) {
    if(a-b < 0) return a-b+m;
    return a-b;
}

struct FenwickTree {
    vector<ll> bit;

    FenwickTree(int n) : bit(n+1) {}

    FenwickTree(vector<int>& v) : FenwickTree(v.size()+1) {
        for(int i = i; i < bit.size(); i++) {
            bit[i] += v[i-1];
            if(i+(i&-i) < bit.size()) bit[i+(i&-i)] += bit[i];
        }
    }

    void upd(int i, ll val) {
        while(i <= bit.size()) {
            bit[i] = sum(bit[i],val);
            i += i&-i;
        }
    }

    ll query(int l, int r) {
        return sub(bsum(r),bsum(l-1));
    }

    ll bsum(int i) {
        ll ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= i&-i;
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;
        
        sort(a.begin(), a.end());

        // FenwickTree dp(n/2+1);
        // dp.upd(0+1,1);

        vector<ll> dp(n+1);
        dp[0] = dp[1] = 1;

        for(int i = n-2, count = 2; i >= 0; i--, count++) {
            for(int h = n-1; h > 1; h-=2) {
                dp[h] = dp[h]*(max(0,h-(count-1))) + dp[h-2];
            }
            for(ll x : dp) cout << x << ' ';
            cout << '\n';
        }

        cout << dp[n-1] << '\n';
    }
    return 0;
}