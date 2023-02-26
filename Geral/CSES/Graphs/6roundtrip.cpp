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
vector<vii> graph(0); vii visited(0);
stack<int> stk;

bool dfstree(int curr, int last){
    visited[curr] = 1;
    stk.push(curr);

    for(int j: graph[curr]){
        if(visited[j] == 1 && j != last){
            stk.push(j);
            return true;
        }
        if(visited[j] == 0){
            if(dfstree(j, curr)) return true;
        }
    }
    stk.pop();
    return false;
}

int main(){
    fastio;

    cin >> n >> m;
    visited.resize(n,0);
    graph.resize(n);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bool is = false;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0) is = dfstree(i, -1);
        if(is) break;
    }

    if(!is){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    int beg = stk.top();
    vii ans(0); ans.pb(beg);
    stk.pop();

    while(stk.top() != beg){
        ans.pb(stk.top());
        stk.pop();
    }
    ans.pb(beg);

    cout << ans.size() << endl;
    for(int j = 0; j < ans.size()-1; j++) cout << ans[j]+1 << esp;
    cout << (*ans.rbegin())+1 << endl;

    return 0;
}