#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'
using pll = pair<ll,ll>;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<ll>> a(n, vector<ll>(n)), sol(4, vector<ll>(4, 1e15));
        for(auto& line : a) {
            for(ll& val : line) {
                cin >> val;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i <= n/2 && j <= n/2) sol[0][0] = min(sol[0][0], a[i][j]);
                if(i <= n/2 && j >= n/2) sol[1][1] = min(sol[1][1], a[i][j]);
                if(i >= n/2 && j <= n/2) sol[2][2] = min(sol[2][2], a[i][j]);
                if(i >= n/2 && j >= n/2) sol[3][3] = min(sol[3][3], a[i][j]);
            }
        }

        for(int j = 0; j < n; j++) {
            if(j <= n/2) sol[0][2] = min(sol[0][2], a[n/2][j]);
            if(j >= n/2) sol[1][3] = min(sol[1][3], a[n/2][j]);
        }

        for(int i = 0; i < n; i++) {
            if(i <= n/2) sol[0][1] = min(sol[0][1], a[i][n/2]);
            if(i >= n/2) sol[2][3] = min(sol[2][3], a[i][n/2]);
        }

        ll ans = min({
            sol[0][1]+sol[2][3],
            sol[0][2]+sol[1][3],
            sol[0][0]+sol[2][2]+sol[1][3],
            sol[0][2]+sol[1][1]+sol[3][3],
            a[n/2][n/2],
            sol[0][0]+sol[1][1]+sol[2][2]+sol[3][3],
            sol[0][1]+sol[2][2]+sol[3][3],
            sol[0][0]+sol[1][1]+sol[2][3]
        });

        cout << ans << '\n';
    }

    return 0;
}