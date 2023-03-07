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

//esse algoritmo precisa do uso de segtree
//O(q.log²n)

int n;

vii weight(0), depth(0), parent(0), req(0);
vector<vii> children(0), graph(0);

int dfs(int curr, int last){
    weight[curr] = 1;
    
    for(int j: graph[curr]){
        if(last == j) continue;
        children[curr].pb(j);
        req[curr]++;
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
    children.resize(n);
    req.resize(n,0);
    dfs(0,-1);

    return;
}

vll value(0);
vii ind(0),tp(0),heavy(0);
int tempo = 0;

vector<set<int>> colors(0);

void hld(int curr, int last, int top){
    ind[curr] = ind[top];
    tp[curr] = top;

    int wt_id = -1, wt_val = -1;

    for(int j: graph[curr]){
        if(j == last) continue;
        if(weight[j] > wt_val){
            wt_val = weight[j];
            wt_id = j;
        }
    }
    heavy[curr] = wt_id;
    if(wt_id == -1) return;

    hld(wt_id, curr, top);
    
    for(int j: graph[curr]){
        if(j == last || j == wt_id) continue;
        ind[j] = ++tempo;
        hld(j,curr,j);
    }
}

void hldcall(){
    ind.resize(n,0); tp.resize(n); heavy.resize(n,-1);
    hld(0,-1,0);
}

int main(){
    fastio;

    cin >> n;

    value.resize(n);
    for(ll &i: value) cin >> i;

    graph.resize(n);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfscall();
    hldcall();

    vii ans(n,0);
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(req[i] == 0) q.push(i);
    }

    colors.resize(++tempo);

    while(!q.empty()){
        int curr = q.front(); q.pop();


        colors[ind[curr]].insert(value[curr]);

        for(int j: graph[curr]){
            if(j == parent[curr] || j == heavy[curr]) continue;
            colors[ind[curr]].merge(colors[ind[j]]);      
        }
        
        req[parent[curr]]--;
        if(curr != 0 && req[parent[curr]] == 0) q.push(parent[curr]);
        ans[curr] = colors[ind[curr]].size();
    }

    for(int i: ans) cout << i << esp;
    cout << endl;

    return 0;
}