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
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1004669333, mod2 = 2147483647;

struct Seg{
    int n, m = 1;
    pair<pair<ll,ll>,int> neutral={{0LL,0LL},0};    //remember to change
    vector<pair<pair<ll,ll>,int>> tree, lazy;
    pair<pair<ll,ll>,int> join(const pair<pair<ll,ll>,int> &a, const pair<pair<ll,ll>,int> &b){     
        ll A = (a.f.f + b.f.f) % mod, B = (a.f.s + b.f.s) % mod2;
        int C = 0;
        if((a.s || b.s)) C = 1;
        return {{A,B},C};
    }
    Seg(int n, vector<pair<pair<ll,ll>,int>> ini = {}) : n(n) {
        while(m < n) m<<=1;

        tree.resize(2*m, neutral);
        lazy.resize(2*m, neutral);
    }
    void unlazy(int node, int l, int r){
        if(lazy[node] != pair<pair<ll,ll>,int>({{0LL,0LL},0})){
            pair<pair<ll,ll>,int> cc = lazy[node];
            int x = r-l+1;
            cc = {{cc.f.f*x % mod, cc.f.s*x % mod2}, cc.s};
            tree[node]=join(tree[node], cc); //remember to change
            if(tree[node].f.f || tree[node].f.s) tree[node].s = 1;
            else tree[node].s = 0;
            if(l!=r){
                lazy[2*node]=join(lazy[node], lazy[2*node]);
                lazy[2*node+1]=join(lazy[node], lazy[2*node+1]);
            }
            lazy[node]={{0LL,0LL},0};
        }
    }
    void upd(int node, int l, int r, int a, int b, const pair<pair<ll,ll>,int> &val){
        unlazy(node, l, r);
        if(a>r || b<l) return;
        if(l>=a && r<=b){
            lazy[node]=val;
            unlazy(node, l, r);
            if(l != r && (tree[node].s == 0 && (tree[2*node].s == 1 || tree[2*node+1].s == 1))){
                int mid=(l+r)>>1;
                upd(2*node, l, mid, a, b, neutral);
                upd(2*node+1, mid+1, r, a, b, neutral);  
                tree[node]=join(tree[2*node], tree[2*node+1]);
            }
            return;
        }
        int mid=(l+r)>>1;
        upd(2*node, l, mid, a, b, val);
        upd(2*node+1, mid+1, r, a, b, val);
        tree[node]=join(tree[2*node], tree[2*node+1]);
    }
    void upd(int l, int r, const pair<pair<ll,ll>,int> &val){
        upd(1, 1, m, l, r, val);
    }
};

signed solve(){
    
    int n; cin >> n;
    int q; cin >> q;

    Seg seg(2*n+5);

    vector<pair<ll,ll>> val(n, {0,0});

    uniform_int_distribution<int> uid(70, 1e9), uid2(70, 1e9);

    for(int i = 0; i < n; i++) {val[i].first = uid(rng); val[i].second = uid2(rng);}

    vector<vector<int>> graph(n);
    vector<int> dp(n, 1);
    vector<pair<ll,ll>> sum(n, {0LL,0LL});

    for(int i = 1; i < n; i++){
        int x; cin >> x; x--;
        graph[x].push_back(i);
    }

    function<void(int)> dfs;

    dfs = [&](int cc){
        sum[cc] = {(sum[cc].f + val[cc].f) % mod, (sum[cc].s + val[cc].s) % mod2};
        for(int j: graph[cc]){
            sum[j] = sum[cc];
            dfs(j);
            dp[cc] += dp[j];
        }
    };

    dfs(0);

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x; x--;
        arr[i] = x;

        seg.upd(i+1, i+dp[x], {{val[x].f, val[x].s}, 0});
        seg.upd(i+1, i+1, {{(-sum[x].f % mod + mod) % mod, (-sum[x].s % mod2 + mod2) % mod2}, 0});
    }

    for(int cz = 0; cz < q; cz++){
        int a,b; cin >> a >> b; a--; b--;
        int A = arr[a], B = arr[b];
        a++; b++;

        seg.upd(a, a+dp[A]-1, {{(-val[A].f % mod + mod) % mod, (-val[A].s % mod2 + mod2) % mod2}, 0});
        seg.upd(b, b+dp[B]-1, {{(-val[B].f % mod + mod) % mod, (-val[B].s % mod2 + mod2) % mod2}, 0});
        seg.upd(b, b+dp[A]-1, {{val[A].f, val[A].s}, 0});
        seg.upd(a, a+dp[B]-1, {{val[B].f, val[B].s}, 0});
        seg.upd(a, a, {{sum[A].f, sum[A].s}, 0});
        seg.upd(b, b, {{sum[B].f, sum[B].s}, 0});
        seg.upd(b, b, {{(-sum[A].f % mod + mod) % mod, (-sum[A].s % mod2 + mod2) % mod2}, 0});
        seg.upd(a, a, {{(-sum[B].f % mod + mod) % mod, (-sum[B].s % mod2 + mod2) % mod2}, 0});

        a--; b--;

        swap(arr[a], arr[b]);

        if(seg.tree[1].s != 0){
            cout << "NO\n";
        }
        else cout << "YES\n";
    }


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