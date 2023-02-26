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

vll tree(0); vll arr(0); vll lazy(0); vll seq(0);

void unlazy(int node, int l, int r){
    if(lazy[node] != 0){
        if(l == r){
            arr[l] = tree[node];
        }

        tree[node]+=lazy[node];   //change op

        if(l!=r){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void build(int node, int l, int r){
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node]=max(tree[2*node],tree[2*node+1]);     //change op
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    iterador*=2;
    tree.resize(iterador, -INFL);     //value of every node should be neutral value of op when itilializing
    lazy.resize(iterador, 0);
    build(1, 0, arr.size() - 1);
}

ll change(int node, int l, int r, int id, ll val){
    unlazy(node,l,r);
    if(l == r){
        ll diff = val - seq[l];
        seq[l] = val;
        arr[l] += diff;
        tree[node] += diff;
        return diff;
    }
    int mid = (l+r)>>1;
    ll diff;
    if(l <= id && id <= mid){
        diff = change(2*node, l, mid, id, val);
        lazy[2*node+1] += diff;
        unlazy(2*node+1, mid+1, r);
    } else{
        diff = change(2*node+1, mid+1, r, id, val);
        unlazy(2*node,l,mid);
    }
    tree[node] = max(tree[2*node], tree[2*node+1]); //change op
    return diff;
}

ll consult(int node, int l, int r, int id){
    unlazy(node,l,r);
    if(l == r) return tree[node];
    int mid = (l+r)/2;
    if(l <= mid && id <= mid){
        return consult(node*2, l, mid, id);
    }else{
        return consult(node*2+1, mid+1, r, id);
    }
}

ll query(int node, int l, int r, int a, int b){
    unlazy(node, l, r);
    if(a>r || b<l) return -INFL;    //change value
    if(a<=l && b>=r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    return max(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));   // change op
}

int main(){
    fastio;

    int n,q; cin >> n >> q;
    arr.resize(n,0); seq.resize(n,0);
    
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll a; cin >> a; sum += a;
        seq[i] = a;
        arr[i] = sum;
    }

    initialize();

    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll k,u; cin >> k >> u;
            change(1,0,n-1,k-1,u);
        }else{
            int a,b; cin >> a >> b; a--; b--;
            if(a == 0)cout << max(ll(0), query(1,0,n-1,a,b)) << endl;
            else cout << max(ll(0), query(1,0,n-1,a,b) - consult(1, 0, n-1, a-1)) << endl;
        }
    }

    return 0;
}