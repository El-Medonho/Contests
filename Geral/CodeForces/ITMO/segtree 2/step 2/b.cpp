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

const ll mod = 1e9+7;

struct Seg{
    int n,m = 1;
    vector<ll> tree, lazy;

    ll join(const ll &a, const ll &b){
        return (a+b)%mod;
    }
    
    Seg(int n) : n(n) {
        while(m < n) m <<= 1;
        tree.resize(2*m, 1);
        lazy.resize(2*m, 1);
        for(int i = m-1; i > 0; i--) tree[i] = join(tree[2*i], tree[2*i+1]);
    }

    void unlazy(int node){
        tree[node] = tree[node]*lazy[node] % mod;
        if(node < m){
            lazy[2*node] = lazy[2*node]*lazy[node]%mod;
            lazy[2*node+1] = lazy[2*node+1]*lazy[node]%mod;
        }
        lazy[node] = 1;
    }

    void upd(int a, int b, int val, int node, int l, int r){
        if(lazy[node] != 1) unlazy(node);
        if(a > r || b < l) return;
        if(l >= a && r <= b){
            lazy[node] = val;
            unlazy(node);
            return;
        }
        int mid = (l+r)/2;
        upd(a,b,val,2*node,l,mid);
        upd(a,b,val,2*node+1,mid+1,r);
        tree[node] = join(tree[2*node], tree[2*node+1]);
    }

    int query(int pos, int node, int l, int r){
        if(pos > r || pos < l) 
            return 0;
        if(lazy[node] != 1) unlazy(node);
        if(l == r) 
            return tree[node];

        int mid = (l+r)/2;
        if(mid < pos) return query(pos, 2*node+1, mid+1, r);
        return query(pos, 2*node, l, mid);
    }

    int query(int a, int b, int node, int l, int r){
        if(a > r || b < l) 
            return 0;
        if(lazy[node] != 1) unlazy(node);
        if(l >= a && r <= b) 
            return tree[node];

        int mid = (l+r)/2;
        if(mid < a) return query(a, b, 2*node+1, mid+1, r);
        else if(mid+1 > b) return query(a, b, 2*node, l, mid);
        return join( query(a, b, 2*node, l, mid), query(a, b, 2*node+1, mid+1, r) );
    }

    void upd(int a, int b, ll val){
        upd(a,b,val,1,1,m);
    }

    int query(int pos){
        return query(pos,1,1,m);
    }

    int query(int l, int r){
        return query(l,r,1,1,m);
    }
};

signed solve(){

    int n,q; cin >> n >> q;

    Seg seg(n);

    while(q--){
        int op; cin >> op;

        if(op == 1){
            int l,r,v; cin >> l >> r >> v; l++;
            seg.upd(l,r,v,1,1,seg.m);
        }
        else {
            int l,r; cin >> l >> r; l++;
            cout << seg.query(l,r,1,1,seg.m) << endl;
        }
    }
    

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