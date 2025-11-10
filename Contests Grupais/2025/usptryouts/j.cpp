#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;
#define MOD 1000000007

using pll = pair<ll,ll>;

ll bin_exp(ll a, ll b) {
    a %= MOD;
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = ans*a % MOD;
        b >>= 1;
        a = a*a % MOD;
    }
    return ans;
}

int inv(int n) {
    return bin_exp(n, MOD-2);
}

int pos_mod(ll a) {
    return ((a % MOD) + MOD) % MOD;
}

int n, m, s, t;
vector<vector<int>> g;

vector<pll> bfs(int u0) {
    vector<int> vis(n+1);
    vector<pll> dist(n+1,{-1,0});
    queue<pll> q;
    q.emplace(u0,0);
    vis[u0] = true;
    dist[u0] = {0,1};

    while(!q.empty()) {
        auto [u,d] = q.front();
        q.pop();

        for(int v : g[u]) {
            if(!vis[v]) {
                q.emplace(v,d+1);
                vis[v] = true;
                dist[v] = {d+1,dist[u].second};
            }else if(dist[v].first == d+1) {
                dist[v].second = (dist[v].second + dist[u].second) % MOD;
            }
        }
    }

    return dist;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> s >> t;
    g.resize(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pll> ds = bfs(s); // dist, count
    vector<pll> dt = bfs(t);

    int min_dist = ds[t].first;
    ll ans = 0;

    vector<int> vis(n+1);
    queue<pll> q;
    q.emplace(s,0);
    vis[s] = true;

    while(!q.empty()) {
        auto [u,d] = q.front();
        q.pop();

        auto [dsu, csu] = ds[u];

        for(int v : g[u]) {
            auto& [dvs, cvs] = ds[v];
            auto [dvt, cvt] = dt[v];
            if(dsu + 1 + dvt == min_dist+1) {
                //cout << u << ' ' << v << ' ' << dsu << ' ' << dvt << '\n';
                ans = (ans + csu*cvt) % MOD;
                if(dsu+1 == dvs) {
                cvs = pos_mod(cvs-csu);
                }
            }
            if(!vis[v]) {
                q.emplace(v,d+1);
                vis[v] = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}