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

int main(){
    fastio;

    int n, obj; cin >> n >> obj; obj--;
    vector<vii> graph(n);

    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    queue<int> q; q.push(obj);

    vii dist(n,-1); dist[obj] = 0;
    while(!q.empty()){
        int curr = q.front(); q.pop();

        for(int j: graph[curr]){
            if(dist[j] == -1){
                dist[j] = dist[curr]+1;
                q.push(j);
            }
        }
    }

    vii best(n,0);

    auto dfs = [&](int u, int p, auto &self) -> int{
        if(u != 0)best[u] = best[p]+1;
        else best[u] = 0;
        for(int j: graph[u]){
            if(j == obj){
                cout << best[u]+1 << endl;
                return 0; 
            }
        }
        for(int j: graph[u]){
            if(j == p) continue;
            if(dist[u] < dist[j]){
                best[u] += (self(j,u,self) - best[u]) + 1;
            }
        }
        for(int j:graph[u]){
            if(j == p) continue;
            if(dist[u] > dist[j]){
                self(j,u,self);
            }
        }
        return best[u];
    };

    dfs(0,-1,dfs);



    return 0;
}