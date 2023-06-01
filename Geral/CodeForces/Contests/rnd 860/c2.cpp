#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int solve(){

    int n; cin >> n;

    vector<ll> a(n),b(n);
    for(int i = 0; i < n; i++){
        ll g,j; cin >> g >> j;
        a[i] = g; b[i] = j; 
    }

    ll mmc = b[0], ans = 1, pnt = 0;

    for(int i = 1; i < n; i++){
        ll nmmc = (mmc*b[i])/__gcd(mmc,b[i]);

        if(nmmc == mmc && a[i] % (nmmc/b[i]) == 0){
            mmc = nmmc;
            continue;
        }
        bool pass = true;
        if(nmmc != mmc && a[i] % (nmmc/b[i]) == 0){
            for(int j = pnt; j < i; j++){
                if(a[j] % (nmmc/b[j]) != 0){
                    pass = false;
                    break;
                }
            }
        }
        mmc = nmmc;
        if(!pass || a[i] % (mmc/b[i]) != 0){
            mmc = b[i];
            ans++;
            pnt = i;
        }
    }

    cout << ans << endl;

    return 0;
}

int main(){
    fastio;

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;
}