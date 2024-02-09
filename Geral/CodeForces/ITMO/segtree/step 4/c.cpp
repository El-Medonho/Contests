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

ll ans = 0;

struct Seg{
    int n, m;
    vector<vector<int>> tree;
    vector<ll> val;

    vector<int> join(const vector<int> &a, const vector<int> &b, const int node){
        vector<int> base(41, 0);
        ll sum = 0;
        ll cc = 0;
        for(int i = 40; i > -1; i--) {
            base[i] += a[i] + b[i];
            cc += sum * b[i];
            ans += sum * b[i];
            sum += a[i];
        }
        val[node] = cc; 
        val[node] += val[2*node] + val[2*node+1];
        return base;
    }

    vector<int> join2(const vector<int> &a, const vector<int> &b){
        vector<int> base(41, 0);
        ll sum = 0;
        ll cc = 0;
        for(int i = 40; i > -1; i--) {
            base[i] += a[i] + b[i];
            ans += sum * b[i];
            sum += a[i];
        }
        return base;
    }

    Seg(int n, vector<vector<int>> &arr) : n(n) {
        m = 1;
        while(m < n) m<<=1;

        tree.resize(2*m, vector<int>(41,0));
        val.resize(2*m, 0);
        for(int i = m; i < n+m; i++) tree[i] = arr[i-m];

        for(int i = m-1; i > 0; i--) tree[i] = join(tree[2*i], tree[2*i+1], i);
    }

    void upd(int pos, int val, int node, int l, int r){
        if(l > pos || r < pos) return;
        if(l == r){
            tree[node] = vector<int>(41, 0);
            tree[node][val]++;
            return;
        }
        int mid = (l+r)/2;
        if(mid >= pos) upd(pos, val, node*2, l, mid);
        else upd(pos, val, node*2+1, mid+1, r);
        tree[node] = join(tree[2*node], tree[2*node+1], node);
        return;
    }

    vector<int> query(int a, int b, int node, int l, int r){
        if(a > r || b < l) return vector<int>(41, 0);
        if(l >= a && r <= b) {ans += val[node]; return tree[node];}
        
        int mid = (l+r)/2;
        if(a > mid || b < l) return query(a,b,2*node+1,mid+1,r);
        else if(a > r || b < mid+1) return query(a,b,2*node,l,mid);
        return join2(query(a,b,2*node,l,mid), query(a,b,2*node+1,mid+1,r));
    }

    void upd(int pos, int val){
        upd(pos, val, 1, 1, m);
        return;
    }
};

signed solve(){

    int n,q; cin >> n >> q;
    vector<vector<int>> arr(n, vector<int>(41, 0));
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[i][x]++;
    }
    
    Seg seg(n, arr);

    ans = 0;
    // seg.query(1,7,1,1,seg.m);
    // cout << ans << endl;

    while(q--){
        int op, x, y; cin >> op >> x >> y;
        if(op == 1){
            ans = 0;
            vector<int> cc = seg.query(x,y,1,1,seg.m);
            cout << ans << endl;
        }
        else{
            seg.upd(x, y);
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