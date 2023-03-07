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

int n;
vector<vii> graph(0), up(0);
vii parent(0), depth(0), weight(0);
vll value(0);

vll tree(0); vll arr(0);
int sti = 0;

void build(int node, int l, int r){
    // if(l == r){
    //     if(l < arr.size()) tree[node] = arr[l];
    //     return;
    // }
    // int mid = (l+r)>>1;
    // build(2*node, l, mid);
    // build(2*node+1, mid+1, r);
    // tree[node] = max(tree[2*node], tree[2*node+1]);     //change op

    for(int i = sti; i < sti*2; i++){
        int l = (i-sti);
        if(l < arr.size()) tree[i] = arr[l];
    }

    for(int i = sti/2; i > 0; i/=2){
        for(int j = i; j < i*2; j++){
            tree[j] = max(tree[2*j], tree[2*j+1]);
        }
    }
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    sti = iterador;
    iterador*=2;
    tree.resize(iterador, -INFL);     //value of every node should be neutral value of op when itilializing
    build(1, 0, (iterador/2) - 1);
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
    tree[node] = max(tree[2*node], tree[2*node+1]); //change op
}

ll query(int node, int l, int r, int a, int b){     //call it like query(1, 0, sti-1, a, b)
    if(b < l || a > r) return -INFL;        //return neutral value of op
    if(l >= a && r <= b) return tree[node];
    int mid = (l+r)>>1;
    return max(query(2*node, l , mid, a, b), query(2*node+1, mid+1, r, a, b));  //change op
}

int dfs(int curr, int last){
    weight[curr] = 1;
    
    for(int j: graph[curr]){
        if(last == j) continue;
        depth[j] = depth[curr]+1;
        parent[j] = curr;
        weight[curr] += dfs(j,curr);
    }
    return weight[curr];
}

void dfscall(){

    depth.resize(n,0);
    parent.resize(n,0);
    weight.resize(n,0);
    dfs(0,-1);

    return;
}

vii ind(0),tp(0);
int tempo = 0;

void hld(int curr, int last, int top){
    arr[tempo] = value[curr];
    ind[curr] = tempo++;
    tp[curr] = top;

    int wt_id = -1, wt_val = -1;

    for(int j: graph[curr]){
        if(j == last) continue;
        if(weight[j] > wt_val){
            wt_val = weight[j];
            wt_id = j;
        }
    }

    if(wt_id == -1) return;

    hld(wt_id, curr, top);
    
    for(int j: graph[curr]){
        if(j == last || j == wt_id) continue;
        hld(j,curr,j);
    }
}

void hldcall(){
    ind.resize(n); tp.resize(n); arr.resize(n);
    hld(0,-1,0);
}

int main(){
    fastio;

    int q; cin >> n >> q;

    value.resize(n,0);
    for(ll &i: value) cin >> i;

    graph.resize(n);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfscall();

    hldcall();

    initialize();

    while(q--){
        int op; cin >> op;
        if(op == 1){
            ll i,x; cin >> i >> x; i--;
            upd(1,0,sti-1,ind[i], x);
        }else{
            int a,b; cin >> a >> b; a--; b--;
            
            ll ans = -INFL;
            while(tp[a] != tp[b]){
                if(depth[tp[a]] < depth[tp[b]]) swap(a,b);
                ans = max(ans, query(1,0,sti-1,ind[tp[a]],ind[a]));
                a = tp[a];
                a = parent[a];
            }

            if(depth[a] < depth[b]) swap(a,b);
            ans = max(ans, query(1,0,sti-1,ind[b],ind[a]));

            cout << ans << esp;
        }
    }

    cout << endl;

    return 0;
}