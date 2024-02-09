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

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set<int> xc;

    for(int i = 0; i < n; i++){
        if(graph[i].size() == 1) xc.insert(i);
    }

    vector<int> ans(0), vis(n, 0);
    int root = -1;

    vector<vector<pair<int,int>>> order(n);

    function<int(int,int)> ini, desc, pass;
    function<int(int,int,int)> src;

    src = [&](int cc, int last, int obj){

        if(cc == obj) return last;

        for(int j: graph[cc]){
            if(j == last) continue;
            int h = src(j, cc, obj);
            if(h != -1) return h;
        }
        return -1;
    };

    desc = [&](int cc, int last){

        int val = 1e7;
        for(int j: graph[cc]){
            if(j == last) continue;
            int hj = desc(j, cc);
            val = min(hj, val);
            order[cc].push_back( make_pair(hj, j) );
        }

        sort(order[cc].begin(), order[cc].end());

        if(val == 1e7) val = cc;

        return val;
    };

    pass = [&](int cc, int last){
        vis[cc] = 1;
        for(auto [hj, j]: order[cc] ){
            pass(j, cc);
        }

        ans.push_back(cc);
        if(xc.find(cc) != xc.end()) xc.erase(cc);
        return 0;
    };

    ini = [&](int cc, int last){

        vis[cc] = 1;
        if(graph[cc].size() >= 3){
            root = cc;

            int h = graph[cc].size(); h-=2;

            while(h){
                int nxt = src(*xc.begin(), -1, cc);
                desc(nxt, cc);
                pass(nxt, cc);
                h--;
            }

            if(cc > *xc.begin()){
                int nxt = src(*xc.begin(), -1, cc);
                desc(nxt, cc);
                pass(nxt, cc);
            }
        }
        else if(cc > *xc.begin()) {
            root = cc;

            int nxt = src(*xc.begin(), -1, cc);
            desc(nxt, cc);
            pass(nxt, cc);
        }

        ans.push_back(cc);
        if(xc.find(cc) != xc.end()) xc.erase(cc);
            
        for(int j: graph[cc]){
            if(j == last || vis[j]) continue;
            ini(j, cc);
        }



        return 0;
    };

    // while(root == -1){
    //     int x = *xc.begin(); xc.erase(xc.begin());
    //     ini(x,x);
    // }
    
    ini(*xc.begin(), *xc.begin());

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