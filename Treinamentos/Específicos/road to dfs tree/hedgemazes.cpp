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

int rooms, corridors, querries; vector<vector<int>> graph(rooms);
vector<int> lowlink, depth, visited, parent;
vector<vector<int>> islinear; 
int tempo = 0;


int dfs(int curr, int last){

    visited[curr] = 1;
    lowlink[curr] = depth[curr] = ++tempo;

    for(int next : graph[curr]){
        if (visited[next] != 0 && next != last){
            lowlink[curr] = min(lowlink[curr], depth[next]);
            continue;
        }
        if (next == last) continue;
        parent[next] = curr;
        dfs(next, curr);
        lowlink[curr] = min(lowlink[curr], lowlink[next]);
    }
    return 0;
}

int bridge_search(){
    for (int i = 0; i < rooms; i++){
        if (visited[i] == 0) dfs(i,-1);
    }

    for(int i = 0; i < rooms; i++){
        if (lowlink[i] == depth[i] && parent[i] != -1){
            islinear[i].push_back(parent[i]); islinear[parent[i]].push_back(i);
        } 
    }
    return 0;
}

int check(int curr, int last, int obj){
    if(curr == obj) return 1;
    for(int i : islinear[curr]){
        if (i == last) continue;
        if (check(i, curr, obj) == 1) return 1;
    }
    return 0;
}

int main(){
    fastio;
    while(true){
        graph.resize(0); lowlink.resize(0); depth.resize(0); visited.resize(0); islinear.resize(0); parent.resize(0);
        cin >> rooms >> corridors >> querries;
        graph.resize(rooms); lowlink.resize(rooms); depth.resize(rooms); visited.resize(rooms); islinear.resize(rooms); parent.resize(rooms, -1);
        if (rooms == 0) return 0;
        for (int i = 1; i < corridors+1; i++){
            int j = 0; int f = 0;
            cin >> j >> f;
            graph[j-1].push_back(f-1); graph[f-1].push_back(j-1);
        }

        bridge_search();
        int f,s;
        for(int i = 0; i < querries; i++){
            cin >> s >> f;
            int u = check(s-1,-1,f-1);
            if (u == 1) cout << "Y" << endl;
            else cout << "N" << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}