#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;

const int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int s,b; cin >> s >> b;

    vector<vector<ll>> dp(s+1, vector<ll>(b+1, 0LL)); dp[0][0] = 1;

    vector<int> vis(s+1, 0); vis[0] = 1;
    vector<vector<int>> dp_vis(s+1, vector<int>(b+1, 0));
    int mx = 0;

    for(int i = b; i > 0; i--){
        for(int j = 1; j < s; j++){
            if(!vis[j]) break;
            
            for(int k = j; k < b; k++){
                if(dp_vis[j][k] && k + i <= b){
                    dp[j+1][k+i] = dp[j+1][k+i] + dp[j][k];
                    if(dp[j+1][k+i] >= mod) dp[j+1][k+i] -= mod;
                    vis[j+1] = 1;
                    dp_vis[j+1][k+i] = 1;
                }
            }
        }

        for(int j = 1; j < s; j++){
            if(!vis[j]) break;
            
            for(int k = j; k < b; k++){
                if(dp_vis[j][k] && k + i <= b){
                    dp[j+1][k+i] = dp[j+1][k+i] + dp[j][k];
                    if(dp[j+1][k+i] >= mod) dp[j+1][k+i] -= mod;
                    vis[j+1] = 1;
                    dp_vis[j+1][k+i] = 1;
                }
            }
        }

        for(int j = 1; j <= s; j++){
            if(j * i > b) break;
            dp[j][i*j]++;
            if(dp[j][i*j] >= mod) dp[j][i*j] -= mod;
            vis[j] = 1;
            dp_vis[j][i*j] = 1;
        }
    }

    cout << dp[s][b] % mod << endl;

    return 0;
}