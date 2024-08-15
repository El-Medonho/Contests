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

const int mx = 1e3;

vector<int> pai(0), peso(0);

int ff(int x){
    if(pai[x]==x) return x;
    return pai[x]=ff(pai[x]);
}

void uu(int x, int y){
    x=ff(x), y=ff(y);
    if(x==y) return;
    if(peso[y]>peso[x]) swap(x, y);
    pai[y]=x;
    peso[x]+=peso[y];
}

void init(int n){
    pai.resize(n); peso.resize(n);
    for(int i=0; i<n; i++){
        pai[i]=i;
        peso[i]=1;
    }
}

signed solve(){
    
    int n; cin >> n;

    int m; cin >> m;

    init(n);

    vector<vector<int>> table(n, vector<int>(n, mx));

    while(m--){
        int a,b; cin >> a >> b; a--; b--;

        // if(ff(a) == ff(b)) continue;

        uu(a, b);
        int c; cin >> c;

        table[a][b] = -c;
        table[b][a] = c;
    }

    vector<int> mp1(n, 0), mp(n, -1);

    for(int i = 0; i < n; i++) mp1[ff(i)]++;

    int c1 = 0;

    for(int i = 0; i < n; i++) c1 += mp1[ff(i)] == 1;

    vector<int> ans(n, -1);
    vector<int> rev(0);
    int N = 0;

    for(int i = 0; i < n; i++){
        if(mp1[i] >= 1){
            if(mp1[i] > 1 || c1 < 2) {
                if(mp1[i] == 1) continue;
                mp[i] = N++;
                rev.push_back(i);
            }
            else ans[i] = -2;
        }
    }

    for(int k = 0; k < n; k++){
        table[k][k] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(table[i][k] != mx && table[k][j] != mx)
                    table[i][j] = table[i][k] + table[k][j];
            }
        }
    }

    vector<vector<pair<int,int>>> graph(n);

    for(int i: rev){
        for(int j = 0; j < n; j++){
            if(table[i][j] != mx) graph[i].push_back({j, table[i][j]});
        }
    }

    vector<int> con(0);

    function<void()>  ch;

    ch = [&](){

        // for(int i: con) cout << i << ' ';
        // cout << endl;

        do{
            vector<int> repr(n, -1), occ(n, 0);

            bool ok = true;

            for(int i = 0; i < N && ok; i++){
                int cc = rev[i];

                for(auto [j, x]: graph[cc]){
                    int nw = con[i] + x;
                    if(nw < 0 || nw >= n || occ[nw]){
                        ok = false;
                        break;
                    }

                    occ[nw]++;
                    repr[j] = nw;
                }
            }

            if(!ok) continue;

            for(int i = 0; i < n; i++){
                if(ans[i] == -2) continue;

                if(repr[i] == -1 && c1 == 1){
                    for(int j = 0; j < n; j++){
                        if(occ[j] == 0){
                            occ[j]++;
                            repr[i] = j;
                            break;
                        }
                    }
                }

                if(ans[i] != -1 && ans[i] != repr[i]) ans[i] = -2;
                else ans[i] = repr[i];
            }
        }

        while(next_permutation(con.begin(), con.end()));
    };
    
    function<void(int)> ins;

    ins = [&](int l){
        if(con.size() == N) {ch(); return;}

        for(int i = l; i + (N - con.size() - 1) < n; i++){
            con.push_back(i);
            ins(i+1);
            con.pop_back();
        }
        return;
    };

    ins(0);

    for(int i = 0; i < n; i++){
        if(ans[i] == -1) ans[i] = -2;
        cout << ans[i] + 1 << ' ';
    }

    cout << endl;

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