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
    
    int h; cin >> h;

    int n,m; cin >> n >> m;

    vector<pair<int,int>> arr(h);

    for(int i = 0; i < h; i++) cin >> arr[i].first >> arr[i].second;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    function<bool(int)> dfs;

    dfs = [&](int mask){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]) continue;

                for(int k = 0; k < h; k++){
                    if(mask & (1<<k)) continue;

                    // mask ^= (1<<k);



                    bool ok = true;
                    if(i + arr[k].first > n || j + arr[k].second > m) ok = false;

                    if(ok){
                        for(int a = i; a < i+arr[k].first; a++){
                            for(int b = j; b < j+arr[k].second; b++){
                                if(grid[a][b]) ok = false;
                            }
                        }
                    }


                    if(ok){

                        mask ^= (1<<k);

                        for(int a = i; a < i+arr[k].first; a++){
                            for(int b = j; b < j+arr[k].second; b++){
                                grid[a][b] = 1;
                            }
                        }

                        if(dfs(mask)) return true;

                        mask ^= (1<<k);

                        for(int a = i; a < i+arr[k].first; a++){
                            for(int b = j; b < j+arr[k].second; b++){
                                grid[a][b] = 0;
                            }
                        }

                    }


                    swap(arr[k].first, arr[k].second);


                    ok = true;

                    if(i + arr[k].first > n || j + arr[k].second > m) ok = false;

                    if(ok){
                        for(int a = i; a < i+arr[k].first; a++){
                            for(int b = j; b < j+arr[k].second; b++){
                                if(grid[a][b]) ok = false;
                            }
                        }
                    }

                    if(ok){

                        mask ^= (1<<k);

                        for(int a = i; a < i+arr[k].first; a++){
                            for(int b = j; b < j+arr[k].second; b++){
                                grid[a][b] = 1;
                            }
                        }

                        if(dfs(mask)) return true;

                        mask ^= (1<<k);

                        for(int a = i; a < i+arr[k].first; a++){
                            for(int b = j; b < j+arr[k].second; b++){
                                grid[a][b] = 0;
                            }
                        }
                        
                    }

                    swap(arr[k].first, arr[k].second);
                }

                return false;
            }
        }

        return true;
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