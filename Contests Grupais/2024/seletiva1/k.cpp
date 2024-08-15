#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n,k; cin >> n >> k;

    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    int x = 0;

    vector<int> vals = {0,1,2,2,2,3,3,3};

    if(n <= 7) x = vals[n];
    else x = 3 + (n-5)/2;

    vector<ll> sum(n+1, 0);

    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1];
        sum[i] += arr[i-1];
    }

    if(k >= x){
        cout << sum[n] << endl;
        return 0;
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}