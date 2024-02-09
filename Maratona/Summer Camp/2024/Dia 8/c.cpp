#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n,a,b; cin >> n >> a >> b;

    for(ll k = 1; k <= 2*n+5; k++){
        for(ll j = 0; j <= k; j++){
            ll i = k-j;

            if( (i*a + j*b) % n == 0 ){
                cout << k << endl;
                return 0;
            }
        }
    }


    return 0;
}