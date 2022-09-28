#include "bits/stdc++.h"
using namespace std;
using ll = long long;

class Segtree{
    public:
    int nums;
    int n;
    vector<ll> tree;

    void set(int index, ll valor){
        index += nums-1;
        tree[index] = valor;
        while(index!=0){
            int a = (index-1)/2;
            tree[a] = min(tree[(a*2)+1], tree[(a*2) + 2]);
            index = a;
        }
        return;
    }

    ll minimum(ll v,int l,int r,int a,int b){
        if(l>=b || r<a){return LONG_LONG_MAX;}
        if(l>=a && r < b){return tree[v];}
        int md = (l+r)/2;
        return min(minimum((v*2)+1, l, md, a, b), minimum((v*2)+2, md+1, r, a, b));
    }
};

int main(){
    Segtree segtree;
    int n,m;

    cin >> n >> m;
    int factor = 1;
    while(factor < n){
        factor *= 2;
    }
    segtree.nums = factor;
    factor *= 2;
    segtree.n = factor; segtree.tree.resize(factor, LONG_LONG_MAX);

    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        segtree.set(i, a);
    }

    vector<ll> ans;

    for(int i = 0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){segtree.set(b,c);}
        else{ans.push_back(segtree.minimum(0,0,segtree.nums-1,b,c));}
    }

    for(ll i: ans){
        cout << i << "\n";
    }


}