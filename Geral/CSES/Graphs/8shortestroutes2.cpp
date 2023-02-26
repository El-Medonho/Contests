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
vector<vector<pii>> graph(0);
vll weight(0);

int main(){
    fastio;

    cin >> n >> m;
    graph.resize(n); weight.resize(n, INFL);

    while(m--){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].pb(make_pair(b,c));
        // graph[b].pb(make_pair(a,c));
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,0});
    weight[0] = 0;
    vii visited(n,0);

    while(!pq.empty()){
        pll curr = pq.top();
        pq.pop();
        if(visited[curr.s] == 1) continue;
        visited[curr.s] = 1;

        for(pii flights: graph[curr.s]){
            if(weight[flights.f] > curr.f + flights.s){
                weight[flights.f] = curr.f + flights.s;
                pq.push({curr.f + flights.s, flights.f});
                continue;
            }
        }
    }

    for(ll i: weight) cout << i << esp;
    cout << endl;



    return 0;
}