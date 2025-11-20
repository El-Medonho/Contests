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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find
typedef tuple<int,int,int> pii;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;
const int inf = 1e9+5;

signed solve(){
    
    int n,m; cin >> n >> m;
    
    vector<pair<int,int>> dir = {{0,-1}, {-1, 0}, {0,1}, {1,0}};
    
    vector<string> arr(n);
    vector<vector<int>> vis(n*m, vector<int>(4, inf));
    // dist, node, dir
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.emplace(0, 0, 0);
    vis[0][0] = 0;
    // 0 - L; 1 - U; 2 - R; 3 - D
    
    for(string &s: arr){
        cin >> s;
    }
    int ans = inf;

    while(!pq.empty()){
        auto[dist, cc, cd] = pq.top(); pq.pop();
        int a = cc/m, b = cc%m;
        if(vis[a*m+b][cd] != dist) continue;

        
        {
            // no mirror
            int dist_ = dist;
            if(arr[a][b] != 'A') dist_++;

            int nd = (cd + 2) % 4;
            int A = a + dir[nd].first, B = b + dir[nd].second;
            nd = (nd+2)%4;

            if(A == n-1 && B == m) {ans = min(ans, dist_);}
            else if(A == n || A == -1 || B == m || B == -1 || vis[A*m+B][nd] <= dist_) { }
            else{
                vis[A*m+B][nd] = dist_;
                pq.emplace(dist_, A*m+B, nd);
            }
        }

        {
            // mirror B
            int dist_ = dist;
            if(arr[a][b] != 'B') dist_++;

            int nd = (cd == 0 || cd == 2) ? (cd + 3) % 4 : (cd+1) % 4;
            int A = a + dir[nd].first, B = b + dir[nd].second;
            nd = (nd+2)%4;

            if(A == n-1 && B == m) ans = min(ans, dist_);
            else if(A == n || A == -1 || B == m || B == -1 || vis[A*m+B][nd] <= dist_) { }
            else{
                vis[A*m+B][nd] = dist_;
                pq.emplace(dist_, A*m+B, nd);
            }
        }

        {
            // mirror C
            int dist_ = dist;
            if(arr[a][b] != 'C') dist_++;

            int nd = (cd == 1 || cd == 3) ? (cd + 3) % 4 : (cd+1) % 4;
            int A = a + dir[nd].first, B = b + dir[nd].second;
            nd = (nd+2)%4;

            if(A == n-1 && B == m) ans = min(ans, dist_);
            else if(A == n || A == -1 || B == m || B == -1 || vis[A*m+B][nd] <= dist_) { }
            else{

                vis[A*m+B][nd] = dist_;
                pq.emplace(dist_, A*m+B, nd);
            }
        }

    }

    cout << ans << endl;

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