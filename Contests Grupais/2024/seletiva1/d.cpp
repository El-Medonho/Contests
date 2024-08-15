#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n; cin >> n;

    vector<int> arr(n);

    ll sum = 0;

    for(int &i: arr){
        cin >> i;
        sum += i;
    }

    sum /= n;

    ll ans = 0;

    for(int i: arr){
        ans += abs(i-sum);
    }

    cout << ans/2 << endl;

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