#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n,m;
vector<vector<int>> graph;
vector<int> visited; vector<int> lowlink; vector<int> depth; vector<int> parent;
int sum = -1; int tempo = 0; vector<int> record1 = {0,0,0};
pair<pair<int,int>, pair<int,int>> record = {{0,0},{0,0}};


int dfs(int curr, int last){ //fzr dfs normal
    visited[curr] = 1;
    parent[curr] = last;
    lowlink[curr] = depth[curr] = ++tempo;
    bool check_dual_connection = false;
    for(int next : graph[curr]){
        if((next != last || check_dual_connection) && visited[next] == 1){
            lowlink[curr] = min(lowlink[curr], depth[next]); continue;
        }
        if (next == last) check_dual_connection = true;
        if(visited[next] == 1) continue;
        dfs(next,curr);
        lowlink[curr] = min(lowlink[next], lowlink[curr]);
    }
    return 0;
}

pair<int,int> dfs_sum(int curr, int last, int sum){  //dfs apos achar as bridges
    visited[curr] = 1;

    int soma = sum;
    //aqui entra a logica de achar a soma
    if (curr != 0) {if (depth[curr] == lowlink[curr]) soma+=1;}  

    // cout << soma << " " << curr+1 << endl;

    pair<pair<int, int>,pair<int, int>> best = {{0, curr}, {0,curr}};

    for(int next: graph[curr]){
        if(visited[next] == 1) continue;
        pair<int,int> deviation = {0,0};
        deviation = dfs_sum(next, curr, soma); int comparador = deviation.f;

        if (comparador >= best.f.f) {
            best.s = {best.f.f, best.f.s};
            best.f = {comparador, deviation.s};
        }
        else if(comparador > best.s.f) {best.s = {comparador, deviation.s};} 
    }
    pair<pair<int,int>, pair<int,int>> bestobest = {{0,0},{0,0}};
    if(soma >= best.f.s)  bestobest = {{soma,0}, best.f};
    else bestobest = {best.f, best.s};
    if (bestobest.f.f + bestobest.s.f > record1[0]) record1 = {bestobest.f.f + bestobest.s.f, bestobest.f.s, bestobest.s.s};
    return {best.f.f + (soma-sum), best.f.s};
}

int main(){
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    fastio;
    cin >> n >> m;
    graph.resize(n); visited.resize(n,0); lowlink.resize(n,0); depth.resize(n,0); parent.resize(n,0);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1); graph[b-1].push_back(a-1);
    }
    dfs(0,-1);
    visited.resize(0); visited.resize(n,0);
    dfs_sum(0,-1,0);
    cout << (record1[1]+1) << " " << (record1[2]+1) << endl;

    return 0;
}