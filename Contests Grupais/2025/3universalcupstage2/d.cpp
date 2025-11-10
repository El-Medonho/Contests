#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const ll mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    //0 -> first
    //1 -> second
    vector<pair<ll,ll>> dp(62, make_pair(1LL,0LL));

    ll sum = 0, ans = 0;

    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        x ^= sum; sum = x;
        ll cc = 0;
        for(int j = 0; j < 62; j++){
            if(x>>j&1) cc += (1LL << j) % mod * dp[j].first % mod;
            else cc += (1LL << j) % mod * dp[j].second % mod;
            if(cc >= mod) cc -= mod;
        }
        // cout << cc << endl;
        ans = cc;
        for(int j = 0; j < 62; j++){
            if(x>>j&1) {dp[j].second += cc; if(dp[j].second >= mod) dp[j].second -= mod;}
            else {dp[j].first += cc; if(dp[j].first >= mod) dp[j].first -= mod;}
        }
    }

    cout << ans << endl;

    return 0;
}