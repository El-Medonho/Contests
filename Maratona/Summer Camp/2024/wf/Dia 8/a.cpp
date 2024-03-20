#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n,k; cin >> n >> k;

    vector<int> arr(n), pre(n, 0);

    for(int &i: arr) cin >> i;

    vector<vector<vector<pair<double,ll>>>> dp(n, vector<vector<pair<double,ll>>>(103, vector<pair<double,ll>>(103, {1e8, 0})));

    {
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            pre[i] = sum;
        }
    }



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