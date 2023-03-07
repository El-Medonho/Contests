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
vector<vii> graph(0), revgraph(0); 
vii visited(0);
stack<int> stk1, stk2;
vii compind(0);
int comp = 0;

void dfs1(int curr){
    visited[curr] = 1;
    for(int j: graph[curr]){
        if(!visited[j]){
            dfs1(j);
        }
    }
    stk1.push(curr);
}

void dfs2(int curr){
    visited[curr] = 0;
    compind[curr] = comp;

    for(int j: revgraph[curr]){
        if(visited[j]){
            dfs2(j);
        }
    }
    stk2.push(curr);
}

void kosaraju(){
    visited.resize(n,0); compind.resize(n,0);

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs1(i);
    }

    while(!stk1.empty()){
        int i = stk1.top();
        stk1.pop();

        if(visited[i]){
            comp++;
            dfs2(i);
        }
    }
}

int main(){
    fastio;

    cin >> n >> m;

    graph.resize(n); revgraph.resize(n);
    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        revgraph[b].pb(a);
    }

    kosaraju();

    cout << comp << endl;
    for(int i = 0; i < n-1; i++){
        cout << compind[i] << esp;
    }
    cout << compind[n-1] << endl;

    return 0;
}