#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

vector<vector<int>> graph;
vector<int> visited, lowlink, depth, finishedvisiting;
int n,m,tempo;
bool impossible = false;
int currlink = 0;
vector<pair<int,int>> ans;

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

int newdfs(int curr, int last){
    visited[curr] = 1;
    for(int next: graph[curr]){
        if(visited[next] == 1 && next != last && finishedvisiting[next] == 0){
            ans.push_back({curr + 1, next + 1}); continue;
        }
        if(visited[next] == 1) continue;
        newdfs(next, curr);
        ans.push_back({curr + 1, next + 1});
    }
    finishedvisiting[curr] = 1;
    return 0;
}

int find_cycle(){
    dfs(0,-1);
    for(int i = 0; i < n; i++){
        if(visited[i] == 0 || (lowlink[i] == depth[i] && depth[i] != 1)) {impossible = true; return 0;}
    }

    visited.resize(0); visited.resize(n,0);

    newdfs(0,-1);

    return 0;
}

int main(){
    fastio;
    cin >> n >> m;
    visited.resize(n,0); lowlink.resize(n,0); depth.resize(n,0); finishedvisiting.resize(n,0); graph.resize(n);
    for(int i = 0; i < m; i++){
        int q,p;
        cin >> q >> p;
        graph[q-1].push_back(p-1); graph[p-1].push_back(q-1);
    }

    find_cycle();
    if (impossible) {cout << 0 << endl; return 0;}
    for (pair<int,int> i : ans) cout << i.f << " " << i.s << endl;
    return 0;
}