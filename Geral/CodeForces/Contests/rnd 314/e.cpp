// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄


#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;

signed solve(){
    
    int n,m,s,t; cin >> n >> m >> s >> t; s--; t--;

    vector<vector<pair<int,ll>>> graph(n), rev(n);

    vector<vector<int>> edges(m);

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].push_back({b,c});
        rev[b].push_back({a,c});

        edges[i] = {a,b,c};
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> qw;

    vector<int> vis(n, 0);

    vector<ll> dist(n, 1e17); dist[s] = 0;

    qw.push({0,s});

    while(!qw.empty()){
        auto [d,cc] = qw.top(); qw.pop();

        if(vis[cc]) continue;

        vis[cc] = 1;

        for(auto [j, c]: graph[cc]){
            if(vis[j] || dist[j] <= dist[cc] + c) continue;

            dist[j] = dist[cc] + c;

            qw.push({dist[j], j});
        }
    }

    qw.push({0,t});

    vector<ll> rdist(n, 1e17); rdist[t] = 0;

    fill(vis.begin(), vis.end(), 0);

    while(!qw.empty()){
        auto [d,cc] = qw.top(); qw.pop();

        if(vis[cc]) continue;

        vis[cc] = 1;

        for(auto [j, c]: rev[cc]){
            if(vis[j] || rdist[j] <= rdist[cc] + c) continue;

            rdist[j] = rdist[cc] + c;

            qw.push({rdist[j], j});
        }
    }

    vector<vector<pair<int,int>>> cgraph(n);

    vector<int> pp(m, 0);

    for(int i = 0; i < m; i++){
        int a = edges[i][0], b = edges[i][1], c = edges[i][2];
        ll cc = dist[a] + rdist[b];
        
        if(cc + c == dist[t]){
            cgraph[a].push_back({b,i});
            cgraph[b].push_back({a,i});

            pp[i] = 1;
        }
    }

    vector<int> memo(n), low(n), tin(n);
    int cont;

    function<void(int,int)> dfs;

    dfs = [&](int x, int p) {

        map<int,int> mp;

        for(auto[i,h]: cgraph[x]) mp[i]++;

        memo[x] = 1;
        tin[x] = low[x] = ++cont;
        int children = 0;
        for (auto [i, h] : cgraph[x]) {
            if (i == p) continue;
            if (memo[i]) {
                low[x] = min(low[x], tin[i]);
            } else {
                dfs(i, x);
                low[x] = min(low[x], low[i]);
                if (low[i] > tin[x] && mp[i] == 1) {
                    pp[h] = 2;
                }
                children++;
            }
        }
    };

    function<void()> build;

    build = [&]() {
        cont = 0;
        for (int i = 0; i < n; i++) {
            memo[i] = low[i] = tin[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if(!memo[i]) dfs(i, 0);
        }
    };

    build();




    for(int i = 0; i < m; i++){
        int a = edges[i][0], b = edges[i][1], c = edges[i][2];
        ll cc = dist[a] + rdist[b];

        if(cc + c == dist[t]){
            if(pp[i] == 2) cout << "YES\n";
            else if(c > 1) cout << "CAN 1\n";
            else cout << "NO\n";
        }

        else if(cc + 1 > dist[t] - 1){
            cout << "NO\n";
        }

        else{
            cout << "CAN " << c - (dist[t] - 1 - cc) << endl; 
        }
    }


    return 0;
}

signed main(){
    fastio;

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}