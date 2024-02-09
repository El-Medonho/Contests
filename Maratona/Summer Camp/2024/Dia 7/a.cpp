#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,k; cin >> n >> k;

    ll ans = 0;
    ll sum = 0;

    ll tot = 1;

    vector<ll> fact(1e6+5,1);

    for(int i = 1; i < (int)1e6+3; i++){
        fact[i] = fact[i-1] * i % mod;
    }

    if(k == 0){
        cout << fact[n] << endl;

        return 0;
    }
    // cout << fact[4] << '\n';

    vector<int> arr(k);
    for(int &i: arr) cin >> i;

    tot = fact[n];

    for(int i = 0; i < k; i++){
        ll sum2 = 0;
        sum += arr[i];
        for(int j = 0; j <= i; j++){
            int op = ((i-j)%2 != 0) ? -1 : 1;
            sum2 += arr[j];

            ll h = fact[sum2] * fact[sum-sum2] % mod;
            h = h * fact[n-sum] % mod;
            cout << op*h << ' ';

            ans = ((ans + op * h) % mod + mod) % mod;
        }
        // ans = (ans + fact[sum]*fact[n-sum] % mod) % mod;

        cout << endl;
        cout << ans << '\n';
    }

    ans = ((tot-ans) % mod + mod) % mod ;

    cout << ans << '\n';

    return 0;
}