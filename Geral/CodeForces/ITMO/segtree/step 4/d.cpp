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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

ll ans = 0;

struct Seg{
    int n, m;
    vector<vector<int>> tree;

    vector<int> join(const vector<int> &a, const vector<int> &b){
        vector<int> base(41, 0);

        for(int i = 0; i < 41; i++){
            base[i] += a[i]+b[i];
        }

        return base;
    }

    Seg(int n, vector<int> &arr) : n(n) {
        m = 1;
        while(m < n) m<<=1;

        tree.resize(2*m, vector<int>(41, 0));

        for(int i = m; i < n+m; i++) tree[i][arr[i-m]]++;

        for(int i = m-1; i > 0; i--) tree[i] = join(tree[2*i], tree[2*i+1]);
    }

    void upd(int pos, int val, int node, int l, int r){
        if(l > pos || r < pos) return;
        if(l == r){
            tree[node] = vector<int>(41,0);
            tree[node][val]++;
            return;
        }
        int mid = (l+r)/2;
        if(mid >= pos) upd(pos, val, node*2, l, mid);
        else upd(pos, val, node*2+1, mid+1, r);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }

    vector<int> query(int a, int b, int node, int l, int r){
        if(a > r || b < l) return vector<int>(41,0);
        if(l >= a && r <= b) {return tree[node];}
        
        int mid = (l+r)/2;
        if(a > mid || b < l) return query(a,b,2*node+1,mid+1,r);
        else if(a > r || b < mid+1) return query(a,b,2*node,l,mid);
        return join(query(a,b,2*node,l,mid), query(a,b,2*node+1,mid+1,r));
    }

    void upd(int pos, int val){
        upd(pos, val, 1, 1, m);
        return;
    }
};

signed solve(){

    int n,q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[i] = x;
    }
    
    Seg seg(n, arr);

    ans = 0;

    while(q--){
        int op, x, y; cin >> op >> x >> y;
        if(op == 1){
            ans = 0;
            vector<int> cc = seg.query(x,y,1,1,seg.m);
            int ss = 0;
            for(int i: cc){
                if(i) ss++;
            }
            cout << ss << endl;
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