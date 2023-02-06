#include <bits/stdc++.h>
#include <queue>

#define mxn 200005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define es " "
#define endl "\n"
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

using namespace std;

int main(){
    fastio;


    int n,v;
    while(cin >> n >> v){
    vector<vector<pii>> roads(n);
    for(int i = 0; i < v; i++){
        int u,v,w; cin >> u >> v >> w;u--;v--;
        roads[u].pb({v,w});
        roads[v].pb({u,w});
    }
    vector<vector<int>> visited(n,{0,0}); vector<vector<int>> dist(n,{INF,INF});
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    pq.push({0,{0,0}});
    dist[0][0] = 0;
    int ans = -1;

    while(!pq.empty()){
        if(pq.top().s.s == n-1 && pq.top().s.f == 0) {ans = pq.top().f; break;}

        pair<int,pii> curr = pq.top();
        pq.pop();
        if(visited[curr.s.s][curr.s.f] == 1) continue;
        visited[curr.s.s][curr.s.f] = 1;
        
        for(pii next: roads[curr.s.s]){
            if(dist[next.f][0] > dist[curr.s.s][1] + next.s && curr.s.f == 1){
                dist[next.f][0] = dist[curr.s.s][1] + next.s;
                pq.push({dist[next.f][0], {0,next.f}});
            }
        }

        for(pii next: roads[curr.s.s]){
            if(dist[next.f][1] > dist[curr.s.s][0] + next.s && curr.s.f == 0){
                dist[next.f][1] = dist[curr.s.s][0] + next.s;
                pq.push({dist[next.f][1], {1, next.f}});
            }
        }
    }
    cout << ans << endl;
    }
}