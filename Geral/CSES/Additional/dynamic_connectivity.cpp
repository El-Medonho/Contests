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
    
    int n,M,k; cin >> n >> M >> k;

    vector<int> ans(k+1);
    int cans = n;

    vector<int> pai(n), peso(n, 1);

    for(int i = 0; i < n; i++) pai[i] = i;

    auto ff = [&](auto&& self, int x) -> int {
        if(pai[x] != x) x = self(self, pai[x]);
        return x;
    };

    stack<tuple<int,int,int>> stk;

    auto uu = [&](auto&& self, int x, int y) -> void {
        x = ff(ff,x), y = ff(ff,y);
        if(x == y) {
            stk.emplace(0,0,0);
            return;
        }


        if(peso[x] < peso[y]) swap(x, y);

        peso[x] += peso[y];
        stk.emplace(1, y, pai[y]);
        pai[y] = x;
        cans--;
    };

    auto rb = [&]() -> void {
        if(stk.size()){
            auto[v, y, p] = stk.top(); stk.pop();
            if(!v) return;
            peso[pai[y]] -= peso[y];
            pai[y] = p;
            cans++;
        }
    };

    int N = k+5;

    int m = 1;

    while(m <= N) m <<= 1;
    m <<= 1;

    vector<vector<pair<int,int>>> tree(m);

    auto upd = [&](auto&& self, int l, int r, pair<int,int> val, int a, int b, int node) -> void{
        if(b < l || a > r) return;
        if(a >= l && b <= r) {
            tree[node].push_back(val);
            return;
        }

        int mid = (a+b)/2;
        self(self, l, r, val, a, mid, node*2);
        self(self, l, r, val, mid+1, b, node*2+1);
    };

    for(int i = 0; i < n; i++) pai[i] = i;

    map<pair<int,int>, int> mp;

    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b; a--; b--;
        if(a > b) swap(a,b);
        mp[{a,b}] = 1;
    }

    for(int i = 1; i <= k; i++){
        int t, a, b; cin >> t >> a >> b; a--; b--;
        if(a > b) swap(a,b);
        if(t == 1){
            mp[{a,b}] = i+1;
        }
        else{
            upd(upd, mp[{a,b}], i, {a,b}, 1, m/2, 1);
            mp.erase({a,b});
        }
    }

    for(auto[a, b]: mp){
        upd(upd, b, k+1, a, 1, m/2, 1);
    }

    auto qw = [&](auto&& self, int l, int r, int node) -> void {
        for(auto[a,b]: tree[node]){
            uu(uu,a,b);
        }

        if(l == r && l-1 < ans.size()){
            ans[l-1] = cans;
        }
        else if(l != r){
            int mid = (l+r)/2;
            self(self,l,mid,node*2);
            self(self,mid+1,r,node*2+1);
        }

        for(int i = 0; i < tree[node].size(); i++) rb();
    };

    qw(qw, 1, m/2, 1);

    for(int i: ans) cout << i << ' ';
    cout << '\n';



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