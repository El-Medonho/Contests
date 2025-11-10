#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

int n, m, k;

bool bfs(int color, vector<vector<int>>& g, vector<int>& c) {
    queue<tiii> q; //u, or, dist
    vector<vector<int>> vis(n, vector<int>(4, -1)); //or1, dist, or2, dist2
    for(int u = 0; u < n; u++) {
        if(c[u] == color) {
            q.emplace(u,u,0);
            vis[u][0] = u;
            vis[u][1] = 0;
        }
    }
    
    while(!q.empty()) {
        auto [u, origin, dist] = q.front();
        q.pop();

        if(c[u] == color && u != origin && dist+1 <= k) {
            return false;
        }
        
        for(int v : g[u]) {
            // if(color == 1 && v == 2) {
            //     for(int x : vis[v]) cout << x << ' ';
            //     cout << '\n';
            // }
            if(vis[v][0] == -1) {
                vis[v][0] = origin;
                vis[v][1] = dist+1;
                q.emplace(v, origin, dist+1);
            }else if(vis[v][2] == -1 && vis[v][0] != origin) {
                vis[v][2] = origin;
                vis[v][3] = dist+1;
                q.emplace(v, origin, dist+1);
            }
        }
    }

    return true;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m >> k;

        vector<int> c(n);
        set<int> colors;
        for(int& ci : c) {
            cin >> ci;
            colors.insert(ci);
        }

        vector<vector<int>> g(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
        }

        bool yes = true;

        for(int color : colors) {
            yes = yes && bfs(color, g, c);
        }

        cout << (yes ? "YES" : "NO") << '\n';
    }

    return 0;
}