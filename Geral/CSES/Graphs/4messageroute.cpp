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
vii layer(0);

void bfs(){
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int j: graph[curr]){
            if(layer[j] == -1){
                layer[j] = layer[curr]+1;
                q.push(j);
            }
        }
    }
    return;
}


int times = -1;
vii ans(0);
stack<int> answ;
bool dfs(int curr){
    times++;
    answ.push(curr+1);
    if(curr == n-1) return true;
    if(layer[curr] < times) return false;

    for(int j: graph[curr]){
        if(times+1 > layer[j]) continue;
        if(dfs(j)) return true;
    }
    times--;
    answ.pop();
    return false;
}

int main(){
    fastio;

    cin >> n >> m;
    graph.resize(n);
    layer.resize(n,-1);
    layer[0] = 0;

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bfs();
    if(layer[n-1] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    
    dfs(0);
    ans.resize(answ.size()); int ggg = answ.size()-1;
    while(!answ.empty()){
        ans[ggg] = answ.top();
        answ.pop(); ggg--;
    }

    cout << layer[n-1]+1 << endl;
    for(int i = 0; i < ans.size()-1; i++){
        cout << ans[i] << esp;
    }
    cout << ans[ans.size()-1] << endl;

    return 0;
}