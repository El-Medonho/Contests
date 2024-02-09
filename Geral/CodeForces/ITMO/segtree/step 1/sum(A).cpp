#include "bits/stdc++.h"
using ll = long long;
using namespace std;

class segtrees{
    public:
    int n;
    int nums;
    vector<ll> segtree;

    void tamanho(int inicial){
        int iterador = 1;
        while(iterador < inicial){
            iterador *= 2;
        }
        nums = iterador;
        iterador *= 2;
        segtree.resize(iterador-1, 0);
        n = segtree.size();
    }

    void set(int indice, int valor){
        indice += nums-1;
        ll dif = valor - segtree[indice];
        segtree[indice] = valor;
        while(indice!=0){
            indice = (indice-1) / 2;
            segtree[indice] += dif;
        }
        return;
    }

    ll query(ll v,int l,int r,int a,int b){
        if(a>r || b<=l){return 0;}
        if(a <= l && b > r){ return segtree[v];}
        int md = (l+r)/2;
        return query(v*2+1,l,md,a,b) + query(v*2+2,md+1,r,a,b);
    }

    ll sum(int a,int b){
        return query(0,0,nums-1,a,b);
    }
};

int main(){
    int n,m;
    segtrees tree;

    cin >> n >> m;
    tree.tamanho(n);
    
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        tree.set(i, a);
    }
    
    // tree.initialize(0);

    vector<ll> ans;


    for(int i = 0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if (a==1){tree.set(b,c);}
        else{ans.push_back(tree.sum(b,c));}
    }

    for(ll i : ans){
        cout << i << "\n";
    }

}