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
int n,m;
vector<vii> graph(0);
vector<vii> oggraph(0);
vector<vii> cap(0);
vector<vii> rescap(0);

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
    vii counting(n+2,0);
    cap.resize(n+2, vii(n+2,0));
    graph.resize(n+2);
    oggraph.resize(n+2, vii(n+2,0));

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b; 
        graph[a].pb(b);
        oggraph[a][b]++;
        counting[a]++;
        // graph[b].pb(a);
    }

    graph[0].pb(1);
    graph[n].pb(n+1);   counting[n]++;

    for(int i = 0; i <= n; i++){
        for(int j: graph[i]){
            cap[i][j] = 1;
        }
    }
    cap[0][1] = counting[1];

    cap[n][n+1] = INF;

    for(int i = 0; i <= n+1; i++){
        for(int j: graph[i]){
            graph[j].pb(i);
        }
    }

    rescap = cap;
}

int main(){
    fastio;

    cin >> n >> m;

    setgraph();
    n+=2;
    cout << maxflow(0,n-1) << endl;

    while(true){
        int curr = 1;
        vii ans(0);

        while(curr != n-2){
            bool done = false;
            ans.pb(curr);
            for(int j: graph[curr]){
                if(oggraph[curr][j] && rescap[curr][j] == 0){
                    done = true;

                    oggraph[curr][j]--;
                    curr = j; 
                    break;
                }
            }
            if(!done) return 0;
        }
        ans.pb(n-2);
        cout << ans.size() << endl;
        for(int x: ans) cout << x << esp;
        cout << endl;
    }

    return 0;
}