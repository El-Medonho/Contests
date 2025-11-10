#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){
    int n;
    cin >> n;
    ll a=0, b = 0;
    for(int i=0; i<n; i++){
        char x;
        cin >> x;
        if(x == '+') a++;
        else b++;
    }
    int q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        if(a == b){
            cout << "YES" << endl;
        }else{
            ll lcm = x * y / __gcd(x, y);

            ll needx = lcm / x, needy = lcm / y;

            ll varX = abs(needx - needy);

            ll varY = abs(a - b);

            if(varX!=0 && varY % varX == 0){
                ll found = varY / varX;
                if((a - needx * found >= 0 && b - needy * found >= 0) || (b - needx * found >= 0 && a - needy * found >= 0)){
                    cout << "YES" << endl;
                    continue;
                }
            }
            cout << "NO" << endl;
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