#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;


mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int cnt = 3;

int solve(){

    vector<int> mod(cnt);

    uniform_int_distribution<ll> uid(1e3, 1e9+500);

    for(int g = 0; g < cnt; g++) mod[g] = (uid(rng));

    int n; cin >> n;
    int k; cin >> k;

    ll ans = 0;

    vector<int> arr(0);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x >= k) continue;
        arr.push_back(x);
    }

    n = arr.size();

    vector<vector<int>> dp(cnt, vector<int>(2*k+50, 0));
    for(int g = 0; g < cnt; g++) dp[g][0] = 1;

    for(int i: arr){
        for(int g = 0; g < cnt; g++){
            for(int j = 2*k+5; j >= i; j--){
                dp[g][j] = (dp[g][j] + dp[g][j-i]) % mod[g];
            }
        }
    }

    for(int i: arr){
        vector<vector<int>> ndp = dp;
        for(int g = 0; g < cnt; g++){
            for(int j = i; j <= k+i-1; j++){
                ndp[g][j] = ((ndp[g][j] - ndp[g][j-i]) % mod[g] + mod[g]) % mod[g];
            }
        }

        bool ok = false;

        for(int g = 0; g < cnt && !ok; g++){
            for(int j = k; j <= k+i-1; j++){
                if(ndp[g][j-i] != 0) {
                    ok = true;
                    break;
                }
            }
        }

        if(!ok) ans++;
    }

    cout << ans << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}