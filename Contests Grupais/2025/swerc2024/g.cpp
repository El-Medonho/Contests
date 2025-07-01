#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll r; cin >> r;

    int n; cin >> n;

    vector<ll> arr(n);

    ll x = 0;

    bool ok = false;

    for(ll &i: arr){
        cin >> i;

        x += i;
        if(x < 0) x = 0;
        if(x >= r) {ok = true; x = r;}
    }

    if(ok) {cout << x << '\n'; return 0;}

    x = r;

    for(ll i : arr){
        x += i;

        if(x <= 0) {x = 0; ok = true;}
        if(x > r) x = r;
    }

    if(ok){
        cout << x << '\n';
        return 0;
    }

    cout << "uncertain\n";

    return 0;
}