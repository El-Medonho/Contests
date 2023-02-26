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
vector<string> graph(0); 
vector<vii> layer(0); vector<vii> monster(0);

void bfsm(pii begin){
    monster[begin.f][begin.s] = 0;
    queue<pii> q;
    q.push(begin);

    while(!q.empty()){
        pii curr = q.front();
        int i = curr.f, j = curr.s;
        q.pop();

        if(i != 0 && graph[i-1][j] == 'M' && monster[i][j] > 2) continue;
        if(i != n-1 && graph[i+1][j] == 'M' && monster[i][j] > 2) continue;
        if(j != 0 && graph[i][j-1] == 'M' && monster[i][j] > 2) continue;
        if(j != m-1 && graph[i][j+1] == 'M' && monster[i][j] > 2) continue;
        
        if(i != 0 && graph[i-1][j] != 'M' && graph[i-1][j] != '#' && monster[i][j]+1 < monster[i-1][j]){q.push({i-1,j}); monster[i-1][j] = monster[i][j]+1;}
        if(i != n-1 && graph[i+1][j] != 'M' && graph[i+1][j] != '#' && monster[i][j]+1 < monster[i+1][j]){q.push({i+1,j}); monster[i+1][j] = monster[i][j]+1;}
        if(j != 0 && graph[i][j-1] != 'M' && graph[i][j-1] != '#' && monster[i][j]+1 < monster[i][j-1]){q.push({i,j-1}); monster[i][j-1] = monster[i][j]+1;}
        if(j != m-1 && graph[i][j+1] != 'M' && graph[i][j+1] != '#' && monster[i][j]+1 < monster[i][j+1]){q.push({i,j+1}); monster[i][j+1] = monster[i][j]+1;}
    }
}

bool bfs(pii begin){
    layer[begin.f][begin.s] = 0;
    queue<pii> q;
    q.push(begin);

    while(!q.empty()){
        pii curr = q.front();
        int i = curr.f, j = curr.s;
        if(i == 0 || i == n-1 || j == 0 || j == m-1) return true;
        q.pop();
        
        if(i != 0 && layer[i-1][j] == INF && graph[i-1][j] != '#' && layer[i][j]+1 < monster[i-1][j]){q.push({i-1,j}); layer[i-1][j] = layer[i][j]+1;}
        if(i != n-1 && layer[i+1][j] == INF && graph[i+1][j] != '#' && layer[i][j]+1 < monster[i+1][j]){q.push({i+1,j}); layer[i+1][j] = layer[i][j]+1;}
        if(j != 0 && layer[i][j-1] == INF && graph[i][j-1] != '#' && layer[i][j]+1 < monster[i][j-1]){q.push({i,j-1}); layer[i][j-1] = layer[i][j]+1;}
        if(i != m-1 && layer[i][j+1] == INF && graph[i][j+1] != '#' && layer[i][j]+1 < monster[i][j+1]){q.push({i,j+1}); layer[i][j+1] = layer[i][j]+1;}
    }
    return false;
}

int tempo = -1;
string ans = "";

bool dfs(pii curr){
    tempo++;
    int i = curr.f, j = curr.s;
    if(i == 0 || i == n-1 || j == 0 || j == m-1) return true;

    if(tempo+1 == layer[i-1][j]) {ans.pb('U'); if(dfs(make_pair(i-1,j))) return true;}
    if(tempo+1 == layer[i+1][j]) {ans.pb('D'); if(dfs(make_pair(i+1,j))) return true;}
    if(tempo+1 == layer[i][j-1]) {ans.pb('L'); if(dfs(make_pair(i,j-1))) return true;}
    if(tempo+1 == layer[i][j+1]) {ans.pb('R'); if(dfs(make_pair(i,j+1))) return true;}

    ans.pop_back();
    tempo--;
    return false;
}


int main(){
    fastio;

    cin >> n >> m;
    graph.resize(n);
    for(string &s: graph) cin >> s;

    layer.resize(n, vii(m,INF)); monster.resize(n, vii(m,INF));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) if(graph[i][j] == 'M') bfsm(make_pair(i,j));
    }

    bool is;
    pii beg;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) if(graph[i][j] == 'A') {beg = {i,j}; is = bfs(make_pair(i,j));}
    }

    if(!is){
        cout << "NO" << endl;
        return 0;
    }

    dfs(beg);

    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}