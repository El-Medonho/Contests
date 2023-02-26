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

    int n,m; cin >> n >> m;
    vector<vector<pii>> graph(n);

    while(m--){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].pb(make_pair(c,b));
    }
    for(int i = 0; i < n; i++) sort(graph[i].begin(), graph[i].end());

    priority_queue<pll, vector<pll>, greater<pll>> pq, pqhalf;
    pq.push(make_pair(0,0));

    vll weight(n, INFL), weighthalf(n, INFL);
    weight[0] = 0; weighthalf[0] = 0;

    vii visited(n,0);

    while(!pq.empty()){
        pll curr = pq.top();
        pq.pop();
        if(visited[curr.s]) continue;
        visited[curr.s] = 1;

        for(pii j: graph[curr.s]){
            if(weight[j.s] >= weight[curr.s] + j.f){
                weight[j.s] = weight[curr.s] + j.f;
                pq.push({weight[j.s], j.s});
            }
            if(weighthalf[j.s] >= weight[curr.s] + (j.f/2)){
                weighthalf[j.s] = weight[curr.s] + (j.f/2);
                pqhalf.push({weighthalf[j.s], j.s});
            }
        }
    }

    for(int i = 0; i < n; i++) visited[i] = 0;

    while(!pqhalf.empty()){
        pll curr = pqhalf.top();
        pqhalf.pop();
        if(curr.s == n-1){
            cout << curr.f << endl;
            return 0;
        }
        if(visited[curr.s]) continue;
        visited[curr.s] = 1;

        for(pii j: graph[curr.s]){
            if(weighthalf[j.s] >= weighthalf[curr.s] + j.f){
                weighthalf[j.s] = weighthalf[curr.s] + j.f;
                pqhalf.push({weighthalf[j.s], j.s});
            }
        }
    }

    return 0;
}