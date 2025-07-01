#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

const ll mod = 998244353;

signed solve(){
    int n; cin >> n;

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> d(n, 1);

    auto dfs = [&](auto&& self, int cc, int last) -> void {
        for(int j: graph[cc]){
            if(j == last) continue;
            self(self,j,cc);
            d[cc] = max(d[cc], d[j]+1);
        }
    };

    ll ans = n, d1 = 0, d0 = 0;

    dfs(dfs, 0, 0);

    auto dfs2 = [&](auto&& self, int cc, int last, int up) -> void {
        int mx = 0, mx2 = 0;
        vector<int> arr = {0};

        if(up){
            arr.push_back(up);
            mx = up;
        }

        for(int j: graph[cc]){
            if(j == last) continue;
            if(d[j] > mx){
                swap(mx, mx2);
                mx = d[j];
            }
            else if(d[j] > mx2){
                mx2 = d[j];
            }
            arr.push_back(d[j]);
        }

        d0 += mx2;

        for(int x: arr){
            d1 += min(x, mx2+1);
        }

        for(int j: graph[cc]){
            if(j == last) continue;
            if(d[j] == mx) self(self, j, cc, mx2+1);
            else self(self, j, cc, mx+1);
        }
    };

    dfs2(dfs2,0,0,0);

    ans += d0;
    ans += d1/2;

    cout << ans % mod << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}