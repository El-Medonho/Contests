#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;
typedef long double ld;

vector<ld> expo(2e5+5, 1);

signed solve(){

    int n; cin >> n;

    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    vector<ll> ans(n, -1);

    ll ans2 = 0;

    for(int m = 1; m <= 3; m++){
        ans = vector<ll>(n, -1);
        vector<ll> k(n); bool ok = true;
        for(int i = 0; i < n; i++){
            k[i] = arr[i] - m;
            if(k[i] < 0) ok = false;
        }
        if(!ok) continue;

        ld sum = 0;

        for(int i = 0; i < n; i++){
            if(i%2 == 0) sum += k[i]*expo[i];
            else sum -= k[i]*expo[i];
        }
        
        
        ld a0 = 2;
        if(n%2) a0 += expo[n-1];
        else a0 -= expo[n-1];
        
        a0 = sum/a0;
        
        // if(m == 2){
        //     cout << "sum: " << sum << endl;
        // }
        // if(m == 2){
        //     cout << "a0: " << a0 << endl;
        // }

        for(ll bar = max(ll(a0)-3, 0LL); bar < a0+4; bar++){
            vector<ll> sarr = arr;
            vector<ll> cans(n, -1);

            sarr[0] -= 2*bar;
            if(sarr[0] < m) continue;
            sarr[n-1] -= bar;
            cans[0] = bar;

            bool ok = true;

            for(int i = 1; i < n; i++){
                ll falta = sarr[i-1] - m;
                cans[i] = falta;
                sarr[i-1] -= falta;
                sarr[i] -= 2*falta;
                if(sarr[i] < m){
                    ok = false;
                    break;
                }
            }

            if(sarr[n-1] != m) ok = false;

            if(ok){
                ans = cans;
                break;
            }
        }

        if(ans[0] != -1){
            ll mn = *min_element(ans.begin(), ans.end());
        
            ans2 = max(ans2, arr[0] - 2*ans[0] - ans[1] + 3*mn);
        }
    }


    cout << ans2 << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for(int i = 1; i < 2e5+4; i++) expo[i] = expo[i-1]/2;

    while(t--){
        solve();
    }


    return 0;
}