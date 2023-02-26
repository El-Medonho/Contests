#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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
    vector<vector<pll>> graph(n);
    vector<set<int>> ancestors(n); vii visited(n,0); vll points(n,0); vii passed(n,0); vll weight(n,INFL);

    while(m--){
        ll a,b,c; cin >> a >> b >> c;
        graph[--a].pb(make_pair(c, --b));
    }
    for(int i = 0; i < n; i++) sort(graph[i].begin(), graph[i].end());

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        pll curr = pq.top(); pq.pop();
        if(passed[curr.s]) continue;
        passed[curr.s] = 1;

        for(pll j: graph[curr.s]){
            if(weight[j.s] > curr.f + j.f){
                weight[j.s] = curr.f + j.f;
                pq.push({weight[j.s], j.s});
            }
        }
    }

    cout << weight[n-1] << esp;
    pq.push({0,0});

    while(!pq.empty()){
        pll curr = pq.top(); pq.pop();
        
        for(pll j: graph[curr.s]){
            if(weight[j.s] == curr.f + j.f){
                if(visited[j.s] == 0) pq.push({weight[j.s], j.s});
                visited[j.s]++;
                ancestors[j.s].insert(curr.s);
            }
        }
    }

    points[0] = 1;

    queue<int> qw;
    qw.push(0);

    vector<pii> flights(n, make_pair(0,INFL));
    flights[0] = {0,0}; weight[0] = 0;

    while(!qw.empty()){
        int curr = qw.front(); qw.pop();

        for(pll g: graph[curr]){
            int j = g.s;
            if(ancestors[j].find(curr) != ancestors[j].end() && weight[j] == weight[curr] + g.f){
                visited[j]--;
                if(visited[j] == 0) qw.push(j);
                points[j] += points[curr];
                points[j] = mod(points[j], MOD); 
                flights[j].f = max(flights[j].f, flights[curr].f + 1);
                flights[j].s = min(flights[j].s, flights[curr].s + 1);
            }
        }
    }

    cout << points[n-1] << esp;
    cout << flights[n-1].s << esp;
    cout << flights[n-1].f << endl;

    return 0;
}