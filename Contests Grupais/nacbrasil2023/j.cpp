#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::ios_base::sync_with_stdio(0), cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<map<int,int>> adjacencies(n+1);
    vector<map<int,set<int>>> wow(n+1);

    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        adjacencies[u][v] = 1;
        adjacencies[v][u] = 1;
        wow[u][1].insert(v);
        wow[v][1].insert(u);
    }

    for(int node = 1; node <= n; node++) {
        int next = node;

        if(!adjacencies[node].empty()) {
            next = *( wow[node].begin()->second.begin() );
        }

        cout << next << (node != n ? ' ' : '\n');

        for(auto [adj, w] : adjacencies[node]) {
            adjacencies[adj].erase(node);
            
            wow[adj][w].erase(node);
            if(wow[adj][w].empty()) wow[adj].erase(w);

            auto it = wow[node].begin()->second.upper_bound(adj);

            if(it != wow[node].begin()->second.end()) {
                adjacencies[adj][*it] = wow[node].begin()->first;

                wow[adj][wow[node].begin()->first].insert(*it);
            }
        }
    }
}