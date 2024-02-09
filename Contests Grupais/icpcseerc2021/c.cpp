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

const ll md = 998244353;

signed solve(){

    int n; cin >> n;
    vector<int> cor(n);
    for(int &i: cor) cin >> i;

    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // dp[cara][cor][saldo]
    int cnt = 0;

{    set<int> uni_cores;
    for(int i: cor) uni_cores.insert(i);

    vector<int> rel(n+5, -1);
    for(int i: uni_cores){
        rel[i] = cnt++;
    }

    for(int i = 0; i < n; i++){
        cor[i] = rel[cor[i]];
    }   }

    vector<int> resto(cnt, 0);
    for(int i = 0; i < n; i++){
        resto[cor[i]]++;
    }

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(cnt));

    vector<vector<int>> zero(n, vector<int>(cnt, 0)), maxi(n, vector<int>(cnt, 0)), mini(n, vector<int>(cnt, 0));
    
    ll ans = 0;

    function<void(int,int)> dfs;

    dfs = [&](int cc, int last){

        for(int j: graph[cc]){
            if(j == last) continue;
            dfs(j, cc);
        }

        for(int c = 0; c < cnt; c++){
            int sz = 0;
            int isz = 0;
            for(int j: graph[cc]){
                sz += maxi[j][c];
                isz += mini[j][c];
            }

            if(c == cor[cc]) {sz++; resto[c]--;}
            else isz++;

            maxi[cc][c] = max(maxi[cc][c], sz);
            mini[cc][c] = min(mini[cc][c], isz);

            zero[cc][c] = min(resto[c], isz);
            int r = 0,l = 0;

            dp[cc][c].resize(zero[cc][c] + maxi[cc][c] + 1, 0);

            if(c == cor[cc]){
                dp[cc][c][zero[cc][c]+1] = 1; r = 1;
            }

            else{
                dp[cc][c][zero[cc][c]-1] = 1; l = -1;    
            }

            for(int j: graph[cc]){
                for(int k = dp[j][c].size()-1; k > -1; k--){
                    int ll = l, rr = r;
                    int ind1 = k - zero[j][c];
                    for(int kk = r; kk >= l; kk--){
                        int ind2 = kk;
                        
                        int tot = ind2+ind1;
                        if(tot > maxi[cc][c] || tot < -mini[cc][c]) continue;
                        ll = min(tot, l);
                        rr = max(r, tot);

                        tot += zero[cc][c]; ind2 += zero[cc][c]; ind1 += zero[j][c];

                        if(tot >= dp[cc][c].size() || tot < 0){
                            cout << "h\n";
                            return;
                        } //?

                        if(ind2 >= dp[cc][c].size() || ind2 < 0){
                            cout << "h\n";
                            return;
                        }

                        dp[cc][c][tot] = ( dp[cc][c][tot] + (dp[j][c][ind1] * dp[cc][c][ind2] % md) ) % md;
                    }
                    l = ll; r = rr;
                }
            }
        }

        for(int c = 0; c < cnt; c++){
            for(int i = zero[cc][c]+1; i < dp[cc][c].size(); i++) ans = (ans + dp[cc][c][i]) % md;
        }

    };

    dfs(0,0);

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