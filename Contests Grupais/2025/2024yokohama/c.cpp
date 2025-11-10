#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const ll mx = 2e18;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n);
    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    vector<ll> dist(n, 1e18); dist[0] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.emplace(0LL, 0);

    while(!pq.empty()){
        auto[d, cc] = pq.top(); pq.pop();

        if(d != dist[cc]) continue;

        for(auto[j, v]: graph[cc]){
            ll nx = d+v;
            if(nx >= dist[j]) continue;

            dist[j] = nx;
            pq.emplace(nx, j);
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += dist[i] * arr[i];

    cout << ans << endl;

    return 0;
}