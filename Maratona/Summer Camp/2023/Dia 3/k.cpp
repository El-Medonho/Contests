#include <bits/stdc++.h>
#define mxn 100005
#define mxm 100005

using namespace std;
using pii = pair<int,int>;

vector<vector<int>> adjacencies;
set<pii> artifact;

vector<bool> vis, fromB, b2b, fromA;
bool ans = false;
int a, b;

void dfs(int node, int father) {
    vis[node] = true;
    if(b2b[father] == true && b2b[node] == false) b2b[node] = true;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            dfs(adj, node);
        }
        if(adj != father) fromB[node] = fromB[adj] || fromB[node];
        if(adj != father && b2b[node] == true) fromA[node] = fromA[adj] || fromA[node];
    }
}

int main(){
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    adjacencies.resize(n+1);
    vis.resize(n+1, false);
    fromB.resize(n+1, false);
    fromA.resize(n+1, false);
    b2b.resize(n+1, false);

    for(int i = 0, xi, yi, zi; i < m; i++) {
        cin >> xi >> yi >> zi;
        adjacencies[xi].push_back(yi);
        adjacencies[yi].push_back(xi);
        if(zi == 1) {
            artifact.emplace(xi, yi);
            artifact.emplace(yi, xi);
        }
    }

    cin >> a >> b;
    fromA[a] = b2b[b] = fromB[b] = true;
    dfs(a, 0);

    for(auto art : artifact) {
        if(fromB[art.first] && fromB[art.second] ||
           (fromA[art.first] && b2b[art.first]) && (fromA[art.second] && b2b[art.second])) {
            ans = true;
            break;
        }
    }

    if(ans == true) cout << "YES\n";
    else cout << "NO\n";
}
	 	 					  	 	   	   	   		  	