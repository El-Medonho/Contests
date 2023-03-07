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

vll tree(0); vll arr(0), lazy(0);
int gg;

void unlazy(int node, int l, int r){
    if(lazy[node]){
        tree[node]+=(r-l+1)*lazy[node];   //change op
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
    tree[node]=tree[2*node]+tree[2*node+1];     //change op
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    gg = iterador;
    iterador*=2;
    tree.resize(iterador, 0);     //value of every node should be neutral value of op when itilializing
    lazy.resize(iterador, 0);
    build(1, 0, arr.size() - 1);
}

void upd(int node, int l, int r, int a, int b, int val){
    unlazy(node, l, r);
    if(a>r || b<l) return;
    if(l>=a && r<=b){
        lazy[node]+=val;
        unlazy(node, l, r);
        return;
    }
    int mid=(l+r)>>1;
    upd(2*node, l, mid, a, b, val);
    upd(2*node+1, mid+1, r, a, b, val);
    tree[node]=tree[2*node]+tree[2*node+1];   //change op
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

int consult(int node, int l, int r, int id){
    unlazy(node,l,r);
    if(l == r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    if(l<=id && mid>=id){
        return consult(2*node,l,mid,id);
    }else{
        return consult(2*node+1, mid+1, r, id);
    }
}

int n;
vector<vii> graph(0), up(0);
vii parent(0), depth(0);
vector<pii> indice(0);
int tempo = -1;

void dfs(int curr, int last){
    indice[curr].f = ++tempo;
    arr.pb(0);
    depth.resize(n,0);
    parent.resize(n,0);
    for(int j: graph[curr]){
        if(last == j) continue;
        depth[j] = depth[curr]+1;
        parent[j] = curr;
        dfs(j,curr);
    }
    indice[curr].s = ++tempo;
    arr.pb(0);
    return;
}

void bl(){
    up.resize(n, vii(32,0));
    for(int i = 0; i < n; i++){
        up[i][0] = parent[i];
    }

    for(int j = 1; j < 20; j++){
        for(int i = 0; i < n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    return;
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a,b);
    int k = depth[b] - depth[a];

    for(int i = 19; i > -1; i--){
        if(k & (1<<i)){
            b = up[b][i];
        }
    }

    if(a == b){
        return a;
    }

    pii last = {a,b}; int matching = INF;
    for(int i = 19; i > -1; i--){
        a = up[a][i]; b = up[b][i];
        if(a == b){
            matching = a;
            a = last.f; b = last.s;
        }else{
            last = {a,b};
        }
    }
    return matching;
}

int main(){
    fastio;

    int m; cin >> n >> m;

    graph.resize(n);
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    indice.resize(n,{-1,-1});
    dfs(0,-1);
    bl();
    initialize();


    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        int c = lca(a,b);
        if(c == a || c == b){
            a = indice[a].f;
            b = indice[b].f;
            upd(1,0,tempo,min(a,b),max(a,b),1);
            continue;
        }
        a = indice[a].f;
        b = indice[b].f;
        c = indice[c].f;
        upd(1,0,tempo,min(a,c),max(a,c),1);
        upd(1,0,tempo,min(b,c),max(b,c),1);
        upd(1,0,tempo,c,c,-1);
    }

    for(int i = 0; i < n; i++){
        int a = indice[i].f, b = indice[i].s;
        a = consult(1,0,tempo,a);
        b = consult(1,0,tempo,b);
        int ans = a - b;
        cout << ans << esp;
    }
    cout << endl;

    return 0;
}