#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    vector<string> ans;
    bool first = false;
    while(true) {
        int n,m,q;
        cin >> n >> m >> q;
        if (n == 0) break;
        if (first) ans.push_back("\n");
        first = true;

        vector<vector<int>> edges;
        vector<vector<bool>> cycle;
        edges.resize(n);
        cycle.resize(n);

        for(int i = 0; i<n; i++) {
            edges[i].resize(n,INT32_MAX/2);
            cycle[i].resize(n,false);
            edges[i][i] = 0;
        }


        for(int i = 0; i<m; i++) {
            int u,v,q;
            cin >> u >> v >> q;
            edges[u][v] = q;
        }

        for(int i = 0; i<n; i++) {
            int a = min(0,edges[i][i]);
            if (a<0) cycle[i][i];
            if (a<0) edges[i][i] = -30000000;
            edges[i][i] = a;
        }

        // for(int i = 0; i<n; i++) edges[i][i] = 0;
            for(int k = 0; k<n; k++) {
                for(int i = 0; i<n; i++) {
                    for(int j = 0; j<n; j++) {
                        // if ((edges[i][i] < 0 || edges[j][j] < 0 || edges[k][k] < 0) && edges[i][j] != INT32_MAX/2) edges [i][j] = -30000000;
                        if(edges[i][k] == INT32_MAX/2 || edges[k][j] == INT32_MAX/2) continue;
                        if (i == j && edges[i][j] >= 0) edges[i][j] = min(min(0, edges[i][k] + edges[k][j]), edges[i][j]);
                        else edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
                    }
                }
            }

        for(int k = 0; k<n; k++) {
                for(int i = 0; i<n; i++) {
                    for(int j = 0; j<n; j++) {
                        if(edges[i][k] == INT32_MAX/2 || edges[k][j] == INT32_MAX/2) continue;
                        if ((edges[i][j]) > edges[i][k] + edges[k][j]) edges[i][j] = -30000000;
                    }
                }
            }

        for(int k = 0; k<n; k++) {
                for(int i = 0; i<n; i++) {
                    for(int j = 0; j<n; j++) {
                        if(edges[i][k] == INT32_MAX/2 || edges[k][j] == INT32_MAX/2) continue;
                        if ((edges[i][i] < 0 || edges[j][j] < 0 || edges[k][k] < 0)) edges [i][j] = -30000000;
                    }
                }
            }

        for(int i = 0; i<q; i++) {
            int u,v;
            cin >> u >> v;
            int a = edges[u][v];
            if (a == INT32_MAX/2) ans.push_back("Impossible\n");
            else if(a != -30000000) ans.push_back(to_string(a) + "\n");
            else ans.push_back("-Infinity\n");
        }
        // ans.push_back("\n");
        
        for(int i = 0; i<ans.size(); i++) {
            cout << ans[i];
        }
        ans.clear();
    }

    // for(int i = 0; i<ans.size(); i++) {
    //     cout << ans[i];
    // }
}