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

//O(V.E²)
int n,m,k;
int aa,bb,cc;
vector<vii> graph(0);
vector<vii> cap(0);
vector<vii> rescap(0);

vector<pii> ans(0);

ll bfs(int s, int t, vii &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pll> q;
    q.push({s,INFL});

    while(!q.empty()){
        int curr = q.front().f;
        int flow = q.front().s;
        q.pop();

        for(int j: graph[curr]){
            if(parent[j] == -1 && rescap[curr][j]){
                parent[j] = curr;
                ll newflow = min(flow, rescap[curr][j]);
                if(j == t) return newflow;
                q.push({j, newflow});
            }
        }
    }

    return 0;
}

void pairs(){

    for(int i = 1; i <= aa; i++){
        if(rescap[0][i] == 0){
            for(int j: graph[i]){
                if(j == 0) continue;
                if(rescap[i][j] == 0) ans.pb(make_pair(i, j-aa));
            }
        }
    }
}

ll maxflow(int s, int t){
    ll flow = 0;
    vii parent(n);
    int newflow;

    while(newflow = bfs(s,t,parent)){
        flow += newflow;
        int curr = t;
        while(curr != s){
            int prev = parent[curr];

            ll currflow = newflow;

            rescap[prev][curr] -= currflow;
            rescap[curr][prev] += currflow;

            curr = prev;
        }
    }
    return flow;
}

void setgraph(){
    cap.resize(n, vii(n,0));
    graph.resize(n);

    for(int i = 1; i <= aa; i++){
        graph[0].pb(i);
        graph[i].pb(0);
        cap[0][i] = 1;
    }
    for(int i = aa+1; i < aa+bb+1; i++){
        graph[i].pb(aa+bb+1);
        graph[aa+bb+1].pb(i);
        cap[i][aa+bb+1] = 1;
    }

    for(int i = 0; i < cc; i++){
        int a,b,c; cin >> a >> b; b += aa;
        if(cap[a][b] == c) continue;
        c = 1;
        graph[a].pb(b);
        graph[b].pb(a);
        cap[a][b] = c;
        cap[b][a] = 0;
    }

    rescap = cap;
}

int main(){
    fastio;


    cin >> aa >> bb >> cc;
    n = aa+bb+2;
    m = aa+bb+cc;

    setgraph();
    cout << maxflow(0,aa+bb+1) << endl;
    for(pii x: ans){
        cout << x.f << esp << x.s << endl; 
    }

    return 0;
}