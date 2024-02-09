#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    ll b; cin >> b;

    vector<pair<ll,ll>> cost(n);
    vector<vector<int>> graph(n);

    cin >> cost[0].first; cin >> cost[0].second;
    cost[0].second = cost[0].first-cost[0].second;

    for(int i = 1; i < n; i++){
        ll a,b; cin >> a >> b;
        cost[i] = {a, a-b};
        int c; cin >> c;
        graph[i].push_back(c-1);
        graph[c-1].push_back(i);
    }

    vector<vector<ll>> dp(n, vector<ll>(n+2, 1e18));

    vector<int> dpsz(n, 1);

    function<void(int,int)> dfs;

    dfs = [&](int cc, int last){
        
        dp[cc][1] = cost[cc].second;
        for(int j: graph[cc]){
            if(j == last) continue;
            dfs(j, cc);

            cost[cc].first = min(cost[j].first, cost[cc].first);

            vector<ll> arr = dp[cc];
            int h = dpsz[cc];
            for(int a = h; a > 0; a--){
                // if(dp[cc][a] == 1e17) continue;
                for(int b = 1; b <= n; b++){
                    if(dp[j][b] == 1e17) break;
                    dpsz[cc] = max(dpsz[cc], a+b);
                    arr[a+b] = min(arr[a+b], dp[j][b] + dp[cc][a]);
                }
            }
            dp[cc] = arr;
        }

        for(int j: graph[cc]) {if(j != last) dp[cc][1] = min(dp[cc][1], (ll)cost[j].first);}

        return;
    };

    dfs(0,0);

    int ans = 0;
    for(int i = n; i > 0; i--){
        if(dp[0][i] <= b){
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}