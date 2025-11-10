#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;



signed solve(){

    ll x; cin >> x;

    ll qtt; cin >> qtt;

    if(qtt == 1){
        int a; cin >> a;

        cout << (x%a == 0) ? 1: 0 << endl;
        return 0;
    }

    if(qtt == 2){
        int a,b; cin >> a >> b;

        int ans = 0;
        // ans += (x%a == 0) ? 1: 0;
        // ans += (x%b == 0) ? 1: 0;

        int lcm = a*b/__gcd(a,b);

        vector<ll> dp(lcm+1, 0); dp[0] = 1;
        for(int i = 0; i + a <= lcm; i++) dp[i+a] += dp[i];
        for(int i = 0; i + b <= lcm; i++) dp[i+b] += dp[i];

        if(dp[x%lcm]) ans += (x/lcm)+1;
    }


    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);


    int t; cin >> t;
    while(t--) solve();
    


    return 0;
}