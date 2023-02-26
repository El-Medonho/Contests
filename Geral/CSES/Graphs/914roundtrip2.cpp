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
vector<vii> graph(0);
vii visiting(0), visited(0);
stack<int> stk;
vii ans(0);

int solve(){
    int beg = stk.top();
    ans.pb(beg); stk.pop();
    while(!stk.empty()){
        ans.pb(stk.top());
        if(stk.top() == beg) return 1;
        stk.pop();
    }
    return 1;
}

int dfs(int curr){
    stk.push(curr);

    if(visiting[curr] == 1) return solve();
    visiting[curr] = 1;

    for(int i: graph[curr]){
        if(visited[i] == 0) if(dfs(i)) return 1;
    }
    visiting[curr] = 0;
    visited[curr] = 1;
    stk.pop();
    return 0;
}

int dfscaller(){
    for(int i = 0; i < n; i++){
        if(visited[i] == 0) 
        if(dfs(i)) 
        return 1;
    }
    return 0;
}

int main(){
    fastio;

    cin >> n >> m;
    graph.resize(n); visiting.resize(n,0); visited.resize(n,0);
    while(m--){
        int a, b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
    }

    if(!dfscaller()){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(ans.rbegin(), ans.rend());

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size()-1; i++){
        cout << ans[i]+1 << esp;
    }
    cout << (*ans.rbegin())+1 << endl;

    return 0;
}