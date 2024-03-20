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
    int n, m = 1;
    T neutral=0;    //remember to change
    vector<T> tree, sum, lazy;
    T join(const T &a, const T &b){     
        return (a+b);       //remember to change
    }
    Seg(int n, vector<T> ini = {}) : n(n) {
        while(m < n) m<<=1;

        tree.resize(2*m, neutral);
        sum.resize(2*m, neutral);
        lazy.resize(2*m, neutral);

        if(ini.size()){
            for(int i = m; i < m+ini.size(); i++) {tree[i] = ini[i-m]; sum[i] = ini[i-m] * (i-m+1);}
            for(int i = m-1; i > 0; i--) {tree[i] = join(tree[2*i], tree[2*i+1]); sum[i] = join(sum[2*i], sum[2*i+1]);}
        }
    }
    void unlazy(int node, ll l, ll r){
        if(lazy[node]){
            tree[node]+=(r-l+1)*lazy[node]; //remember to change
            sum[node]+= ((l + r) * (r-l+1) / 2) * lazy[node];
            if(l!=r){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }
    void upd(int node, int l, int r, int a, int b, const T &val){
        unlazy(node, l, r);
        if(a>r || b<l) return;
        if(l>=a && r<=b){
            lazy[node]+=val;
            unlazy(node, l, r);
            return;
        }
        int mid=(l+r)>>1;
        upd(2*node, l, mid, a, b, val);
        upd(2*node+1, mid+1, r, a, b, val);
        tree[node]=join(tree[2*node], tree[2*node+1]);
        sum[node]=join(sum[2*node], sum[2*node+1]);
    }
    T query(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return neutral; //remember to change
        if(a<=l && b>=r) return tree[node];
        
        int mid=(l+r)>>1;
        if(mid < a) return query(2*node+1,mid+1,r,a,b);
        if(mid+1 > b) return query(2*node,l,mid,a,b);
        
        return join(query(2*node, l, mid, a, b),
        query(2*node+1, mid+1, r, a, b));
    }
    T query2(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return neutral; //remember to change
        if(a<=l && b>=r) return sum[node];
        
        int mid=(l+r)>>1;
        if(mid < a) return query2(2*node+1,mid+1,r,a,b);
        if(mid+1 > b) return query2(2*node,l,mid,a,b);
        
        return join(query2(2*node, l, mid, a, b),
        query2(2*node+1, mid+1, r, a, b));
    }
    void upd(int l, int r, const T &val){
        upd(1, 1, m, l, r, val);
    }
    T query(int l, int r){
        return query2(1, 1, m, l, r) - (l-1) * query(1, 1, m, l, r);
    }
};

signed solve(){

    int n,q; cin >> n >> q;

    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    Seg<ll> seg(n, arr);
    
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l,r,d; cin >> l >> r >> d;
            seg.upd(l,r,d);
        }
        else{
            int l,r; cin >> l >> r;
            cout << seg.query(l,r) << endl;
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