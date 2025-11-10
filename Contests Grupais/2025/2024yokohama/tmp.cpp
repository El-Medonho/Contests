#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const ll mx = 2e18;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll a,b; cin >> a >> b;

    ll ans = mx, cans = 0;

    bool ok = true;

    int resp = 0;

    for(int i = 62; i > -1; i--){
        if((b&(1LL<<i)) && !(a&(1LL<<i))){
            resp++;
            break;
        }

        if(a&(1LL<<i)) {
            cans += (1LL<<i);
        }
    }

    // int ii;
    // for(ii = 0; ii < resp-1; ii++){
    //     cans += (1LL<<ii);
    // }
    // cout << cans << endl;
    if(cans >= a){
        cout << cans << endl;
        return 0;
    }

    int ii = 0;

    while(ii < 64 && resp > 0){
        cans += (1LL<<ii);
        if(cans >= a) break;
        cans -= (1LL<<ii);
        ii++;
    }

    

    cout << cans << endl;

    return 0;
}