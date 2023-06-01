#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define pb push_back
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
int n,m;
vector<ll>coins; vector<vector<int>> graph; vector<int> lowlink; vector<int> depth; vector<bool> is_on;
stack<int> stk; vector<vector<int>> componentes; vector<int> component_by_point; vector<ll> comp_coins; vector<set<int>> graphcomp; vector<ll> record_comp;
vector<int> nos;
int tempo = 0; int componentes_index = -1;
ll total_record = -1;

int dfs(int curr){
    is_on[curr] = true;
    lowlink[curr] = depth[curr] = ++tempo;
    stk.emplace(curr);

    for(int next: graph[curr]){
        if(lowlink[next] == -1){
            dfs(next);
            lowlink[curr] = min(lowlink[curr], lowlink[next]);
        }
        else if(is_on[next]) lowlink[curr] = min(depth[next], lowlink[curr]);
    }

    if(depth[curr] == lowlink[curr]){
        componentes.pb({}); componentes_index++;
        int u = -1;
        while(u != curr){
            u = stk.top();
            component_by_point[u] = componentes_index;
            stk.pop();
            componentes[componentes_index].pb(u);
            is_on[u] = false;
        }
    }
    return 0;
}

int dfscaller(){
    for(int i = 0; i < n; i++){
        if (lowlink[i] == -1) dfs(i);
    }
    return 0;
}

int coinfinder(){
    comp_coins.resize(componentes.size(),0);
    for(int i = 0; i < componentes.size(); i++){
        for(int j = 0; j < componentes[i].size(); j++){
            comp_coins[i] += coins[componentes[i][j]];
        }
    }
    return 0;
}

int graphsetter(){
    bool isno = true;
    graphcomp.resize(componentes_index); 
    for(int i = 0; i < componentes_index; i++){
        for(int j : componentes[i]){
            for(int curr: graph[j]){
                if(component_by_point[curr] != component_by_point[j]) {
                    isno = false;
                    graphcomp[component_by_point[curr]].emplace(component_by_point[j]);
                }
            }
        }
        if(isno) nos.pb(i);
        isno = true;
    }
    return 0;
}

int searchbest(int curr, ll sum){
    ll curr_sum = sum + comp_coins[curr]; 
    record_comp[curr] = comp_coins[curr];
    for(int next: graphcomp[curr]){
        if(record_comp[next] == -1) searchbest(next, curr_sum);
        record_comp[curr] = max(record_comp[next] + comp_coins[curr], record_comp[curr]);
    }
    if (record_comp[curr] > total_record) total_record = record_comp[curr];
    return 0;
}

int main(){
    fastio;

    cin >> n >> m;

    graph.resize(n); coins.resize(n); lowlink.resize(n,-1); depth.resize(n,-1); component_by_point.resize(n,-1); is_on.resize(n,false);

    for(int i = 0; i < n; i++){
        ll a = 0; cin >> a;
        coins[i] = a;
    }

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        graph[a-1].pb(b-1);
    }

    dfscaller();
    componentes_index++;
    coinfinder();
    graphsetter();

    record_comp.resize(componentes_index, -1);
    for(int noinicial : nos){
        searchbest(noinicial,0);
    }

    cout << total_record << endl;

    return 0;
}