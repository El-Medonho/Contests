#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
using pll = pair<ll,ll>;
using pii = pair<int,int>;

void dfs1(int u, int p, vector<vector<pll>>& g, vector<pll>& parent) {
    for(auto [v,w] : g[u]) {
        if(v == p) continue;
        parent[v] = {u,w};
        dfs1(v, u, g, parent);
    }
}

signed solve(){
    int n, q, c;
    cin >> n >> q >> c;

    vector<vector<pll>> g(n+1);

    for(int m = 0; m < n-1; m++) {
        int u, v;
        cin >> u >> v >> c;
        g[u].emplace_back(v,c);
        g[v].emplace_back(u,c);
    }

    vector<pll> p(n+1);

    dfs1(1, 0, g, p);

    vector<vector<int>> up(20, vector<int>(n+1));
    for(int u = 1; u <= n; u++) up[0][u] = p[u].first;

    vector<vector<ll>> sum(20, vector<ll>(n+1));
    for(int u = 1; u <= n; u++) sum[0][u] = p[u].second;


    for(int k = 1; k < 20; k++) {
        for(int u = 1; u <= n; u++) {
            up[k][u] = up[k-1][up[k-1][u]];
            sum[k][u] = sum[k-1][u] + sum[k-1][up[k-1][u]];
        }
    }

    auto get_up = [&](int u, int k) {
        int i = 0;
        while(k > 0) {
            if(k&1) {
                u = up[u][i];
            }
            i++;
            k >>= 1;
        }
        return u;
    };

    auto get_sum = [&](int u, int k) {
        ll ans = 0;
        int i = 0;
        while(k > 0) {
            if(k&1) {
                ans += sum[u][i];
                u = up[u][i];
            }
            i++;
            k >>= 1;
        }
        return ans;
    };

    auto get_lowest_sum = [&](int u, int target) {
        int l = 0, r = n-1, ans = -1;
        while(l <= r) {
            int mid = (l+r)/2;

            if(get_sum(u, mid) <= c) {
                ans = mid;
                l = mid+1;
            }else {
                r = mid-1;
            }
        }

        return make_pair(get_up(u, ans), ans);
    };

    vector<vector<pll>> cnt(20, vector<pll>(n)); //quantos caras passo e quanto fuel sobrou em cima pra ir pro 2^k-ésimo ancestral

    auto get_cnt = [&](int u, int k) {
        int ans = 0, fuel = 0;
        for(int i = 0; i < 20; i++) {
            if(k&1) {
                ans += cnt[u][i].first;
                pair<int,int> ls = get_lowest_sum(up[u][i], cnt[u][i].second);
                int u = ls.first;
                fuel = cnt[u][i].second - ls.second;
                ans++;
            }
        }
        return make_pair(ans, fuel);
    };

    for(int u = 1; u <= n; u++) {
        cnt[0][u] = {0,p[u].second};
    }

    for(int k = 1; k < 20; k++) {
        for(int u = 1; u <= n; u++) {
            cnt[k][u] = cnt[k-1][u];
            int fuel = cnt[k-1][u].second;

            pii ls = get_lowest_sum(up[k-1][u], fuel);

            int v = ls.first;
            pll bla = get_cnt(v, (1<<k)-ls.second);
            cnt[k][u].first += bla.first;
            cnt[k][u].second = bla.second;
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}