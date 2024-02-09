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

using namespace std;

typedef long long ll;

struct Seg{
    int n, m = 1;
    vector<ll> tree, pre, suf, best;

    void join(int k, int a, int b){
        tree[k] = tree[a] + tree[b];
        pre[k] = max(pre[a], tree[a] + pre[b]); pre[k] = max(pre[k], 0LL);
        suf[k] = max(suf[b], tree[b] + suf[a]); suf[k] = max(suf[k], 0LL);
        best[k] = max(best[a], best[b]); best[k] = max(best[k], suf[a]+pre[b]);
    }

    Seg(int n, vector<ll> &arr) : n(n) {
        
        while(m < n) m<<=1;
        tree.resize(2*m, 0);
        pre.resize(2*m, 0);
        suf.resize(2*m, 0);
        best.resize(2*m, 0);

        for(int i = m; i < n+m; i++) {
            tree[i] = arr[i-m];
            pre[i] = suf[i] = max(tree[i], 0LL);
            best[i] = pre[i];
        }

        for(int i = m-1; i > 0; i--) join(i, 2*i, 2*i+1);
    }

    void upd(int pos, ll val, int node, int l, int r){
        if(l > pos || r < pos) return;
        if(l == r){
            tree[node] = val;
            pre[node] = suf[node] = max(tree[node], 0LL);
            best[node] = pre[node];
            return;
        }

        int mid = (l+r)/2;
        upd(pos,val,2*node,l,mid);
        upd(pos,val,2*node+1,mid+1,r);

        join(node, 2*node, 2*node+1);
    }

    ll query(int a, int b, int node, int l, int r){
        if(l > b || r < a) return 0;
        if(l >= a && r <= b){
            return best[node];
        }
        
        int mid = (l+r)/2;
        return max(query(a,b,2*node,l,mid), query(a,b,2*node+1,mid+1,r));
    }

    void upd(int pos, ll val){
        upd(pos, val, 1, 1, m);
    }
    ll query(int a, int b){
        return query(a,b,1,1,m);
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,q; cin >> n >> q;
    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    Seg seg(n, arr);

    while(q--){
        int pos,x; cin >> pos >> x;
        seg.upd(pos,x);
        cout << max(seg.best[1],0LL) << '\n';
    }

    return 0;
}