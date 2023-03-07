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

vector<vii> graph;
vii weight(0);
int root = 0, tsz = 0;

int dfs(int curr, int last){
    for(int j: graph[curr]){
        if(j == last) continue;
        weight[curr] += dfs(j,curr);
    }
    return weight[curr]+1;
}

void centroid(){
    bool cont = true;
    weight.resize(tsz,0);
    dfs(root, -1);
    int last = -1;
    while(cont){
        cont = false;
        for(int j: graph[root]){
            if(j == last) continue;
            if(weight[j] >= tsz/2){
                last = root;
                cont = true;
                root = j;
                break;
            }
        }
    }
    return;
}


int main(){
    fastio;

    int n; cin >> n; tsz = n;

    graph.resize(n);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    centroid();

    cout << root+1 << endl;

    return 0;
}