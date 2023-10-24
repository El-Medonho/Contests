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

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
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

    vector<string> grid(4, string(4, '.'));
    vector<vector<string>> poli(3, vector<string>(4));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cin >> poli[i][j];
        }
    }

    pair<int,int> arri = {make_pair(1e9, -1e9), make_pair(1e9, -1e9), make_pair(1e9, -1e9)};
    pair<int,int> arrj = {make_pair(1e9, -1e9), make_pair(1e9, -1e9), make_pair(1e9, -1e9)};

    for(int k = 0; k < 3; k++){
        for(int i = 0; i < 4; i++){
            bool ok = false;
            for(int j = 0; j < 4; j++){
                if(poli[k][i][j] == '#'){
                    ok = true;
                }
            }
            if(ok){
                arri[k].first = min(arri[k].first, i);
                arri[k].second = max(arri[k].second, i);
            }
        }
        for(int j = 0; j < 4; j++){
            bool ok = false;
            for(int i = 0; i < 4; i++){
                if(poli[k][i][j] == '#'){
                    ok = true;
                }
            }
            if(ok){
                arrj[k].first = min(arrj[k].first, j);
                arrj[k].second = max(arrj[k].second, j);
            }
        }
    }

    int n = 4;

    function<bool(int)> dfs;

    dfs = [&](int cc){
        if(cc == 3) return true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++){
                bool ok = true;
                bool i1 = arri[cc].first < arri[cc].second;
                bool j1 = arrj[cc].first < arrj[cc].second;
                for(int ii = arri[cc].first; ii <= max(arri[cc].first, arri[cc].second) && ii >= min(arri[cc].first, arri[cc].second) && ok; ii += (i1 ? 1 : -1)){
                    for(int jj = arri[cc].first; jj <= max(arrj[cc].first, arrj[cc].second) && jj >= min(arrj[cc].first, arrj[cc].second) && ok; jj += (j1 ? 1 : -1)){
                        if(i + ii < n && j + ii < n){
                            if(poli[cc][ii][jj] == '#' && grid[i+ii][j+jj] == '#') {
                                ok = false;
                                break;
                            }
                        }
                        else if(poli[cc][ii][jj] == '#'){
                            ok = false;
                            break;
                        }
                    }
                }
                
                if(!ok) continue;
                for(int ii = arri[cc].first; ii <= max(arri[cc].first, arri[cc].second) && ii >= min(arri[cc].first, arri[cc].second) && ok; ii += (i1 ? 1 : -1)){
                    for(int jj = 0; jj < n; jj++){
                        if(i + ii < n && j + ii < n){
                            if(poli[cc][ii][jj] == '#') {
                                grid[i+ii][j+jj] = '#';
                            }
                        }
                    }
                }
                
                if(dfs(cc+1)) return true;
                for(int ii = arri[cc].first; ii <= max(arri[cc].first, arri[cc].second) && ii >= min(arri[cc].first, arri[cc].second) && ok; ii += (i1 ? 1 : -1)){
                    for(int jj = 0; jj < n; jj++){
                        if(i + ii < n && j + ii < n){
                            if(poli[cc][ii][jj] == '#') {
                                grid[i+ii][j+jj] = '.';
                            }
                        }
                    }
                }
            }
        }
        return false;
    };
    

    if(dfs(0)) cout << "Yes\n";
    else cout << "No\n";

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