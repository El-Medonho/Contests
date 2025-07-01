#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;


vector<vector<int>> adjacencies;
vector<int> vis, comp;

void dfs(int node) {
    vis[node] = true;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            comp[adj] = comp[node];
            dfs(adj);
        }
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    adjacencies.resize(n);
    vis.resize(n);
    comp.resize(n);

    for(int u = 0; u < n; u++) {
        string line;
        cin >> line;
        for(int v = 0; v < n; v++) {
            if(line[v] == '1') {
                adjacencies[u].push_back(v);
                adjacencies[v].push_back(u);
            }
        }
    }

    for(int u = 0, count = 0; u < n; u++) {
        if(!vis[u]) {
            comp[u] = ++count;
            dfs(u);
        }
    }

    int e;
    cin >> e;

    while(e--) {
        int k;
        cin >> k;

        set<int> interview;

        for(int i = 0; i < k; i++) {
            int curr;
            cin >> curr;
            curr--;
            interview.insert(comp[curr]);
        }
        
        cout << (interview.size() != k ? "S" : "N") << '\n';
    }
}