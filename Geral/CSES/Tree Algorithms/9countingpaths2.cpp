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
vii parent(0), depth(0), arr(0);
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

    for(int j = 1; j < 18; j++){
        for(int i = 0; i < n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    return;
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a,b);
    int k = depth[b] - depth[a];

    for(int i = 17; i > -1; i--){
        if(k & (1<<i)){
            b = up[b][i];
        }
    }

    if(a == b){
        return a;
    }

    pii last = {a,b}; int matching = INF;
    for(int i = 17; i > -1; i--){
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

    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        int c = lca(a,b);
        if(c == a || c == b){
            a = indice[a].f;
            b = indice[b].f;
            if(a > b) swap(a,b); 
            arr[a] += 1;
            arr[b+1] -= 1;
            continue;
        }
        a = indice[a].f;
        b = indice[b].f;
        c = indice[c].f;
        arr[c] += 1;
        arr[c+1] += 1;
        arr[a+1] -= 1;
        arr[b+1] -= 1;
    }

    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        arr[i] = sum;
    }

    for(int i = 0; i < n; i++){
        int a = indice[i].f, b = indice[i].s;
        int ans = arr[a]-arr[b];
        cout << ans << esp;
    }
    cout << endl;

    return 0;
}