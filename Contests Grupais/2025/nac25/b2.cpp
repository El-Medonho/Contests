#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;
const int mod = 998244353;


ll expo(ll b, ll e){
    ll resp = 1;
    while(e){
        if (e & 1){
            resp = (resp * b)%mod;
        }
        b = (b * b)%mod;
        e>>=1;
    }
    return resp;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> dp(n, 1), dp2(n, 1);

    auto dfs = [&](auto&&self, int cc, int pai) -> void {
        ll sum = 1;
        for(int j: graph[cc]){
            if(j == pai) continue;
            if(graph[j].size() != 1){
                self(self, j, cc);
            }

            dp[j] += dp2[j];
            dp[j] %= mod;

            sum = sum*dp[j]%mod;
        }
        dp[cc] = sum; dp2[cc] = 0;

        for(int j: graph[cc]){
            if(j == pai) continue;
            ll cs = sum * expo(dp[j], mod-2) % mod;
            cs = cs*dp2[j]%mod;
            dp2[cc] += cs; dp2[cc] %= mod;
        }
    };

    dfs(dfs, 0, -1);

    cout << dp[0] << endl;

    return 0;
}