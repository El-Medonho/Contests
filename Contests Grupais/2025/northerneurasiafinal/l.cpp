#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

void yes(int w, int t, vector<int>& last) {
    vector<int> p1 = {t}, p2;

    while(w != 0) {
        p1.push_back(w);
        w = last[w];
    }

    while(t != 0) {
        p2.push_back(t);
        t = last[t];
    }

    reverse(p1.begin(), p1.end());
    reverse(p2.begin(), p2.end());

    cout << "Possible\n";

    cout << p1.size() << '\n';
    for(int u : p1) cout << u << ' ';
    cout << '\n';
    
    cout << p2.size() << '\n';
    for(int u : p2) cout << u << ' ';
    cout << '\n';

    exit(0);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> g(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    queue<int> q;
    vector<int> last(n+1), c(n+1);

    for(int i = 0; i < g[s].size(); i++) {
        int v = g[s][i];
        q.push(v);
        last[v] = s;
        c[v] = i+1;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : g[u]) {
            if(v == s) continue;
            if(!c[v]) {
                q.push(v);
                last[v] = u;
                c[v] = c[u];
            }else if(c[u] != c[v]) {
                yes(u, v, last);
            }
        }
    }

    cout << "Impossible\n";

    return 0;
}