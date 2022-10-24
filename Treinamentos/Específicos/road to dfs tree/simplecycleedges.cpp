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

vector<vector<pair<int,int>>> graph;
vector<int> visited; vector<int> lowlink; vector<int> depth; vector<int> whichcycle; vector<vector<int>> cycles;
vector<int> ans;
int tempo = 0;
int linking = 0; int first = -1;
int n,m;
stack<int> stck;


int dfs(int curr, int last){
    visited[curr] = 1;
    lowlink[curr] = depth[curr] = ++tempo;
    stck.push(curr);

    for(pair<int,int> next: graph[curr]){
        if(next.f != last && visited[next.f] == 1){
            lowlink[curr] = min(lowlink[curr], depth[next.f]);
            continue;
        }
        if(visited[next.f] == 1) continue;
        dfs(next.f,curr);
        lowlink[curr] = min(lowlink[curr], lowlink[next.f]);
    }
    if (lowlink[curr] == depth[curr]){
        vector<int> currcycle;
        int v = -1;
        do{
            v = stck.top();
            stck.pop();
            currcycle.push_back(v);
        }
        while(v != curr);
        cycles.push_back(currcycle);
    }
    
    return 0;
}

int checkrootsum = 0;

int newdfs(int curr, int last){
    int sum = 0;
    int nxt = -1;
    int numnum = 0;
    for(pair<int,int> next: graph[curr]){
        if(whichcycle[next.f] != whichcycle[curr]) continue;
        sum++;
        if(next.f != last) {nxt = next.f; numnum = next.s;}
    }
    if(sum % 2 == 1) return 0; 
    if(nxt == first) { ans.push_back(numnum); return 1;}
    int u = newdfs(nxt, curr);
    if (u == 1) ans.push_back(numnum);
    return u;
}

int findcycle(){
    for(int i = 0; i < n; i++){
        if (visited[i] == 0) dfs(i, -1);
    }

    visited.resize(0); visited.resize(n,0);

    for (int i = 0; i < cycles.size(); i++){
        for(int j : cycles[i]){
            whichcycle[j] = i;
        }
        first = cycles[i][0];
        newdfs(first, -1);
    }
    return 0;
}

int main(){
    fastio;
    cin >> n >> m;
    graph.resize(n); visited.resize(n,0); lowlink.resize(n,0); depth.resize(n,0); whichcycle.resize(n,-1);
    for(int i = 0; i < m; i++){
        int p,q;
        cin >> p >> q;
        graph[p-1].push_back({q-1,i+1}); graph[q-1].push_back({p-1,i+1});
    }
    dfs(0,-1);
    findcycle();
    if(ans.empty()) cout << 0 << endl;
    else{
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i: ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}