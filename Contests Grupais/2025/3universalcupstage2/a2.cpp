#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1), inv_g(n+1);
    vector<int> in(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        inv_g[v].push_back(u);
        in[v]++;
    }

    vector<int> vis(n+1);
    queue<int> q;
    q.push(n);
    vis[n] = true;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : inv_g[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    vector<int> reachable = vis;
    fill(vis.begin(), vis.end(), 0);
    q.push(1);
    int ans = 0;
    vis[1] = true;

    for(int u = 1; u <= n; u++) {
        if(!reachable[u]) {
            for(int v : g[u]) {
                in[v]--;
            }
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : g[u]) {
            if(!reachable[v]) continue;
            in[v]--;
            if(vis[v]) {
               //cout << "Sum at " << u << '\n';
                ans++;
            }
            vis[v] = true;
            if(in[v] == 0) q.push(v);
        }
    }
    
    cout << ans + (vis[n] == true) << '\n';

    return 0;
}