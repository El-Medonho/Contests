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

vector<pll> treer(0), treel(0); vll arr(0);

void build(int node, int l, int r){
    if(l == r){
        treer[node] = treel[node] = {arr[l],l};
        return;
    }
    int mid = (l+r)>>1;
    
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    
    int cnst = 2*node;
    ll distl = abs(treel[cnst].s - treel[cnst+1].s);
    ll distr = abs(treer[cnst].s - treer[cnst+1].s);


    treel[node] = (treel[cnst].f + distl < treel[cnst + 1].f) ? treel[cnst] : treel[cnst + 1];
    treer[node] = (treer[cnst].f < treer[cnst + 1].f + distr) ? treer[cnst] : treer[cnst + 1];
    // tree[node] = tree[2*node], tree[2*node+1];     //change op
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    iterador*=2;
    treel.resize(iterador, {1e18, 1e7});     //value of every node should be neutral value of op when itilializing
    treer.resize(iterador, {1e18, 1e7});
    build(1, 0, arr.size() - 1);
}

void upd(int node, int l, int r, int id, int val){
    if(l == r){
        treel[node] = treer[node] = {val,l};
        arr[l] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(l <= id && id <= mid){
        upd(2*node, l, mid, id, val);
    } else{
        upd(2*node+1, mid+1, r, id, val);
    }
    
    int cnst = 2*node;
    ll distl = abs(treel[cnst].s - treel[cnst+1].s);
    ll distr = abs(treer[cnst].s - treer[cnst+1].s);


    treel[node] = (treel[cnst].f + distl < treel[cnst + 1].f) ? treel[cnst] : treel[cnst + 1];
    treer[node] = (treer[cnst].f < treer[cnst + 1].f + distr) ? treer[cnst] : treer[cnst + 1];
}

pll queryr(int node, int l, int r, int a, int b){     
    if(b < l || a > r) return {1e18, 1e7};        
    if(l >= a && r <= b) return treer[node];
    int mid = (l+r)>>1;
    
    int cnst = 2*node;
    pll aa = queryr(2*node, l , mid, a, b), bb = queryr(2*node+1, mid+1, r, a, b);  
    ll distr = abs(aa.s - bb.s);

    return (aa.f < bb.f + distr) ? aa : bb;
}

pll queryl(int node, int l, int r, int a, int b){     
    if(b < l || a > r) return {1e18, 1e7};        
    if(l >= a && r <= b) return treel[node];
    int mid = (l+r)>>1;
    
    int cnst = 2*node;
    pll aa = queryl(2*node, l , mid, a, b), bb = queryl(2*node+1, mid+1, r, a, b);  
    ll distl = abs(aa.s - bb.s);

    return (aa.f + distl < bb.f) ? aa : bb;
}

int main(){
    fastio;

    int n,q; cin >> n >> q;
    
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    initialize();

    while(q--){
        int h; cin >> h;
        if(h == 1){
            ll k,x; cin >> k >> x; k--;
            upd(1,0,n-1,k,x);
        }else{
            ll k; cin >> k; k--;
            pll a = queryl(1,0,n-1,0,k), b = queryr(1,0,n-1,k,n-1);
            a.f += abs(a.s-k); b.f += abs(b.s-k);
            cout << min(a.f, b.f) << endl;
        }
    }

    return 0;
}