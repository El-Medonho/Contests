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
vii parent(0), depth(0);

void dfs(int curr, int last){
    depth.resize(n,0);
    parent.resize(n,0);
    for(int j: graph[curr]){
        if(last == j) continue;
        depth[j] = depth[curr]+1;
        parent[j] = curr;
        dfs(j,curr);
    }
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
    int ans = 0;
    if(depth[a] > depth[b]) swap(a,b);
    int k = depth[b] - depth[a];
    ans += k;

    for(int i = 19; i > -1; i--){
        if(k & (1<<i)){
            b = up[b][i];
        }
    }

    if(a == b){
        return ans;
    }

    pii last = {a,b}; int matching = INF;
    k = 0; int lastk = 0, matchingk = 0;;
    for(int i = 19; i > -1; i--){
        a = up[a][i]; b = up[b][i];
        k += (1<<i)*2;
        if(a == b){
            matchingk = k;
            k = lastk;
            matching = a;
            a = last.f; b = last.s;
        }else{
            last = {a,b};
            lastk = k;
        }
    }
    ans += matchingk;
    return ans;
}

int main(){
    fastio;

    int q; cin >> n >> q;

    graph.resize(n);
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs(0,-1);
    bl();

    while(q--){
        int a,b; cin >> a >> b; a--; b--;
        cout << lca(a,b) << endl;
    }

    return 0;
}