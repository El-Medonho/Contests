#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

int n, k;
vector<vector<int>> g;
vector<ll> w, mx;

void dfs(int u, int p) {
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
    }

    ll sum = 0;
    if(w[u] != -1) sum += w[u];
    for(int v : g[u]) {
        if(v == p) continue;
        if(w[v] != -1) sum += w[v];
    }

    if(sum > k) {
        cout << -1 << '\n';
        exit(0);
    }

    for(int v : g[u]) {
        if(v == p || w[v] != -1) continue;
        if(sum+mx[v] <= k) {
            sum += mx[v];
            w[v] = mx[v];
        }else {
            w[v] = k-sum;
            sum = k;
        }
    }

    if(w[u] == -1) mx[u] = k-sum;
    else mx[u] = 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    g.resize(n+1);
    w.resize(n+1);

    for(int i = 1; i <= n; i++) cin >> w[i];

    for(int m = 0; m < n-1; m++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    mx.resize(n+1, -1);
    dfs(1, 0);
    if(w[1] == -1) w[1] = mx[1];

    cout << accumulate(w.begin()+1, w.end(), 0ll) << '\n';
    return 0;
}