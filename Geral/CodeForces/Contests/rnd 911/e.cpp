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
    vector<vector<int>> graph(n), ngraph(n);
    
    vector<ll> pesos(n);
    for(ll &i: pesos) cin >> i;

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    stack<int> stk;
    vector<int> lowlink(n, 0), depth(n, 0);
    vector<int> repr(n, 0), w(n, 0);
    vector<bool> visiting(n, 0);
    int tempo = 1;

    function<void(int)> dfs1;

    dfs1 = [&](int cc){

        depth[cc] = lowlink[cc] = tempo++;
        visiting[cc] = 1;
        stk.push(cc);

        for(int j: graph[cc]){
            if(visiting[j]) lowlink[cc] = min(lowlink[cc], depth[j]);
            else if(lowlink[j] == 0){
                dfs1(j);
                lowlink[cc] = min(lowlink[cc], lowlink[j]);
            } 
        }

        if(lowlink[cc] == depth[cc]){
            repr[cc] = cc;
            w[cc] = 1;
            int u = stk.top();
            visiting[cc] = 0;

            while(u != cc){
                repr[u] = cc;
                w[cc]++;
                pesos[cc] += pesos[u];
                visiting[u] = 0;
                stk.pop();
                u = stk.top();
            }
            stk.pop();
        }

    };

    for(int i = 0; i < n; i++){
        if(!lowlink[i]) dfs1(i);
    }

    vector<int> chama(n, 0);

    for(int i = 0; i < n; i++){
        for(int j : graph[i]){
            if(repr[j] == repr[i]) continue;
            ngraph[repr[i]].push_back(repr[j]);
            chama[repr[j]]++;
        }
    }

    queue<int> qw;

    function<bool(pair<ll,ll>, pair<ll,ll>)> cmp = [](pair<ll,ll> a, pair<ll,ll> b){
        if(a.first != b.first) return a < b;
        else return b < a;
    };

    vector<pair<ll,ll>> best(n, {0,0});

    for(int i = 0; i < n; i++){
        if(w[i] && !chama[i]){
            qw.push(i);
            best[i] = {w[i], pesos[i]};
        }
    }

    pair<ll,ll> ans = {0,0};

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();

        ans = max(ans, best[cc], cmp);

        for(int j: ngraph[cc]){
            chama[j]--;
            pair<ll,ll> nw = best[cc];
            nw.first += w[j]; nw.second += pesos[j];
            best[j] = max(best[j], nw, cmp);
            if(!chama[j]){
                qw.push(j);
            }
        }
    }

    cout << ans.first << ' ' << ans.second << endl;
    

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