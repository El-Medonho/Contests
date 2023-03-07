#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

int n,m; 
vll seq(0), arr(0);

vll treeu(0), treel(0);

void buildm(int node, int l, int r){
    if(l == r){
        treeu[node] = arr[l];
        treel[node] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    buildm(2*node, l, mid);
    buildm(2*node+1, mid+1, r);
    
    treeu[node] = max(treeu[2*node], treeu[2*node+1]);  
    treel[node] = min(treel[2*node], treel[2*node+1]);
}

void initializem(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    iterador*=2;
    treeu.resize(iterador, -1e18);     //value of every node should be neutral value of op when itilializing
    treel.resize(iterador, 1e18);
    buildm(1, 0, arr.size() - 1);
}

ll queryu(int node, int l, int r, int a, int b){     //call it like query(1, 0, arr.size()-1, a, b)
    if(b < l || a > r) return -1e18;        
    if(l >= a && r <= b) return treeu[node];
    int mid = (l+r)>>1;
    
    return max(query(2*node, l , mid, a, b), query(2*node+1, mid+1, r, a, b));
}

ll queryl(int node, int l, int r, int a, int b){     //call it like query(1, 0, arr.size()-1, a, b)
    if(b < l || a > r) return 1e18;        
    if(l >= a && r <= b) return treel[node];
    int mid = (l+r)>>1;
    
    return min(query(2*node, l , mid, a, b), query(2*node+1, mid+1, r, a, b));
}

vector<pll> tree(0), parr(0), lazy(0);

void unlazy(int node, int l, int r){
    if(lazy[node] != {0,0}){
        tree[node].f += lazy[node].f;   //change op
        tree[node].s += lazy[node].s;
        if(l!=r){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
}

void build(int node, int l, int r){
    if(l==r){
        tree[node]=parr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    int ind = 2*node;
    tree[node]= ((tree[ind].f - tree[ind].s) > (tree[ind+1].f - tree[ind+1].s)) ? tree[ind] : tree[ind+1];
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    iterador*=2;
    tree.resize(iterador, make_pair(-1e18, 1e18)); 
    lazy.resize(iterador, make_pair(0, 0));    
    build(1, 0, arr.size() - 1);
}

pll consult(int node, int l, int r, int id){
    unlazy(node,l,r);
    if(l > id || r < id) return {-1e18, 1e18};
    if(l == r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    if(l<=id && mid>=id){
        return consult(2*node,l,mid,id);
    }else{
        return consult(2*node+1,mid+1,r,id);
    }
}

void rangeupd(int node, int l, int r, int a, int b, int val){
    unlazy(node, l, r);
    if(a>r || b<l) return;
    if(l>=a && r<=b){
        lazy[node]=val;
        unlazy(node, l, r);
        return;
    }
    int mid=(l+r)>>1;
    rangeupd(2*node, l, mid, a, b, val);
    rangeupd(2*node+1, mid+1, r, a, b, val);
    tree[node]=tree[2*node]+tree[2*node+1];   //change op
}

int searchu(int node, int l, int r, int a, int b, ll val){
    if(node == 1) unlazy(node,l,r);
    if(a>r || b<l) return -1;
    if(l==r){
        if(tree[node].f == val) return l;
        return -1;
    }

    int mid = (l+r)>>1;

    unlazy(2*node,l,mid); unlazy(2*node+1,mid+1,r);
    if(tree[2*node+1] > val) return searchu(2*node+1,mid+1,r,a,b,val);

    int c = searchu(2*node,l,mid,a,b,val), d = searchu(2*node+1,mid+1,r,a,b,val);
    if(d != -1) return d;
    return c;
}

int searchl(int node, int l, int r, int a, int b, ll val){
    unlazy(node,l,r);
    if(a>r || b<l) return -1;
    if(tree[node].s < val) return -1;
    if(l==r){
        if(tree[node].s == val) return l;
        return -1;
    }

    int mid = (l+r)>>1;
    int c = searchl(2*node,l,mid,a,b,val), d = searchl(2*node+1,mid+1,r,a,b,val);
    if(c != -1) return c;
    return d;
}

void upd(int ind, ll val){
    int indu = ind;
    pll cons = consult(1,0,n-1,ind);
    if(tree[1].f != val){
        indu = (ind != 0) ? searchu(1,0,n-1,0,i-1,cons.f) : ind;    //0,i-1
    }
    int indl = searchl();   //i,n-1

    if(indu == -1) indu = ind;
    if(indl == -1) indl = ind;

    rangeupd
}

int query(int node, int l, int r, int a, int b){
    unlazy(node, l, r);
    if(a>r || b<l) return 0;    //change value
    if(a<=l && b>=r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);   // change op
}

int main(){
    fastio;

    cin >> n >> m;

    seq.resize(0); arr.resize(0);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        seq[i] = a;
        sum += a;
        arr[i] = sum;
    }

    initializem();

    parr(n);
    for(int i = 0; i < n; i++){
        parr[i] = {queryu(1,0,n-1,0,i), queryl(1,0,n-1,i,n-1)};
    }

    initialize();

    while(m--){
        ll k,x; cin >> k >> x;
    }



    return 0;
}