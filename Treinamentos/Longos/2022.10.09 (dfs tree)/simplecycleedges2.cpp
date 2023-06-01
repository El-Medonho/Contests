#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define pb push_back 
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n,m;
vector<vector<pair<int,int>>> graph;
vector<int> lowlink, depth, visited;
vector<set<int>> comp_conexas;
vector<int> ans;
int tempo = 0;
int redo = 1;

void dfs(int curr, int last){
    lowlink[curr] = depth[curr] = ++tempo;

    for(pair<int,int> i: graph[curr]){
        int next = i.f;
        if(next == last) continue;
        if(lowlink[next] != -1){
            lowlink[curr] = min(lowlink[curr], depth[next]);
            continue;
        } 
        dfs(next, curr);
        lowlink[curr] = min(lowlink[curr], lowlink[next]);
    }
}

void priodepthdfs(int curr, int last){
    visited[curr] = 1;
    priority_queue<pair<int,int>> pq;

    for(pair<int,int> i: graph[curr]){
        int next = i.f;
        if(next == last) continue;
        if(visited[next] == 1){
            lowlink[curr] = min(lowlink[curr], depth[next]);
            continue;
        } 
        pq.push({depth[next], next});
    }

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        priodepthdfs(u, curr);
        lowlink[curr] = min(lowlink[curr], lowlink[u]);
    }
}

void priolinkdfs(int curr, int last, int fator){
    visited[curr] = 1;
    priority_queue<pair<int,int>> pq;
    int currlowlink = lowlink[curr];

    for(pair<int,int> i: graph[curr]){
        int next = i.f;
        if(next == last) continue;
        if(visited[next] == 1){
            lowlink[curr] = min(lowlink[curr], depth[next]);
            continue;
        } 
        pq.push({fator*lowlink[next], next});
    }

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        priolinkdfs(u, curr, fator);
        lowlink[curr] = min(lowlink[curr], lowlink[u]);
    }
    if(lowlink[curr] != currlowlink) redo = 1;
}

void priolinkmalucodfs(int curr, int last, int fator){
    visited[curr] = 1;
    priority_queue<pair<int,int>> pq;
    int currlowlink = lowlink[curr];

    for(pair<int,int> i: graph[curr]){
        int next = i.f;
        if(next == last) continue;
        if(visited[next] == 1){
            lowlink[curr] = min(lowlink[curr], depth[next]);
            continue;
        } 
        pq.push({fator*lowlink[next], next});
    }

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        priolinkmalucodfs(u, curr, -fator);
        lowlink[curr] = min(lowlink[curr], lowlink[u]);
    }
    if(lowlink[curr] != currlowlink) redo = 1;
}

void dfscaller(){
    for(int i = 0; i < n; i++){
        if(lowlink[i] == -1) dfs(i,-1);
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == 0) priodepthdfs(i, -1);
    }
    while(redo == 1){
        redo = 0;
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) priolinkdfs(i, -1, 1);
        }
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) priolinkdfs(i, -1, -1);
        }
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) priolinkmalucodfs(i, -1, 1);
        }
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) priolinkmalucodfs(i, -1, -1);
        }
}

}

void montarcomponentes(){
    for(int i = 0; i < n; i++){
        comp_conexas[lowlink[i]-1].emplace(i);
        comp_conexas[depth[i]-1].emplace(i);
    }
}

bool cyclefinder(int curr, int last, int primeiro, int currlowlink){
    if(curr == primeiro && last != -1) return true;
    int thenextone = -1;
    int numnum = -1;
    int sum = 0;
    for(pair<int,int> g: graph[curr]){
        int next = g.f;
        if(next == last) continue;
        if(depth[next] == currlowlink || lowlink[next] == currlowlink){
            sum++;
            thenextone = next;
            numnum = g.s;
        }
    }
    if ((sum != 1 && last != -1) || (sum != 2 && last == -1)) return false;
    bool k = cyclefinder(thenextone, curr, primeiro, currlowlink);
    if(k) ans.pb(numnum);
    return k;
}


int main(){
    fastio;

    cin >> n >> m;
    lowlink.resize(n,-1); depth.resize(n,-1); visited.resize(n,0);
    graph.resize(n); comp_conexas.resize(n);

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a-1].pb({b-1,i+1}); graph[b-1].pb({a-1,i+1});
    }

    dfscaller();
    montarcomponentes();

    for(int i = 0; i < n; i++){
        if (comp_conexas[i].size() > 1){
            int u = 0;
            for(int g: comp_conexas[i]){
                if(u == 0) cyclefinder(g,-1,g,i+1);
                u++;
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if(ans.size() > 0){
        for(int g : ans) cout << g << " ";
        cout << endl;
    }
    return 0;
}