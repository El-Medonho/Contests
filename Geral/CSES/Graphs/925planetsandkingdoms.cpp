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
int comptempo = 0;
vii compindex(0);

void tarjan(int curr){
    depth[curr] = lowlink[curr] = ++tempo;
    stk.push(curr);
    visiting[curr] = 1;

    for(int i: graph[curr]){
        if(lowlink[i] == -1){
            
            tarjan(i);
            lowlink[curr] = min(lowlink[curr], lowlink[i]);

        }else if(visiting[i] == 1){

            lowlink[curr] = min(lowlink[curr], depth[i]);

        }
    }

    if(depth[curr] == lowlink[curr]){
        int u = -1;
        comptempo++;
        while(u != curr){
            u = stk.top(); stk.pop();
            visiting[u] = 0;
            compindex[u] = comptempo;
        }
    }

    return;
}

bool tarjancaller(){
    visiting.resize(n, 0); lowlink.resize(n, -1); depth.resize(n, -1); compindex.resize(n, 0);

    for(int i = 0; i < n; i++){
        if(lowlink[i] == -1){
            tarjan(i);
        }
    }
    return true;
}

int main(){
    fastio;

    cin >> n >> m;

    graph.resize(n);

    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
    }

    tarjancaller();

    cout << comptempo << endl;
    for(int i = 0; i < n-1; i++) cout << compindex[i] << esp;
    cout << compindex[n-1] << endl;

    return 0;
}