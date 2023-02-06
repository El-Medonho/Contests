#include <bits/stdc++.h>

#define mxn 100005
#define mxm 100005
#define pb push_pack
#define es " "
#define endl "\n"

using ll = long long int;
using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    vector<ll> p(n+1);

    for(int i = 1; i < n+1; i++) {
        cin >> p[i];
    }

    vector<ll> dp(n+1);
    dp[1] = p[1];
    int sdp = p[1];
    for(int i = 2; i <= k; i++) {
        dp[i] = min(p[i], dp[i-1]);
        sdp += dp[i];
    }

    cout << dp[k] << '\n';
    return 0;
}