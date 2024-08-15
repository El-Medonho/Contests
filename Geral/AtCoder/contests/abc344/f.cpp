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

const ll inf = 1e18+500;

const int mod = 1e9+7;

signed solve(){
    
    int n; cin >> n;

    vector<vector<ll>> p(n, vector<ll>(n)), r(n, vector<ll>(n-1)), d(n-1, vector<ll>(n));
    set<int> st;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> p[i][j];
            st.insert(p[i][j]);
        }
    }

    vector<ll> arr(0); arr.reserve(st.size());
    map<ll,int> mp;

    for(int i: st){
        arr.push_back(i);
        mp[i] = arr.size()-1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            p[i][j] = mp[p[i][j]];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            cin >> r[i][j];
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            cin >> d[i][j];
        }
    }

    int m = st.size();

    vector<vector<pair<ll,ll>>> dp(n*n, vector<pair<ll,ll>>(m, make_pair(inf, 0LL)));

    dp[0][p[0][0]] = {0,0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int k = p[i][j];
            int cc = i*n + j;

            for(int a = 0; a < k; a++) dp[cc][k] = min(dp[cc][k], dp[cc][a]);

            if(i < n-1){
                //down


                for(int a = k; a < m; a++){
                    
                    ll tg = d[i][j];
                    if(dp[cc][a].first >= inf) continue;

                    ll ac = arr[a];
                    ll x = -dp[cc][a].second;

                    if(x >= tg){
                        dp[cc+n][a] = min(dp[cc+n][a], {dp[cc][a].first + 1, - (x-tg)});
                    }
                    else{

                        tg -= x;

                        ll nw = (tg + ac - 1) / ac;
                        ll r =  ac * nw - tg;
                        
                        nw++;

                        dp[cc+n][a] = min(dp[cc+n][a], {dp[cc][a].first + nw, -r});
                    }
                }
            }

            if(j < n-1){
                //right


                for(int a = k; a < m; a++){
                    ll tg = r[i][j];
                    if(dp[cc][a].first >= inf) continue;

                    ll ac = arr[a];
                    ll x = -dp[cc][a].second;

                    if(x >= tg){
                        dp[cc+1][a] = min(dp[cc+1][a], {dp[cc][a].first + 1, - (x-tg)});
                    }
                    else{
                        tg -= x;

                        ll nw = (tg + ac - 1) / ac;
                        ll r =  ac * nw - tg;
                        
                        nw++;

                        dp[cc+1][a] = min(dp[cc+1][a], {dp[cc][a].first + nw, -r});
                    }
                }
            }
        }
    }

    ll ans = 1e18;

    for(int i = 0; i < m; i++){
        ans = min(ans, dp[n*n-1][i].first);
    }

    cout << ans << endl;

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