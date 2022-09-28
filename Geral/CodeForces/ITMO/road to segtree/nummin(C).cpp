#include "bits/stdc++.h"
using ll = long long;
using namespace std;

class Segtree{
    public:
    ll nums;
    vector<pair<ll, ll>> tree;

    void set(int indice, ll valor){
        indice = indice + (nums-1);
        tree[indice] = {valor, 1};

        while(indice != 0){
            int factor = (indice-1)/2;

            pair<ll,ll> x,y;
            x = tree[factor*2+1]; y = tree[factor*2+2];

            if (x.first == y.first) tree[factor] = {x.first, x.second+y.second};
            else if(x.first < y.first) tree[factor] = x;
            else tree[factor] = y;

            indice = factor;
        }
    }

    pair<ll, ll> query(ll v, int l, int r, int a, int b){
        if(l >= b || r < a) return {LONG_LONG_MAX, 0};
        else if(l>=a && r<b) return tree[v];

        int md = (l+r)/2;
        pair<ll,ll> x,y;
        x = query(2*v+1, l, md, a, b); y = query(2*v+2, md+1, r, a, b);

        if (x.first == y.first) return {x.first, x.second+y.second};
        else if(x.first < y.first) return x;
        else return y;
    }
};

int main(){
    Segtree segtree;
    int n,m;
    cin >> n >> m;

    int factor = 1;
    while(factor<n) factor *= 2;
    segtree.nums = factor;
    factor *= 2;
    segtree.tree.resize(factor-1, {LONG_LONG_MAX, 0});

    for(int i = 0; i<n; i++){
        ll a;
        cin >> a;
        segtree.set(i,a);
    }

    vector<pair<ll,ll>>ans;

    for(int i = 0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if (a == 1) segtree.set(b,c);
        else ans.push_back(segtree.query(0,0,(segtree.nums-1),b,c));
    }

    for(pair<ll,ll> i : ans){
        cout << i.first << " " << i.second << "\n";
    }
}