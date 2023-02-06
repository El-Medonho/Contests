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

int cont;
int main(){
    vector<int> answ(0);
    fastio;
    while(true){
    int n,r;
    cin >> n >> r;
    if(n == 0 && r == 0) break;

    vector<vector<int>> temp(r);
    for(int i = 0; i < r; i++){
        int a,b,c; cin >> a >> b >> c; c--;
        temp[i] = {a,b,c};
    }
    int start, end, tour; cin >> start >> end >> tour; start--; end--;
    vector<vector<pair<int,int>>> roads(n); vector<int> dist(n,INF);
    for(int i = 0; i < r;i++){
        roads[temp[i][0]-1].pb({temp[i][1]-1, ceil(double(tour)/double(temp[i][2]))});
        roads[temp[i][1]-1].pb({temp[i][0]-1, ceil(double(tour)/double(temp[i][2]))});
        // cout << ceil(double(tour)/double(temp[i][2])) << endl;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pii> > pq;
    vector<int> visited(n,0);
    pq.push({0, start});
    dist[start] = 0;
    int ans = -1;
    while(!pq.empty()){
        if(pq.top().s == end) {ans = pq.top().f; break;}
        pii curr = pq.top();
        pq.pop();
        if(visited[curr.s] == 1) continue;
        visited[curr.s] = 1;
        for(pii i: roads[curr.s]){
            // cout << dist[i.f] << es << es << dist[curr.s] << es << i.s << endl;
            if(dist[i.f] > max(dist[curr.s], i.s)){
                // cout << pq.top().s << endl;
                dist[i.f] = max(dist[curr.s], i.s);
                pq.push({dist[i.f],i.f});
            }
        }
    }
    // cout << ans << endl;
    answ.pb(ans);
    }
    for(int x: answ){
        cout << "Scenario #" << ++cont << endl;
        cout << "Minimum Number of Trips = " << x << endl;
        cout << endl;
    }
}