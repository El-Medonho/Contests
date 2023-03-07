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
vector<vii> graph(0);
vll coins(0);

vii visiting(0), lowlink(0), depth(0);
int tempo = 0;
stack<int> stk;

vii comps(0);
int compcnt = -1;

vector<vii> compgraph(0);
vll compcoins(0);
vll best(0);

ll ans = 0;

void tarjan(int curr){
    depth[curr] = lowlink[curr] = ++tempo;
    stk.push(curr);
    visiting[curr] = 1;

    for(int i: graph[curr]){
        if(lowlink[i] == -1){
            
            tarjan(i);
            lowlink[curr] = min(lowlink[curr], lowlink[i]);

        }else if(visiting[i] == 1){

            lowlink[curr] = min(lowlink[curr], depth[i]);

        }
    }

    if(depth[curr] == lowlink[curr]){
        int u = -1;
        compcnt++;
        compcoins.pb(0);

        while(u != curr){
            u = stk.top(); stk.pop();
            comps[u] = compcnt;
            compcoins[compcnt] += coins[u];
            visiting[u] = 0;
        }
    }

    return;
}

bool tarjancaller(){
    for(int i = 0; i < n; i++){
        if(lowlink[i] == -1){
            tarjan(i);
        }
    }
    return true;
}

void graphsetter(){
    compgraph.resize(compcnt+1);
    best.resize(compcnt+1, -1);

    for(int i = 0; i < n; i++){
        int curr = comps[i];
        for(int j: graph[i]){
            if(comps[j] == curr) continue;
            compgraph[curr].pb(comps[j]);
        }
    }
}

void dfs(int curr){
    best[curr] = compcoins[curr];

    for(int j: compgraph[curr]){
        if(best[j] == -1){
            dfs(j);
            best[curr] = max(best[curr], compcoins[curr] + best[j]);
        }else{
            best[curr] = max(best[curr], compcoins[curr] + best[j]);
        }
    }

    ans = max(ans, best[curr]);
    return;
}

void dfscaller(){
    for(int i = 0; i < compcnt+1; i++){
        if(best[i] == -1) dfs(i);
    }
}

int main(){
    fastio;

    cin >> n >> m;

    graph.resize(n); coins.resize(n); comps.resize(n, -1);
    lowlink.resize(n,-1); depth.resize(n,-1); visiting.resize(n,0);

    for(ll &i: coins) cin >> i;

    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
    }

    tarjancaller();
    graphsetter();
    dfscaller();

    cout << ans << endl;

    return 0;
}