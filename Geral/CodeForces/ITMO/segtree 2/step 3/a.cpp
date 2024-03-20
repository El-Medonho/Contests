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
    T diff = 1e18;
    vector<T> tree, lazy, pre, suf, tot;
    void join(int i){     
        tree[i] = max(tree[2*i], max(tree[2*i+1], suf[2*i]+pre[2*i+1]));

        pre[i] = max(pre[2*i], tot[2*i] + pre[2*i+1]);

        suf[i] = max(suf[2*i+1], tot[2*i+1] + suf[2*i]);

        tot[i] = tot[2*i] + tot[2*i+1];
    }

    pair<pair<ll,ll>, pair<ll,ll>> join2(pair<pair<ll,ll>, pair<ll,ll>> a, pair<pair<ll,ll>, pair<ll,ll>> b){
        pair<pair<ll,ll>, pair<ll,ll>> ans = {{0,0},{0,0}};

        ans.first.first = a.first.first + b.first.first;

        ans.first.second = max(a.first.second, max(b.first.second, a.second.second + b.second.first));

        ans.second.first = max(a.second.first, a.first.first + b.second.first);

        ans.second.second = max(b.second.second, b.first.first + a.second.second);

        return ans;
    }

    Seg(int n, vector<T> ini = {}) : n(n) {
        while(m < n) m<<=1;

        tree.resize(2*m, neutral);
        pre.resize(2*m, neutral);
        suf.resize(2*m, neutral);
        tot.resize(2*m, neutral);
        lazy.resize(2*m, diff);


        // for(int i = m; i < m+ini.size(); i++) {tree[i] = 0; pre[i] = 0; suf[i] = 0;}
        // for(int i = m-1; i > 0; i--) join(i);
    }
    void unlazy(int node, int l, int r){
        if(lazy[node] != diff){
            
            tot[node] = (r-l+1)*lazy[node];
            tree[node]=max(tot[node], 0LL); //remember to change
            pre[node] = tree[node];
            suf[node] = tree[node];
            
            if(l!=r){
                lazy[2*node]=lazy[node];
                lazy[2*node+1]=lazy[node];
            }
            
            lazy[node]=diff;
        }
    }
    void upd(int node, int l, int r, int a, int b, const T &val){
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
        join(node);
    }
    pair<pair<ll,ll>, pair<ll,ll>> query(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return {{0,0},{0,0}}; //remember to change
        if(a<=l && b>=r) return {{tot[node],tree[node]}, {pre[node], suf[node]}};
        
        int mid=(l+r)>>1;
        if(mid < a) return query(2*node+1,mid+1,r,a,b);
        if(mid+1 > b) return query(2*node,l,mid,a,b);
        
        return join2(query(2*node, l, mid, a, b),
        query(2*node+1, mid+1, r, a, b));
    }
    void upd(int l, int r, const T &val){
        upd(1, 1, m, l, r, val);
    }
    pair<pair<ll,ll>, pair<ll,ll>> query(int l, int r){
        return query(1, 1, m, l, r);
    }
    int upper(int l, int r, const T  &val){
    //primeira posição com valor > que val
        return upper(1, 1, m, l, r, val);
    }
};

signed solve(){

    int n,q; cin >> n >> q;

    Seg<ll> seg(n);

    while(q--){
        // int op; cin >> op;
        int l,r; cin >> l >> r; l++;

        int v; cin >> v;

        seg.upd(l,r,v);
    
    
        cout << seg.query(1,n).first.second << endl;
    
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