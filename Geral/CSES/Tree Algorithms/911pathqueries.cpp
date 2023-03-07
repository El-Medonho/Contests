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

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}
ll sum(int ind, vector<ll> &bit){         //O(logn)
    ll ans=0;
    while(ind){
        ans+=bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

int n;
vector<vii> graph(0), up(0);
vii parent(0), depth(0);
vector<pii> ind(0);
vll value(0);
vii arr(1,0);
int tempo = 0;

void dfs(int curr, int last){
    arr.pb(value[curr]);
    ind[curr].f = ++tempo;

    for(int j: graph[curr]){
        if(last == j) continue;
        depth[j] = depth[curr]+1;
        parent[j] = curr;
        dfs(j,curr);
    }

    arr.pb(-value[curr]);
    ind[curr].s = ++tempo;

    return;
}

void dfscall(){

    depth.resize(n,0);
    parent.resize(n,0);
    ind.resize(n);
    dfs(0,-1);

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

    int q; cin >> n >> q;

    graph.resize(n);
    value.resize(n);
    for(ll &i: value) cin >> i;
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfscall();
    bl();

    vll bit(arr.size(),0);
    
    for(int i = 1; i <= bit.size(); i++){
        upd(i, arr[i], bit);
    }

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int i,x; cin >> i >> x; i--;
            ll diff = x-value[i];
            value[i] = x;
            upd(ind[i].f, diff, bit);
            upd(ind[i].s, -diff, bit);
        }else{
            int a,b; cin >> a; a--;
            b = 0;
            
            if(depth[a] > depth[b]) swap(a,b);
            ll ans = sum(ind[b].f, bit);
            cout << ans << endl;
        }
    }


    return 0;
}