#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const ll md = 998244353;

    ll ans = 1;

    for(int i = n*m-1; i >= 0; i--) {
        ans = ans * (i+1 - (i%m+1)) % md;
        cout << ans << '\n';
    }

    cout << ans << '\n';

    return 0;
}