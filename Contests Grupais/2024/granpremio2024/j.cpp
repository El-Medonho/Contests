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

const int m = 1e9+7;

ll add(ll a, ll b) {
    ll ans = a+b;
    if(ans >= m) ans -= m;
    return ans;
}

int main() {
    fastio;

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> pref(n+1, 0);
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + (s[i-1] - '0');

    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][n-1] = 1;

    for(int sz = n-1; sz > 0; sz--) {
        for(int i = 0; i <= n-sz; i++) {
            int j = i+sz-1;
            int black = pref[i] + pref[n] - pref[j+1];
            int white = n - sz - black;

            if(white > black) continue;

            if(i-1 >= 0) dp[i][j] = add(dp[i][j], dp[i-1][j]);
            if(j+1 < n) dp[i][j] = add(dp[i][j], dp[i][j+1]);
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) ans = add(ans, dp[i][i]);

    if(pref[n] < n-pref[n] || ans == 0) cout << 0 << '\n';
    else cout << add(ans,1) << '\n';
}