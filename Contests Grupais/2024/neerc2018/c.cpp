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

const int n = 3e5;
const int sq = 500;

int main() {
    fastio;

    vector<vector<ll>> dp(n, vector<ll>(sq, 0)); dp[0][0] = 1;

    for(int i = 1; i < n; i++){
        for(int j = sq; j > 0; j--){
            dp[i][j] += dp[]
        }
    }
}