#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    set<int> nl;
    for(int i = 0; i < b; i++) {
        int ing;
        cin >> ing;
        nl.insert(ing);
    }

    for(int step = 1; step <= n; step++) {
        int m;
        cin >> m;
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            int mi;
            cin >> mi;
            if(nl.count(mi) == 1) cnt++;
        }

        if(cnt > m/3) {
            cout << step << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}