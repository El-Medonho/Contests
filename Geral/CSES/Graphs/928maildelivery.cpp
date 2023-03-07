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

int main(){
    fastio;

    int n,m; cin >> n >> m;

    vector<vector<pii>> graph(n);
    vii deg(n,0);
    vii ans(0);
    vii id(m,0);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(make_pair(b,i));
        graph[b].pb(make_pair(a,i));
    }

    for(int i = 0; i < n; i++){
        if(graph[i].size() % 2 == 1){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        deg[i] = graph[i].size();
    }

    stack<int> stk;
    stk.push(0);

    while(!stk.empty()){
        int v = stk.top();
        while(!graph[v].empty() && id[graph[v].back().s]){
            deg[v]--;
            graph[v].pop_back();
        }
        if(!deg[v]){
            ans.pb(v);
            stk.pop();
            continue;
        }
        pii u = graph[v].back();
        graph[v].pop_back();
        deg[v]--;
        id[u.s] = 1;
        stk.push(u.f);
    }

    if(ans.size() < m+1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i: ans) cout << i+1 << esp;
    cout << endl;

    return 0;
}