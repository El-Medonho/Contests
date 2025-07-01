#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

#define f first
#define s second

typedef long long ll;

const int mxn = 1e5+5;
const int inf = 1e9;


signed solve(){

    int n,m; cin >> n >> m;

    unordered_map<int,int> mp;
    set<int> times;

    int cnt = 0;


    vector<tuple<int,int,int>> edges(m); 

    vector<vector<pair<pair<int,int>, int>>> graph(n);

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        edges[i] = {a,b,c};

        times.insert(c);
    }

    for(int x: times) mp[x] = cnt++;
    vector<vector<int>> ind_time(cnt);
    vector<int> num_edges(cnt, 0);

    vector<int> dist(n, inf); dist[0] = 0;

    for(auto[a,b,c]: edges){
        a--; b--;
        graph[a].push_back({{mp[c],0}, b});
        graph[b].push_back({{mp[c],1}, a});

        ind_time[mp[c]].push_back(a);
        ind_time[mp[c]].push_back(b);
        num_edges[mp[c]]++;
    }

    for(int i = 0; i < n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> ind(n, 0);

    for(int t = 0; t < cnt; t++){
        vector<pair<int,int>> ch(0); ch.reserve(2*num_edges[t]);

        for(int cc: ind_time[t]){
            if(dist[cc] == inf) continue;
            while(ind[cc] != graph[cc].size() && graph[cc][ind[cc]].f.f <= t){
                auto [vals, j] = graph[cc][ind[cc]];

                if(vals.f < t){
                    ind[cc]++;
                    continue;
                }

                if(dist[j] <= dist[cc] + vals.s){
                    ind[cc]++;
                    continue;
                }

                ch.push_back({j, dist[cc] + vals.s});

                // pq.push({dist[j], j});

                ind[cc]++;
            }
        }

        for(auto[i, x]: ch) dist[i] = min(dist[i], x);
    }

    if(dist[n-1] == inf) cout << -1 << endl;
    else cout << dist[n-1] << endl;


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