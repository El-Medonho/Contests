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

signed solve(){

    int n,m; cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n);
    // vector<vector<int>> mark(n);

    map<pair<int,int>, int> mark;

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    function<void(int,int)> tarj;

    vector<int> lowlink(n, -1), depth(n, -1), vis(n, 0), root(n, 0);

    int tempo = 0;

    tarj = [&](int cc, int last){
        depth[cc] = lowlink[cc] = ++tempo;
        vis[cc] = 1;

        for(auto[j, w]: graph[cc]){
            if(vis[j]){
                if(j == last) continue;
                lowlink[cc] = min(lowlink[cc], depth[j]);
            }
            else{
                tarj(j, cc);
                if(lowlink[j] == depth[j]){
                    mark[{ min(cc,j), max(cc,j) }]++;
                }
                lowlink[cc] = min(lowlink[cc], lowlink[j]);
            }
        }
    };

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            root[i] = 1;
            tarj(i,i);
        }
    }

    pair<int,pair<int,int>> pp = {1e9, {0,0}};

    for(int i = 0; i < n; i++){
        for(auto[j, w]: graph[i]){
            if(!mark[{min(i,j), max(i,j)}]){
                pp = min(pp, {w, {i,j}});
            }
        }
    }

    fill(vis.begin(), vis.end(), 0);

    vector<int> ans(0);

    function<bool(int,int)> dfs;

    dfs = [&](int cc, int last){
        vis[cc] = 1;

        if(cc == pp.second.first){
            for(auto[j, w]: graph[cc]){
                if(j == pp.second.second){
                    
                    if(dfs(j, cc)){
                        ans.push_back(cc);
                        return true;
                    }
                }
            }
            return false;
        } 

        for(auto[j, w]: graph[cc]){
            if(j == last) continue;
            if(vis[j] && j == pp.second.first) {
                ans.push_back(cc);
                return true;
            }
        }

        for(auto[j, w]: graph[cc]){
            if(j == last) continue;
            if(vis[j]) continue;

            if(dfs(j, cc)){
                ans.push_back(cc);
                return true;
            }
        }

        return false;
    };

    int h = pp.second.first;

    if(!dfs(h,h)){
        cout << "aa" << endl;
        return 0;
    }

    reverse(ans.begin(), ans.end());

    cout << pp.first << ' ' << ans.size() << endl;
    for(int i: ans) cout << i+1 << ' ';
    cout << endl;

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}