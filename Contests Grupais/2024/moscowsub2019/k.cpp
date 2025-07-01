#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<ll> arr(n);

    ll ans = 0;

    for(ll &i: arr){
        cin >> i;
    }

    for(int i = 0; i < n-1; i++){
        if(max(arr[i], arr[i+1]) >= 0) ans += max(arr[i], arr[i+1]);
    }

    cout << ans << endl;

    return 0;
}