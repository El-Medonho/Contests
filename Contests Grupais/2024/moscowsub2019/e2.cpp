#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;
const int INF = 0x3f3f3f3f;

signed solve(){
    int n, m;
    cin >> n >> m;

    map<int, vector<pair<int, int> > > edges;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[c].push_back({a, b});
    }

    vector<int> dist(n+1, INF);
    dist[1]=0;

    for(auto [k, v]:edges){
        vector<pair<int, int> > ch;
        for(auto [a, b]:v){
            if(dist[b]>dist[a]) ch.push_back({b, dist[a]});
            if(dist[a]>dist[b]+1) ch.push_back({a, dist[b]+1});
        }
        for(auto [a, b]:ch){
            dist[a] = min(dist[a], b);
        }
    }

    if(dist[n]==INF) cout << -1 << endl;
    else cout << dist[n] << endl;
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