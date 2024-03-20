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
    T neutral=-1;    //remember to change
    vector<T> tree, lazy;
    T join(const T &a, const T &b){     
        return max(a,b);       //remember to change
    }
    Seg(int n, vector<T> ini = {}) : n(n) {
        while(m < n) m<<=1;

        tree.resize(2*m, neutral);
        lazy.resize(2*m, neutral);

        if(ini.size()){
            for(int i = m; i < m+ini.size(); i++) tree[i] = ini[i-m];
            for(int i = m-1; i > 0; i--) tree[i] = join(tree[2*i], tree[2*i+1]);
        }
    }
    void unlazy(int node, int l, int r){
        if(lazy[node] != neutral){
            tree[node]=max(tree[node],lazy[node]); //remember to change
            if(l!=r){
                lazy[2*node]=max(lazy[node], lazy[2*node]);
                lazy[2*node+1]=max(lazy[node], lazy[2*node+1]);
            }
            lazy[node]=neutral;
        }
    }
    void upd(int node, int l, int r, int pos, const T &val){
        if(l==r){
            tree[node]=val;     //change if necessary
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
        tree[node]=join(tree[2*node], tree[2*node+1]);
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
    void upd(int pos, const T &val){
        upd(1, 1, m, pos, val);
    }
    void upd(int l, int r, const T &val){
        upd(1, 1, m, l, r, val);
    }
    T query(int l, int r){
        return query(1, 1, m, l, r);
    }
    int upper(int l, int r, const T  &val){
    //primeira posição com valor > que val
        return upper(1, 1, m, l, r, val);
    }
};

template <class T> struct Seg2{
    int n, m = 1;
    T neutral=0;    //remember to change
    vector<T> tree, lazy;
    T join(const T &a, const T &b){     
        return (a+b);       //remember to change
    }
    Seg2(int n, vector<T> ini = {}) : n(n) {
        while(m < n) m<<=1;

        tree.resize(2*m, neutral);
        lazy.resize(2*m, neutral);

        if(ini.size()){
            for(int i = m; i < m+ini.size(); i++) tree[i] = ini[i-m];
            for(int i = m-1; i > 0; i--) tree[i] = join(tree[2*i], tree[2*i+1]);
        }
    }
    void unlazy(int node, int l, int r){
        if(lazy[node] != neutral){
            tree[node]+=lazy[node]; //remember to change
            if(l!=r){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=neutral;
        }
    }
    void upd(int node, int l, int r, int pos, const T &val){
        if(l==r){
            tree[node]=val;     //change if necessary
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
        tree[node]=join(tree[2*node], tree[2*node+1]);
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
    void upd(int pos, const T &val){
        upd(1, 1, m, pos, val);
    }
    void upd(int l, int r, const T &val){
        upd(1, 1, m, l, r, val);
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

    int n,m; cin >> n >> m;

    Seg<ll> mx(n);
    Seg2<ll> sum(n);

    while(m--){
        int l,r; cin >> l >> r;
        mx.upd(l,r, r);
        sum.upd(l,r,1);
    }

    vector<ll> dp(n+5, 0);

    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i], dp[i-1]);

        int r = mx.query(i,i);

        ll val = sum.query(i,i);

        if(r != -1) dp[r+1] = max(dp[r+1], dp[i] + val);
    }

    dp[n+1] = max(dp[n+1], dp[n]);
    
    cout << dp[n+1] << endl;

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