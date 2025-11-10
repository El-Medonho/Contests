#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

using pii = pair<int,int>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<int> p(n);
    for(int& pi : p) cin >> pi;

    vector<pii> dp(n, {1e6,1e6});

    for(int i = n-1; i >= 0; i--) {
        auto [first, last] = dp[p[i]];

        if(first <= i) {
            continue;
        }else if(first - i >= 2*d) {
            dp[p[i]] = {i,i};
        }else if(last-i+1 <= d) {
            dp[p[i]] = {i,last};
        }else if(first-i-1 >= d && i >= first-2*d && first-2*d >= 0) {
            dp[p[i]] = {first-2*d,i};
        }else {
            dp[p[i]] = {-1,-1};
        }
    }

    int ans = n;
    for(int i = n-1; i >= 0; i--) {
        if(dp[i] != make_pair(-1,-1)) ans = i;
    }

    cout << ans << '\n';

    return 0;
}