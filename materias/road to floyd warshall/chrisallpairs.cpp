#include<bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t, q;
    bool st = true;
    while (cin >> n >> t >> q) {
        if (n + t + q == 0) exit(0);
        const lint inf = 1LL << 62;
        vector<vector<lint>> m(n, vector<lint>(n, inf));
        for (int i = 0; i < n; ++i) m[i][i] = 0;
        for (int i = 0; i < t; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            m[a][b] = min(m[a][b], 1ll*c);
        }
        for (int i = 0; i < n; ++i) m[i][i] = min(m[i][i], {});
        for (int k = 0; k < n; ++k) 
            for (int i = 0; i < n; ++i) 
                for (int j = 0; j < n; ++j)
                    if (m[i][k] != inf && m[k][j] != inf) {
                        auto newDist = max(m[i][k] + m[k][j], -inf);
                        m[i][j] = min(m[i][j], newDist);
                    }
        for (int k = 0; k < n; ++k) if (m[k][k] < 0) 
            for (int i = 0; i < n; ++i) 
                for (int j = 0; j < n; ++j)
                    if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
        for (int i = 0; i < q; ++i) {
            int u, v;
            cin >> u >> v;
            if (m[u][v] == inf) cout << "Impossible\n";
            else if (m[u][v] == -inf) cout << "-Infinity\n";
            else cout << m[u][v] << '\n';
        }
        cout << '\n';
    }
}