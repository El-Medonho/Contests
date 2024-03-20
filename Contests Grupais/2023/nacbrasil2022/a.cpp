#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pb push_back

int main(){
    fastio;

    int n; cin >> n;

    vector<vector<int>> graph(n, vector<int>(0)), revgraph(n, vector<int>(0)), visited(n, vector<int> (n,0));

    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[i].pb(a);
        graph[i].pb(b);
        revgraph[a].pb(i);
        revgraph[b].pb(i);
    }

    function<void(int,int)> bfs;

    bfs = [&](int in, int parent){
        fill(visited[in].begin(), visited[in].end(), 0);
        queue<int> qw;
        qw.push(in); if(parent != -1)visited[in][parent] = 1; visited[in][in] = 1;

        while(!qw.empty()){
            int curr = qw.front(); qw.pop();

            for(int j: revgraph[curr]){
                if(j == parent || visited[in][j]) continue;
                qw.push(j);
                visited[in][j] = 1;
            }
        }
    };

    vector<int> resp(n,0);
    for(int i = 0; i < n; i++){
        for(int j: graph[i]) bfs(j,i);
        bfs(i,-1);
        
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if(visited[i][j] && visited[graph[i][0]][j] && visited[graph[i][1]][j]){
                resp[i] = 1;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(resp[i]) cout << "Y";
        else cout << "N";
    }
    cout << endl;

    return 0;
}