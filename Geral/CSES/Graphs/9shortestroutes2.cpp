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

vector<vll> best(0);

int n,m,q;
vector<vector<pii>> graph(0);

void djikstra(int begin){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,begin});

    vii visited(n,0);
    vll weight(n, INFL);

    while(!pq.empty()){
        pll curr = pq.top();
        pq.pop();
        if(visited[curr.s] == 1) continue;
        best[begin][curr.s] = curr.f;
        // if(curr.s == end) return curr.f;
        visited[curr.s] = 1;
        
        for(pii j: graph[curr.s]){
            if(weight[j.s] > j.f + curr.f){
                weight[j.s] = j.f + curr.f;
                pq.push({weight[j.s], j.s});
                continue;
            }
        }
    }
    // return best[begin][end] =-1;
    return;
}


int main(){
    fastio;

    cin >> n >> m >> q;
    graph.resize(n);

    while(m--){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].pb(make_pair(c,b));
        graph[b].pb(make_pair(c,a));
    }

    for(int i = 0; i < n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    best.resize(n, vll(n, -1));

    for(int i = 0; i < n; i++){
        djikstra(i);
    }

    while(q--){
        int a,b; cin >> a >> b; a--; b--;
        // if(best[a][b] == -2) cout << djikstra(a,b) << endl;
        cout << best[a][b] << endl;
    }



    return 0;
}