#include "bits/stdc++.h"

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s; cin >> s;

    vector<int> dp(27, 0);

    for(int i = 1; i < 27; i++) dp[i] = i;

    for(char c: s){
        int x = c-'a'; x++;

        dp[x] = min(dp[x], dp[x-1]);

        for(int i = x+1; i < 27; i++) dp[i] = min(dp[i], dp[i-1]+1);
    }

    cout << dp[26] << '\n';


    return 0;
}