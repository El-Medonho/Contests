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
vector<vii> graph(0); vii visiting(0), lowlink(0), depth(0);
int tempo = 0;
stack<int> stk;

void tarjan(int curr){
    depth[curr] = lowlink[curr] = ++tempo;
    stk.push(curr);
    visiting[curr] = 1;

    for(int i: graph[curr]){
        if(lowlink[i] == -1){
            
            tarjan(i);
            lowlink[curr] = min(lowlink[curr], lowlink[i]);

        }else if(visiting[curr] = 1){

            lowlink[curr] = min(lowlink[curr], depth[i]);

        }
    }

    if(depth[curr] == lowlink[curr]){
        int u = -1;
        while(u != curr){
            u = stk.top(); stk.pop();
            visiting[curr] = 0;
        }
    }

    return;
}

int n1,n2;

bool tarjancaller(){
    tarjan(0);
    for(int i = 1; i < n; i++){
        if(lowlink[i] == -1){
            n1 = 0; n2 = i;
            return false;
        }
    }
    return true;
}

vii visited(0);
bool bfs(){
    visited.resize(n,0);
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int curr = q.front(); q.pop();
        visited[curr] = 1;
        if(curr = n2) return true;

        for(int i: graph[curr]){
            if(visited[i] != 1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return false;
}

int main(){
    fastio;

    cin >> n >> m;
    graph.resize(n); visiting.resize(n,0); lowlink.resize(n,-1); depth.resize(n,-1);
    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
    }

    if(!tarjancaller()) {cout << "NO" << endl << n1+1 << esp << n2+1 << endl; return 0;}

    bool did = true;;
    for(int i = 1; i < n; i++){
        if(lowlink[i] == depth[i]){
            n1 = 0; n2 = i;
            did = false;
        }
    }

    if(did){ cout << "YES" << endl; return 0;}

    cout << "NO" << endl;
    if(bfs()) cout << n2+1 << esp << n1+1 << endl;
    else cout << n1+1 << esp << n2+1 << endl;

    return 0;
}