#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    fastio;

    int n, t;
    cin >> n >> t;

    vector<vector<ll>> c(n+1, vector<ll>(t+1, 0LL));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= t; j++) {
            cin >> c[i][j];
            c[i][j] += c[i][j-1];
        }
    }

    int l, u;
    cin >> l >> u;

    vector<vector<ll>> dp(t+1, vector<ll>(n+1, -1));
    for(int i = 1; i <= n; i++) dp[0][i] = 0;

    for(int ti = 0; ti < t; ti++) {
        ll mx = -1, mx2 = -1;

        if(ti == 0){
            mx = 0; mx2 = 0;
        }

        for(int i = 1; i <= n; i++){
            if(mx < dp[ti][i]){
                swap(mx, mx2);
                mx = dp[ti][i];
            }
            else if(mx2 < dp[ti][i]) mx2 = dp[ti][i];
        }

        for(int i = 1; i <= n; i++) {
            ll cc = mx;
            if(dp[ti][i] == mx) cc = mx2;
            if(cc == -1) continue;
            for(int offset = l; offset <= u; offset++) {
                if(ti+offset <= t) dp[ti+offset][i] = max(dp[ti+offset][i], cc+c[i][ti+offset]-c[i][ti]);
            }
        }
    }


    ll ans = -1;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[t][i]);
    }

    cout << ans << '\n';
}   