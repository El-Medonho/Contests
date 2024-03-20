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
    pair<int,int> neutral={1e9,-1e9}, neutral2 = {-1e9, 1e9};    //remember to change
    vector<pair<int,int>> tree, lazy;
    void join(int node){     
        int a = 2*node, b = 2*node+1;

        tree[node] = {min(tree[a].first, tree[b].first), max(tree[a].second, tree[b].second)};
    }
    Seg(int n, vector<T> ini = {}) : n(n) {
        while(m < n) m<<=1;

        tree.resize(2*m, {0,0});
        lazy.resize(2*m, neutral2);
    }
    void unlazy(int node, int l, int r){
        if(lazy[node] != neutral2){
            tree[node].first=max(tree[node].first, lazy[node].first); //remember to change
            tree[node].second=max(tree[node].second, lazy[node].first); //remember to change
            tree[node].second=min(tree[node].second, lazy[node].second);
            tree[node].first=min(tree[node].first, lazy[node].second);

            if(l!=r){
                
                lazy[2*node] = {max(lazy[2*node].first, lazy[node].first), max(lazy[2*node].second, lazy[node].first)};
                lazy[2*node+1] = {max(lazy[2*node+1].first, lazy[node].first), max(lazy[2*node+1].second, lazy[node].first)};

                lazy[2*node] = {min(lazy[2*node].first, lazy[node].second), min(lazy[2*node].second, lazy[node].second)};
                lazy[2*node+1] = {min(lazy[2*node+1].first, lazy[node].second), min(lazy[2*node+1].second, lazy[node].second)};
            }
            lazy[node]=neutral2;
        }
    }
    void upd(int node, int l, int r, int a, int b, const T &val){
        unlazy(node, l, r);
        if(a>r || b<l) return;
        if(l>=a && r<=b){
            lazy[node].first=val;
            unlazy(node, l, r);
            return;
        }
        int mid=(l+r)>>1;
        upd(2*node, l, mid, a, b, val);
        upd(2*node+1, mid+1, r, a, b, val);
        join(node);
    }
    void upd2(int node, int l, int r, int a, int b, const T &val){
        unlazy(node, l, r);
        if(a>r || b<l) return;
        if(l>=a && r<=b){
            lazy[node].second=val;
            unlazy(node, l, r);
            return;
        }
        int mid=(l+r)>>1;
        upd2(2*node, l, mid, a, b, val);
        upd2(2*node+1, mid+1, r, a, b, val);
        join(node);
    }
    T query(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return 0; //remember to change
        if(a<=l && b>=r) return tree[node].first;
        
        int mid=(l+r)>>1;
        if(mid < a) return query(2*node+1,mid+1,r,a,b);
        if(mid+1 > b) return query(2*node,l,mid,a,b);
        
        // return join(query(2*node, l, mid, a, b),
        // query(2*node+1, mid+1, r, a, b));

        return -1;
    }
    int upper(int node, int l, int r, int a, int b, const T &val){
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
    void upd(int l, int r, const T &val){
        upd(1, 1, m, l, r, val);
    }
    void upd2(int l, int r, const T &val){
        upd2(1, 1, m, l, r, val);
    }
    T query(int l, int r){
        return query(1, 1, m, l, r);
    }
    int upper(int l, int r, const T  &val){
    //primeira posição com valor > que val
        return upper(1, 1, m, l, r, val);
    }
};

signed solve(){

    int n,q; cin >> n >> q;

    Seg<int> seg(n);

    while(q--){
        int op; cin >> op;
        int l,r,k; cin >> l >> r >> k; l++; r++;

        if(op == 1){
            seg.upd(l,r,k);
        }
        else seg.upd2(l,r,k);
    }

    for(int i = 1; i <= n; i++){
        cout << seg.query(i,i) << endl;
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