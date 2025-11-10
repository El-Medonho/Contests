#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll d; cin >> d;
    ll ini = d;

    vector<pair<int,int>> dp(2005, make_pair(-1,-1)); dp[0] = {0,0};

    int count = 1e4;

    while(count--){
        int sum = 0;
        ll temp = d;
        while(temp){
            sum += temp%10;
            temp/=10;
        }
        if(sum > 2002) break;
        for(int i = 2002; i > -1; i--){
            if(i-sum < 0) break;
            if(dp[i-sum].first != -1 && dp[i].first == -1) dp[i] = {d, i-sum};
        }
        d += ini;
    }
    assert(dp[ini].first != -1 || dp[ini*2].first != -1);

    if(dp[ini].first == -1) ini *= 2;

    string ans = "";
    while(ini){
        auto [num, l] = dp[ini];
        while(num){
            ans += '0'+num%10;
            num /=10;
        }
        ini = l;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}