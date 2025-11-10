#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int mxn = 4e5+5;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, k;
vector<pair<int, int> > vec[mxn];

ll dist[mxn];

void dj(int x){
    for(int i=1; i<=n+k; i++) dist[i] = INFL;
    dist[x] = 0;

    priority_queue<pair<ll, int> > fila;
    fila.push({0, x});

    while(!fila.empty()){
        auto c = -fila.top().first; auto u = fila.top().second;
        fila.pop();

        if(c>dist[u]) continue;

       // cout << u << ' ' << c << endl;

        for(auto [i, c]:vec[u]){
            if(dist[i] > dist[u] + c){
                dist[i] = dist[u] + c;
                fila.push({-dist[i], i});
            } //else if(i > n){
            //     dist[i] = dist[u] + c;
            //     fila.push({-dist[i], i});
            // }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> k;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }

    for(int i=1; i<=n; i++){
        int k;
        cin >> k;

        for(int j=0; j<k; j++){
            int u, c;
            cin >> u >> c;
            vec[i].push_back({n+u, c});
            vec[n+u].push_back({i, 0});
        }
    }
    dj(1);
    cout << dist[n] << endl;
    return 0;
}