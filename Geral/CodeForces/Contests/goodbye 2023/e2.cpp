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

template <class T> struct Seg{
    int n; T neutral=0;
    vector<T> tree, lazy;
    Seg(int n) : n(n), tree(4*(n+1), 0), lazy(4*(n+1), 0) {}
    T join(T a, T b){
        return max(a,b);
    }
    void unlazy(int node, int l, int r){
        if(lazy[node]){
            tree[node]+=lazy[node]; //remember to change
            if(l!=r){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }
    void upd(int node, int l, int r, int pos, T val){
        if(l==r){
            tree[node]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid){
            upd(2*node, l, mid, pos, val);
        }else{
            upd(2*node+1, mid+1, r, pos, val);
        }
        tree[node]=join(tree[2*node], tree[2*node+1]);
    }
    void upd(int node, int l, int r, int a, int b, T val){
        unlazy(node, l, r);
        if(a>r || b<l) return;
        if(l>=a && r<=b){
            lazy[node]=val;
            unlazy(node, l, r);
            return;
        }
        int mid=(l+r)>>1;
        upd(2*node, l, mid, a, b, val);
        upd(2*node+1, mid+1, r, a, b, val);
        tree[node]=join(tree[2*node], tree[2*node+1]);
    }
    T query(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return neutral; //remember to change
        if(a<=l && b>=r) return tree[node];
        int mid=(l+r)>>1;
        return join(query(2*node, l, mid, a, b),
        query(2*node+1, mid+1, r, a, b));
    }
    int upper(int node, int l, int r, int a, int b, T val){
        if(a>r || b<l) return -1;
        if(l>=a && r<=b){
            if(tree[node]<=val) return -1;
            while(l!=r){
                int mid = (l+r)>>1;
                if(tree[2*node]>val){
                    node=2*node;
                    r=mid;
                }else{
                    node=2*node+1;
                    l=mid+1;
                }
            }
            return l;
        }
        int mid=(l+r)>>1;
        int ans = upper(2*node, l, mid, a, b, val);
        if(ans!=-1) return ans;
        return upper(2*node+1, mid+1, r, a, b, val);
    }
    void upd(int pos, T val){
        upd(1, 1, n, pos, val);
    }
    void upd(int l, int r, T val){
        upd(1, 1, n, l, r, val);
    }
    T query(int l, int r){
        return query(1, 1, n, l, r);
    }
    int upper(int l, int r, T val){
    //primeira posição com valor > que val
        return upper(1, 1, n, l, r, val);
    }
};

signed solve(){

    int n; cin >> n;
    vector<set<int>> memo(n);

    vector<vector<int>> graph(n);
    vector<int> par(n), filhos(n, 0);
    for(int i = 1; i < n; i++){
        int x; cin >> x; x--;
        graph[x].push_back(i);
        par[i] = x;
        filhos[x]++;
    }

    vector<int> cor(n);
    for(int &i: cor) cin >> i;

    // queue<int> qw; 

    // for(int i = 0; i < n; i++) if(graph[i].size() == 0) qw.push(i);


    vector<int> in(n+2), out(n+2);
    int cnt = 1;

    function<void(int)> dfs, dfs2;

    dfs = [&](int cc){
        in[cc] = cnt++;

        for(int j: graph[cc]) dfs(j);

        out[cc] = cnt++;
    };

    dfs(0);
    Seg<ll> seg(cnt+2);

    ll ans = 1;

    vector<vector<pair<int,int>>> caracor(n+2);

    int tempo = 1;

    dfs2 = [&](int cc){

        int og = tempo++;
        int acor = cor[cc];

        for(int j: graph[cc]) dfs2(j);

        seg.upd(in[cc], out[cc], 1);
        while(!caracor[acor].empty()){
            auto [tem, h] = caracor[acor].back();
            if(tem <= og) break;
            caracor[acor].pop_back();
            seg.upd(in[h], out[h], -1);
        }

        ll best = 1;
        for(int j: graph[cc]){
            ll res = seg.query(in[j], out[j]);
            ans = max(ans, best * res);
            best = max(best, res);
        }
        caracor[acor].push_back({tempo, cc});
    };

    dfs2(0);

    cout << ans << endl;

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