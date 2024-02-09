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
    int n, neutral=0;
    vector<T> tree, lazy;
    Seg(int n) : n(n), tree(4*(n+1)), lazy(4*(n+1)) {}
    T join(T a, T b){
        return a + b;
    }
    void unlazy(int node, int l, int r){
        if(lazy[node]){
            tree[node]+=(r-l+1)*lazy[node]; //remember to change
            if(l!=r){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }
    void upd(int node, int l, int r, int pos, int val){
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
    void upd(int node, int l, int r, int a, int b, int val){
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
    int upper(int node, int l, int r, int a, int b, int val){
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
    void upd(int pos, int val){
        upd(1, 1, n, pos, val);
    }
    void upd(int l, int r, int val){
        upd(1, 1, n, l, r, val);
    }
    T query(int l, int r){
        return query(1, 1, n, l, r);
    }
    int upper(int l, int r, int val){
    //primeira posição com valor > que val
        return upper(1, 1, n, l, r, val);
    }
};

template <class T> struct HLD{
    int n, cont=0;
    vector<int> sub, pai, heavy, chain, pos, v;
    vector<vector<int>> vec;
    Seg<T> seg;
    
    HLD(int n) : n(n), seg(n), sub(n+1), pai(n+1), heavy(n+1), chain(n+1),
    pos(n+1), vec(n+1), v(n+1) {}
    
    void add_edge(int a, int b){
        a++; b++;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    void dfs(int x, int p){
        sub[x]=1;
        int maior=0;
        for(int i:vec[x]){
            if(i==p) continue;
            dfs(i, x);
            if(sub[i]>maior) maior=sub[i], heavy[x]=i;
            pai[i]=x;
            sub[x]+=sub[i];
        }
    }
    void hld(int x, int atual){
        chain[x]=atual;
        pos[x]=++cont;
        
        seg.upd(1, 1, n, pos[x], v[x]);
        
        if(heavy[x]) hld(heavy[x], atual);
        for(int i:vec[x]){
            if(i==heavy[x] || i==pai[x]) continue;
            hld(i, i);
        }
    }
    
    void build(){
        dfs(1, 0);
        hld(1, 1);
    }
    
    T query_path(int a, int b){
        int ans=0;
        while(chain[a]!=chain[b]){
            if(pos[chain[a]]<pos[chain[b]]) swap(a, b);
            
            ans=seg.join(ans, seg.query(1, 1, n, pos[chain[a]], pos[a]));
            a=pai[chain[a]];
        }
        if(pos[a]>pos[b]) swap(a, b);
        //if the values are on the edges pos[a]+1
        ans=seg.join(ans, seg.query(1, 1, n, pos[a], pos[b]));
        return ans;
    }
    void upd_path(int a, int b, T x){
        while(chain[a]!=chain[b]){
            if(pos[chain[a]]<pos[chain[b]]) swap(a, b);
            seg.upd(1, 1, n, pos[chain[a]], pos[a], x);
            a=pai[chain[a]];
        }
        if(pos[a]>pos[b]) swap(a, b);
        
        //if the values are on the edges pos[a]+1
        seg.upd(1, 1, n, pos[a], pos[b], x);
    }

    T query_sub(int a){
        return seg.query(1, 1, n, pos[a], pos[a]+sub[a]-1);
    }
    void upd_sub(int a, T x){
        seg.upd(1, 1, n, pos[a], pos[a]+sub[a]-1, x);
    }
    T query_node(int a){
        return seg.query(1, 1, n, pos[a], pos[a]);
    }
    void upd_node(int a, T x){
        seg.upd(1, 1, n, pos[a], x);
    }
};

signed solve(){

    int n,q; cin >> n >> q;

    HLD<int> hld(n);

    vector<vector<int>> graph(n);
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);

        hld.add_edge(a, b);
    }

    hld.build();

    while(q--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;

        hld.upd_path(a+1,b+1,1);

        int ans = hld.query_path(c+1,d+1);

        hld.upd_path(a+1,b+1,-1);

        cout << ans << endl;
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