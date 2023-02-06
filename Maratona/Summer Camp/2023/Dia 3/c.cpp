#include <bits/stdc++.h>
#define mxn 100005
#define mxm 100005
#define pii pair<long long, long long>
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

    int r,c,q;
    vector<vector<int>> graph;
    int tempo = -1;
    vector<int> visited, lowlink, depth;
    vector<string> ans;

    int dfs(int curr, int last){
    visited[curr] = 1;
    lowlink[curr] = depth[curr] = ++tempo;

    for(int next : graph[curr]){
        if(visited[next] == 1 && next != last){
            lowlink[curr] = min(lowlink[curr], depth[next]);
        }
        if(visited[next] == 1) continue;
        dfs(next, curr);
        lowlink[curr] = min(lowlink[curr], lowlink[next]);
    }
    return 0;
}

    int dfscaller(){
        for(int i = 0; i < r; i++){
            if(depth[i] == -1) dfs(i,-1);
        }
        return 0;
    }

bool dfsalt(int curr, int obj){
    if(curr == obj) return true;
    visited[curr] = 1;
    for(auto next: graph[curr]){
        if(visited[next] == 1|| lowlink[next] != depth[next]) continue;
        if(lowlink[next] == depth[next]) {if(dfsalt(next, obj)) return true;}
    }
    return false;
}

int dfsaltcaller(){
    for(int g = 0; g < q; g++){
        for(int i = 0; i < r; i++) {visited[i] = 0;}
        int u,v;
        cin >> u >> v; u--; v--;
        if(dfsalt(u,v)) ans.push_back("Y");
        else ans.push_back("N");
    }
    return 0;
}

int main(){
    fastio;
    ans.resize(0);
    while(true){
    cin >> r >> c >> q;
    graph.resize(0);
    graph.resize(r);
    if(r == 0 && c == 0 && q==0) break;

    for(int i = 0; i < c; i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visited.resize(0);  depth.resize(0); lowlink.resize(0);
    visited.resize(r,0); depth.resize(r,-1); lowlink.resize(r,-1); tempo = -1;

    dfscaller();
    dfsaltcaller();

    ans.push_back("-");
}
for(auto x: ans) cout << x << endl;
return 0;
}