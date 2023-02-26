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

vll tree(0); vll arr(0);

void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node] = tree[2*node] ^ tree[2*node+1];     //change op
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    iterador = iterador << 1;
    tree.resize(iterador-1, 0);     //value of every node should be neutral value of op when itilializing
    build(1, 0, arr.size() - 1);
}

void upd(int node, int l, int r, int id, int val){
    if(l == r){
        tree[node] = val;
        arr[l] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(l <= id && id <= mid){
        upd(2*node, l, mid, id, val);
    } else{
        upd(2*node+1, mid+1, r, id, val);
    }
    tree[node] = tree[2*node] ^ tree[2*node+1]; //change op
}

ll query(int node, int l, int r, int a, int b){     //call it like query(1, 0, arr.size()-1, a, b)
    if(b < l || a > r) return 0;        //return neutral value of op
    if(l >= a && r <= b) return tree[node];
    int mid = (l+r)>>1;
    return query(2*node, l , mid, a, b) ^ query(2*node+1, mid+1, r, a, b);  //change op
}

int main(){
    fastio;

    int n,q; cin >> n >> q;
    arr.resize(n);
    for(ll &i: arr) cin >> i;

    initialize();

    while(q--){
        int a,b; cin >> a >> b; a--; b--;
        cout << query(1, 0, arr.size()-1, a, b) << endl;
    }

    return 0;
}