#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;

int n, m;
vector<string> grid;
vector<vector<int>> dp;

bool check(int dim) {
    bool ok = false;
    for(int j = 0; j < m; j++) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i][j] >= dim) count++;
            else count = 0;
            ok = ok || (count >= dim);
        }
    }

    return ok;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    grid.resize(n);

    for(int i = 0; i < n; i++) cin >> grid[i];

    dp.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++) dp[i][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(grid[i][j] == grid[i][j-1]) dp[i][j] = dp[i][j-1] + 1;
            else dp[i][j] = 1;
        }
    }

    int l = 1, r = min(n,m), ans = 1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(check(mid)) {
            ans = mid;
            l = mid+1;
        }else {
            r = mid-1;
        }
    }

    cout << ans*ans << '\n';

    return 0;
}