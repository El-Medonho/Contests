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
vii cap(0);
vii rescap(0);

ll bfs(int s, int t, vector<pii> &parent){
    fill(parent.begin(), parent.end(), make_pair(-1,-1));
    parent[s] = {-2,-2};

    queue<pll> q;
    q.push({s,INFL});

    while(!q.empty()){
        int curr = q.front().f;
        int flow = q.front().s;
        q.pop();

        for(pii g: graph[curr]){
            int j = g.f;
            if(parent[j].f == -1 && rescap[g.s]){
                parent[j] = {curr,g.s};
                ll newflow = min(flow, rescap[g.s]);
                if(j == t) return newflow;
                q.push({j, newflow});
            }
        }
    }

    return 0;
}

ll maxflow(int s, int t){
    ll flow = 0;
    vector<pii> parent(n);
    int newflow;

    while(newflow = bfs(s,t,parent)){
        flow += newflow;
        int curr = t;
        while(curr != s){
            int prev = parent[curr].f;
            int edge = parent[curr].s;

            ll currflow = newflow;
            if(edge % 2 == 1) {currflow*=(-1); edge--; };

            rescap[edge] -= currflow;
            rescap[edge+1] += currflow;

            curr = prev;
        }
    }
    return flow;
}

void setgraph(){
    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].pb({b,i*2});
        graph[b].pb({a,i*2+1});
        cap[2*i] = c;
        cap[2*i+1] = 0;
    }

    rescap = cap;
}



int main(){
    fastio;

    cin >> n >> m;
    
    graph.resize(n);
    cap.resize(2*m);

    setgraph();

    cout << maxflow(0,n-1) << endl;

    return 0;
}