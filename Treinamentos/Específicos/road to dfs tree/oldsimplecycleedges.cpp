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
vector<int> visited; vector<int> lowlink; vector<int> depth; vector<vector<int>> cycles; vector<int> freq;
vector<int> ans;
int tempo = 0;
int linking = 0; int first = 0;
int n,m;

int dfs(int curr, int last){
    visited[curr] = 1;
    lowlink[curr] = depth[curr] = ++tempo;

    for(pair<int,int> next: graph[curr]){
        if(next.f != last && visited[next.f] == 1){
            lowlink[curr] = min(lowlink[curr], depth[next.f]);
            continue;
        }
        if(visited[next.f] == 1) continue;
        dfs(next.f,curr);
        lowlink[curr] = min(lowlink[curr], lowlink[next.f]);
    }
    return 0;
}

int simplecycle(int curr, int last){
    int sum = 0;

    if(visited[curr] == 1) return 1;

    if(curr == first) visited[curr] = 1;

    int tocycle = 0;

    int numnum = 0;
    for(pair<int,int> next : graph[curr]){
        if ((lowlink[next.f] != linking && depth[next.f] != linking) || next.f == last) continue;
        sum++;
        tocycle = next.f; 
        numnum = next.s;
    }
    if (curr == first) sum--;
    if (sum >= 2) return 0;
    int u = simplecycle(tocycle, curr);
    if (u == 1) ans.push_back(numnum);
    return u;  
    
}

int cyclefinder(){
    for(int i = 0; i < n; i++){
        if(visited[i] == 0) dfs(i,-1);
    }

    freq.resize(n,0); visited.resize(0); visited.resize(n,0);

    for(int i = 0; i < n; i++){
        if (lowlink[i] != depth[i] && freq[lowlink[i]-1] == 0) {
            freq[lowlink[i]-1]++;
            linking = lowlink[i];
            first = i;
            simplecycle(i, -1);
        }
    }
    return 0;
}

int main(){
    fastio;
    cin >> n >> m;
    graph.resize(n); visited.resize(n,0); lowlink.resize(n,0); depth.resize(n,0); cycles.resize(n); freq.resize(n,0);
    for(int i = 0; i < m; i++){
        int p,q;
        cin >> p >> q;
        graph[p-1].push_back({q-1,i+1}); graph[q-1].push_back({p-1,i+1});
    }
    cyclefinder();
    if(ans.empty()) cout << 0 << endl;
    else{
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i: ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}