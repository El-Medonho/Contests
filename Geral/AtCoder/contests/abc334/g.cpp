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

const int mod = 998244353;

ll expo(ll b, ll e){
    ll resp = 1;

    while(e){
        if(e&1) resp = (resp*b) % mod;
        b = (b*b) % mod;
        e>>=1;
    }

    return resp;
}

signed solve(){
    
    int n,m; cin >> n >> m;

    vector<string> grid(n);

    for(string &i: grid) cin >> i;

    int cnt = 0;

    ll sub = 0;

    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    ll ans = 0;

    vector<int> mp(n*m+1, 0);

    int k = n*m;

    vector<int> pai(k), peso(k, 1);

    for(int i = 0; i < k; i++) pai[i] = i;

    function<int(int)> ff;

    ff = [&](int x){
        if(pai[x] == x) return x;
        return pai[x] = ff(pai[x]);
    };

    function<void(int,int)> uu;

    uu = [&](int x, int y){
        x = ff(x); y = ff(y);

        if(x == y) return;

        if(peso[x] > peso[y]) swap(x,y);

        pai[x] = y;
        peso[y] += peso[x];

        return;
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#'){
                for(auto [xn, yn]: dir){
                    int in = i + xn, jn = j + yn;

                    if(in < 0 || in >= n || jn < 0 || jn >= m || grid[in][jn] != '#') continue;

                    uu(i*m + j, in * m + jn);
                }
            }
        }
    }

    set<int> bs;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#') bs.insert(ff(i*m + j));
        }
    }

    int base = bs.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != '#') continue;

            sub++;
            int qtt = 0;

            for(auto[xn, yn]: dir){
                int x = i+xn, y = j+yn;

                if(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] != '#') continue;

                qtt++;
            }   

            mp[i*m+j] = cnt++;
        }
    }

    vector<vector<int>> graph(cnt);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != '#') continue;

            for(auto[xn, yn]: dir){
                int x = i+xn, y = j+yn;

                if(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] != '#') continue;

                graph[mp[i*m+j]].push_back(mp[x*m+y]);
            }   
        }
    }

    n = cnt;

    function<void(int,int)> dfs;

    int cont = 0;

    vector<int> tin(n, 0), low(n, 0), artic(n, 0), memo(n, 0);

    vector<pair<int,int>> bridges(0);

    dfs = [&](int x, int p) {
        memo[x] = 1;
        tin[x] = low[x] = ++cont;
        int children = 0;
        for (int i : graph[x]) {
            if (i == p) continue;
            if (memo[i]) {
                low[x] = min(low[x], tin[i]);
            } else {
                dfs(i, x);
                low[x] = min(low[x], low[i]);
                if (low[i] > tin[x]) {
                    bridges.push_back({min(i, x), max(i, x)});
                }
                if (low[i] >= tin[x] && p != -1) artic[x]++;
                children++;
            }
        }
        if (p == -1) artic[x] = children-1;
    };

    function<void()> build;

    build = [&]() {
        cont = 0;
        bridges.clear();
        for (int i = 0; i < n; i++) {
            memo[i] = low[i] = tin[i] = artic[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if(!memo[i]) dfs(i, -1);
        }
    };

    build();

    vector<vector<int>> bd(n);

    for(auto [a,b]: bridges){
        bd[a].push_back(b);
        bd[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        ll cc = artic[i];

        ans += base + cc;
    }

    ans %= mod;

    sub %= mod;

    sub = expo(sub, mod-2);

    ans = ans * sub % mod;

    ans = (ans + mod) % mod;

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