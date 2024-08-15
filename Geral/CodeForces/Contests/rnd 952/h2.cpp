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
    
    int N,M; cin >> N >> M;

    vector<string> arr(N);

    for(string &i: arr) cin >> i;

    int n = N*M;

    vector<int> pai(n), peso(n, 1);
    for(int i = 0; i < n; i++){
        pai[i] = i;
    }

    function<int(int)> ff;

    ff = [&](int x){
        if(pai[x]==x) return x;
        return pai[x]=ff(pai[x]);
    };

    function<void(int,int)> uu;

    uu = [&](int x, int y){
        x=ff(x), y=ff(y);
        if(x==y) return;
        if(peso[y]>peso[x]) swap(x, y);
        pai[y]=x;
        peso[x]+=peso[y];
    };

    vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    vector<vector<int>> Ns(N), Ms(M);
    vector<int> qN(N,0), qM(M,0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            if(arr[i][j] != '#') continue;

            for(auto[xn, yn]: dir){
                int x = i+xn, y = j+yn;

                if(x < 0 || x >= N || y < 0 || y >= M || arr[x][y] != '#') continue;

                uu(i*M+j, x*M+y);
            }

            Ns[i].push_back(i*M+j);
            Ms[j].push_back(i*M+j);
        }
    }

    int mx = *max_element(peso.begin(), peso.end());

    for(int i = 0; i < N; i++){

        int cc = 0;
        map<int,int> mp;

        if(i > 0){
            for(int x: Ns[i-1]) mp[ff(x)]++;
        }

        cc += M - Ns[i].size();

        for(int x: Ns[i]) mp[ff(x)]++;

        if(i < N-1){
            for(int x: Ns[i+1]) mp[ff(x)]++;
        }

        for(auto[x,a]: mp) if(a) cc += peso[x];

        for(int j = 0; j < M; j++){

            int cc2 = cc;

            if(j > 0){
                for(int x: Ms[j-1]) {
                    int h = ff(x);
                    if(mp[h] == 0) cc2 += peso[h];
                    mp[h]++;
                }
            }

            cc2 += N - Ms[j].size();

            for(int x: Ms[j]) {
                int h = ff(x);
                if(mp[h] == 0) cc2 += peso[h];
                mp[h]++;
            }

            if(j < M-1){
                for(int x: Ms[j+1]) {
                    int h = ff(x);
                    if(mp[h] == 0) cc2 += peso[h];
                    mp[h]++;
                }
            }
            
            if(arr[i][j] == '.') cc2--;

            mx = max(mx, cc2);

            if(j > 0){
                for(int x: Ms[j-1]) {
                    int h = ff(x);
                    mp[h]--;
                    if(mp[h] == 0) mp.erase(h);
                }
            }

            cc2 += N - Ms[j].size();

            for(int x: Ms[j]) {
                int h = ff(x);
                mp[h]--;
                if(mp[h] == 0) mp.erase(h);
            }

            if(j < M-1){
                for(int x: Ms[j+1]) {
                    int h = ff(x);
                    mp[h]--;
                    if(mp[h] == 0) mp.erase(h);
                }
            }
        }


    }

    cout << mx << endl;


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