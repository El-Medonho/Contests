#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

void chmin(ll& a, ll b) {
    a = min(a, b);
}
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n; cin >> n;
    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    int k = (n+1)/2 + 2;

    vector<vector<ll>> dp(k+1, vector<ll>(3, 1e16));
    vector<vector<ll>> nxt;
    dp[0][2] = 0;

    for(int i = 0; i < n; i++){
        nxt = vector<vector<ll>>(k+1, vector<ll>(3, 1e16));
        for(int j = 0; j < k; j++) 
            for(int a = 0; a < 3; a++) 
                nxt[j][min(a+1, 2)] = min(dp[j][a], nxt[j][min(a+1, 2)]);

        ll h = 0;
        if(i > 0) h += max(0LL, arr[i-1] - arr[i] + 1);
        if(i < n-1) h += max(0LL, arr[i+1] - arr[i] + 1); 

        for(int j = 0; j < k; j++){
            chmin(nxt[j+1][0], dp[j][2] + h);
        }

        if(i >= 2){
            h = 0;
            if(i < n-1) h += max(0LL, arr[i+1] - arr[i] + 1); 
            if(i > 1) h += max(0LL, min(arr[i-1], arr[i-2]-1) - arr[i] + 1);

            for(int j = 0; j < k; j++){
                // if(dp[j][1] == 1e18) continue;
                chmin(nxt[j+1][0], dp[j][1] + h);
            }
        }


        dp = nxt;
    }

    for(int j = 1; j <= (n+1)/2; j++){
        cout << *min_element(nxt[j].begin(), nxt[j].end()) << ' ';
    }
    cout << endl;

    return 0;
}