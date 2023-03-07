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
vector<vector<pii>> graph(n);       //.f vizinho, .s id global da aresta
vii deg(0);
vii ans(0);
vii id(0);
vii val(0);

int euler(){

    deg.resize(n); id.resize(m,0);

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
            // ans.pb(val[v]);
            stk.pop();
            continue;
        }
        
        pii u = graph[v].back();
        graph[v].pop_back();
        deg[v]--;
        ans.pb(val[u.s]);
        id[u.s] = 1;
        stk.push(u.f);
    }

    // if(ans.size() < m+1){
    //     cout << "IMPOSSIBLE" << endl;
    //     return 0;
    // }

    

    for(int i: ans) cout << i;
    cout << endl;

    return 1;
}

int main(){
    fastio;

    int k; cin >> k;

    if(k == 1) {cout << 10 << endl; return 0;}

    n = 1;
    for(int i = 0; i < k-1; i++) n*=2;

    graph.resize(n);
    int cnt = -1;

    for(int i = 0; i < n; i++){
        int a = (i<<1);
        if(a & (1<<(k-1))) a = a ^ (1<<(k-1));

        cnt++;
        graph[i].pb(make_pair(a, cnt));
        val.pb(0);

        a = a ^ 1;
        cnt++;
        graph[i].pb(make_pair(a, cnt));
        val.pb(1);
    }

    m = cnt+1;

    for(int i = 0; i < k-1; i++) cout << 0;
    euler();

    return 0;
}