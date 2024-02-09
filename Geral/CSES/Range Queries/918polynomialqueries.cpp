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

struct Seg{
    vector<ll> tree, pre, sz;
    int n, m = 1;

    ll join(const ll &a, const ll &b){
        return a+b;
    }

    void unlazy(int node, int l, int r){
        tree[node] += sz[node]*(1 + (r-l+1))*(r-l+1)/2;
        tree[node] += pre[node] * (r-l+1);

        if(node < m){
            int i = 2*node, mid = (l+r)/2;
            pre[i] += pre[node];
            sz[i] += sz[node];

            i = 2*node+1;
            pre[i] += pre[node] + (mid-l+1) * sz[node];
            sz[i] += sz[node];
        }

        pre[node] = 0; sz[node] = 0;
    }

    Seg(int n, vector<int> arr) : n(n) {
        while(m < n) m <<= 1;
        tree.resize(2*m, 0);
        pre.resize(2*m, 0);
        sz.resize(2*m, 0);

        for(int i = m; i < n+m; i++) tree[i] = arr[i-m];
        for(int i = m-1; i > 0; i--) tree[i] = join(tree[2*i], tree[2*i+1]);
    }

    void upd(int a, int b, int node, int l, int r){
        if(sz[node] != 0) unlazy(node,l,r);
        if(l > b || r < a) return;
        if(l >= a && r <= b){
            pre[node]+=(l-a);
            sz[node]++;
            unlazy(node,l,r);
            return;
        }

        int mid = (l+r)/2;
        upd(a,b,2*node,l,mid);
        upd(a,b,2*node+1,mid+1,r);
        tree[node] = join(tree[2*node], tree[2*node+1]);
    }

    ll query(int a, int b, int node, int l, int r){
        if(sz[node] != 0) 
            unlazy(node,l,r);
        if(l > b || r < a) return 0;
        if(l >= a && r <= b){
            return tree[node];
        }
        int mid = (l+r)/2;
        if(mid < a) return query(a,b,2*node+1,mid+1,r);
        else if(mid+1 > b) return query(a,b,2*node,l,mid);
        return join(query(a,b,2*node,l,mid), query(a,b,2*node+1,mid+1,r));
    }
};

signed solve(){

    int n,q; cin >> n >> q;
    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    Seg seg(n, arr);

    while(q--){
        int op; cin >> op; op--;
        int l,r; cin >> l >> r;
        if(op){
            cout << seg.query(l,r,1,1,seg.m) << endl;
        }
        else{
            seg.upd(l,r,1,1,seg.m);
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