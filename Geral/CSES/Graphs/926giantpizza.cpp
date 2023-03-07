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
vector<int> visited(0), compind(0);
stack<int> stk1, stk2;
int comp = 0;

vector<char> ans(0);

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

bool kosaraju(){
    visited.resize(2*n,0); compind.resize(2*n,0);

    for(int i = 0; i < 2*n; i++){
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

    for(int i = 0; i < n; i++){
        if(compind[2*i] == compind[2*i+1] && compind[2*i] != 0) return false;
    }

    ans.resize(n, '-');

    for(int i = 0; i < n; i++){
        if(compind[2*i+1] > compind[2*i]) ans[i] = '+';
    }

    return true;
}

int main(){
    fastio;

    cin >> m >> n;
    graph.resize(2*(n));
    revgraph.resize(2*(n));

    for(int i = 0; i < m; i++){
        char a,c; 
        int b,d;
        cin >> a >> b >> c >> d; b--; d--;

        graph[(2*b) ^ (a == '-')].pb((2*d) ^ (c == '+'));
        graph[(2*d) ^ (c == '-')].pb((2*b) ^ (a == '+'));

        revgraph[(2*b) ^ (a == '+')].pb((2*d) ^ (c == '-'));
        revgraph[(2*d) ^ (c == '+')].pb((2*b) ^ (a == '-'));
    }

    if(!kosaraju()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i = 0; i < n-1; i++){
        cout << ans[i] << esp;
    } cout << ans[n-1] << endl;

    return 0;
}