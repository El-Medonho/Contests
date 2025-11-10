#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,p,m; cin >> n >> p >> m;

    vector<vector<int>> dp(515, vector<int>(515, 0));

    int h = n-p;
    dp[h][p] = 1;

    for(int sum = 1; sum <= h; sum++){
        for(int i = h; i >= sum; i--){
            for(int x = 0; x < 512; x++){
                if(dp[i][x] == 0) continue; 
                dp[i-sum][x^sum]+=dp[i][x];
                if(dp[i-sum][x^sum] >= m) dp[i-sum][x^sum] -= m;
            }
        }
    }

    cout << dp[0][0] << endl;


    return 0;
}