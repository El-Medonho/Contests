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

    int n; cin >> n;
    vector<int> memo(n, 0);

    string s; cin >> s;
    for(int i = 0; i < n; i++) memo[i] = s[i]-'0';

    vector<set<int>> aha(n);
    vector<vector<pair<int,int>>> graph(n);
    vector<int> filhos(n, 0);

    for(int i = 0; i < n; i++){
        int a; cin >> a; a--;
        if(aha[a].find(i) != aha[a].end()) continue;

        aha[a].insert(i);
        aha[i].insert(a);

        graph[a].push_back({i,i});
        graph[i].push_back({a,i});


        filhos[a] = graph[a].size()-1;
        filhos[i] = graph[i].size()-1;
    }

    vector<int> ans(0);
    vector<int> vis(n, 0), q1(0);

    function<int(int, int, int)> dfs, dfs2;

    dfs2 = [&](int cc, int last, int estado)  {
        vis[cc] = 1;

        for(auto [j,ind]: graph[cc]){
            if(j == last || vis[j]) continue;
            filhos[j]--;
            if(memo[cc] == 1) ans.push_back(ind);
            memo[j] = memo[j] != memo[cc];
            if(filhos[j] == 0) dfs2(j,cc,estado);
            memo[cc] = 0;
        }

        return 0;
    };

    for(int i = 0; i < n; i++){
        if(filhos[i] <= 0 && !vis[i]) dfs2(i,i,0);
    }

    for(int i = 0; i < n; i++){
        if(filhos[i] <= 0 && memo[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    int sz = 0, ini = -1;
     
    dfs = [&](int cc, int last, int estado){
        sz++;
        vis[cc] = 1;
        estado = estado != memo[cc];
        for(auto [j,ind] : graph[cc]){
            if(j == last) continue;
            if(j == ini && estado){
                cout << -1 << endl;
                return -1;
            }
            else if(j == ini){
                return 0;
            }
            else if(filhos[j] <= 0 || j == last) continue;

            if(dfs(j, cc, estado) == -1) return -1;
            if(estado == 1) q1.push_back(ind);

            if(cc == last){
                if(q1.size() <= (sz)/2) return 0;
                q1.clear();
                sz = 1;
            }
        }

        return 0;
    };

    for(int i = 0; i < n; i++){
        if(filhos[i] && !vis[i] && memo[i]) {
            ini = i;
            if(dfs(i,i,0) == -1) return 0;
            for(int i: q1) ans.push_back(i);
            q1.clear();
            sz = 0;
        }
    }



    cout << ans.size() << endl;
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