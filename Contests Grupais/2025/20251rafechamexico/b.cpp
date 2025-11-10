#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define f first
#define s second
typedef pair<int,int> pii;
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    ll ans = 0;
    vector<vector<ll>> arr(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            ans = max(ans, arr[i][j]);
        }
    }
    vector<pii> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}}, ini = {{0,0}, {n-1, 0}, {0,n-1},{n-1,n-1}};


    function<ll(pii,pii)> solve = 
    [&](pii cc, pii dir){
        if(cc.f + dir.f == n || cc.f + dir.f < 0 || cc.s + dir.s == n || cc.s + dir.s < 0) return 0LL;
        ll best = 0, csum = 0;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        while(true){
            vis[cc.f][cc.s] = 1;
            csum = max(csum + arr[cc.f][cc.s], 0LL);
            best = max(best, csum);
            if(cc.f + dir.f == n || cc.f + dir.f < 0 || cc.s + dir.s == n || cc.s + dir.s < 0 || vis[cc.f + dir.f][cc.s + dir.s]){
                bool nxt = 0;
                for(auto d: directions){
                    if(cc.f + d.f == n || cc.f + d.f < 0 || cc.s + d.s == n || cc.s + d.s < 0 || vis[cc.f + d.f][cc.s + d.s]) continue;
                    nxt = true;
                    cc.f += d.f; cc.s += d.s;
                    dir = d;
                    break;
                }
                if(!nxt) break;
                continue;
            }

            cc.f += dir.f; cc.s += dir.s;
        }

        return best;
    };

    for(auto dir: directions){
        for(auto cini: ini){
            ans = max(ans, solve(cini, dir));
        }
    }

    cout << ans << endl;
    


    return 0;
}