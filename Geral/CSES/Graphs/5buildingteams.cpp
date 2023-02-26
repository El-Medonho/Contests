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
vii visited(0);

bool bfs(int begin){
    fastio;
    queue<int> q;
    visited[begin] = 0;
    q.push(begin);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int j: graph[curr]){
            if(visited[j] == -1){
                visited[j] = (visited[curr] + 1) % 2;
                q.push(j);
            }
            else if(visited[j] == visited[curr]) return false;
        }
    }
    return true;
}

int main(){
    fastio;

    cin >> n >> m;
    graph.resize(n); visited.resize(n,-1);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == -1){
            if(!bfs(i)){
                cout << "IMPOSSIBLE" << endl;
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        cout << visited[i]+1 << esp;
    }
    cout << (*visited.rbegin())+1 << endl;

    return 0;
}