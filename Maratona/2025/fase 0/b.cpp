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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7, mod2 = 1e9+9;
const ll inf = 1e18+5;

ll expo(ll b, ll e, ll m){
    ll resp = 1;
    while(e){
        if(e&1) resp=resp*b%m;
        b=b*b%m;
        e>>=1;
    }
    return resp;
}

signed solve(){

    int n; cin >> n;

    vector<vector<pair<int,char>>> graph(n);

    vector<int> inp(n-1); string ih; 
    for(int &i: inp) cin >> i;
    cin >> ih; 

    vector<vector<int>> bl(22, vector<int>(n, -1));
    for(int i = 1; i < n; i++){
        int a = inp[i-1]; a--; char c = ih[i-1];
        graph[a].emplace_back(i, c);
        bl[0][i] = a;
    }

    vector<ll> hash(n, 0LL);

    string s = "";

    pair<ll,ll> sum = {0LL, 0LL};

    vector<pair<ll,ll>> val(n, {0LL,0LL});
    vector<int> lv(n, 0);

    function<void(int, pair<ll,ll>, int)> dfs = [&](int cc, pair<ll,ll> p = {1LL, 1LL}, int lvl = 0){
        auto old = sum;
        lv[cc] = lvl;
        for(auto[j, c]: graph[cc]){
            sum.first += (c-'a'+1)*p.first; sum.second += (c-'a'+1)*p.second;
            sum = {sum.first%mod, sum.second%mod2};
            val[j] = sum;

            dfs(j, make_pair(p.first*31%mod, p.second*31%mod2), lvl+1);

            sum = old;
        }
    };

    dfs(0, make_pair(1ll, 1ll), 0);


    for(int i = 1; i < 22; i++){
        for(int j = 0; j < n; j++){
            if(bl[i-1][j] != -1) bl[i][j] = bl[i-1][bl[i-1][j]];
        }
    }

    vector<ll> invp1(1e5+5, 1), invp2(1e5+5, 1);

    invp1[1] = expo(31, mod-2, mod);

    for(int i = 2; i < 1e5+5; i++) invp1[i] = invp1[i-1] * invp1[1] % mod;

    invp2[1] = expo(31, mod2-2, mod2);

    for(int i = 2; i < 1e5+5; i++) invp2[i] = invp2[i-1] * invp2[1] % mod2;

    vector<vector<int>> div(n+1);


    for(int i = 1; i <= n; i++){
        if(div[i].size() >= 2) continue;
        for(int j = i; j <= n; j+=i){
            div[j].push_back(i);
        }
    }

    vector<map<int,pair<ll,ll>>> pi(n);
    vector<int> eres(n, 0);

    int ans = 0;

    function<void(int)> dfs2 = [&](int cc){
        auto old = sum;

        int cl = lv[cc];

        bool ok = false;

        pi[cc][cl] = val[cc];
        ll num = 1;

        for(int j: div[cl]){

            if(j == cl) continue;

            j = cl/j;
    
            int hi = cl-j;
    
            int nxt = cc;
            for(int i = 20; i > -1; i--){
                if( (j & (1<<i)) == 0 ||bl[i][nxt] == -1) continue;
                nxt = bl[i][nxt];
            }

    
            pair<ll,ll> xsum = {val[cc].first - val[nxt].first, val[cc].second - val[nxt].second};
            xsum = {(xsum.first + mod) % mod, (xsum.second + mod2) % mod2};
            xsum = {xsum.first * invp1[hi] % mod, xsum.second * invp2[hi] % mod2 };
    
            if(pi[nxt].find(j) != pi[nxt].end() && pi[nxt][j] == xsum){
                if(ok == false){
                    ok = true;
                    ans = max(ans, j);
                    eres[cc] = 1;
                }
                pi[cc][j] = xsum;
            }
        }


        for(auto[j, c]: graph[cc]){
            dfs2(j);
        }
    };

    dfs2(0);

    cout << ans << endl;


    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}