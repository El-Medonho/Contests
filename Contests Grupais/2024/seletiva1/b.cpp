#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;



signed solve(){

    int n; cin >> n;

    int ab; cin >> ab;

    vector<int> arr(n);

    for(int &i: arr) cin >> i;

    vector<int> qtt(n);

    for(int &i: qtt) cin >> i;

    int lim = 1602;

    vector<vector<int>> dp(41, vector<int>(lim+5, -1)); dp[0][0] = 0;

    for(int i = n-1; i > -1; i--){
        for(int j = 0; j < qtt[i]; j++){
            for(int k = 0; k <=lim; k++){
                if(dp[j][k] == -1) continue;
                if(k + arr[i] <= lim) dp[j+1][k+arr[i]] = max(dp[j+1][k+arr[i]], dp[j][k]);
                dp[j][k] += arr[i] * j;
            }
        }

        for(int j = qtt[i]; j <= 40; j++){
            for(int k = 0; k <= lim; k++){
                if(dp[j][k] != -1) dp[j][k] += arr[i]*qtt[i];
            }
        }
    }

    int ans = 0;

    for(int j = 0; j <= 40; j++){
        for(int k = 0; k <= min(ab, lim); k++) ans = max(ans, dp[j][k]);
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