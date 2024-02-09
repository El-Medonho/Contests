#include "bits/stdc++.h"

using namespace std;

template <class T> struct Seg{
    int n, m = 1;
    T neutral=0;    //remember to change
    vector<T> tree, lazy;
    T join(const T &a, const T &b){     
        return (a&b);       //remember to change
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
        if(lazy[node]){
            tree[node]|=lazy[node]; //remember to change
            if(l!=r){
                lazy[2*node]|=lazy[node];
                lazy[2*node+1]|=lazy[node];
            }
            lazy[node]=0;
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