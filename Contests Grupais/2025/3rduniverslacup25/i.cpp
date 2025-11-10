#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const ll lim = 1e12;

const ll mod = 998244353;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed solve(){
    int n;
    cin >> n;

    vector<ll> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<ll> single(200, 0), squared(200, 0);

    int mx = min(500, n);

    ll base = 0;

    ll ans = 0;

    for(int i = 0; i < mx; i++){
        for(int j = 0; j < n; j++){
            ans += (arr[j] % arr[i] % mod) * (arr[j] % arr[i] % mod) % mod;
        }
    }

    if(mx == n){
        cout << ans % mod << endl;
        return 0;
    }

    for(int i = 0; i < mx; i++){
        base += arr[i] * arr[i] % mod;
    }

    ll h = 0;
    map<ll, int> mapa;
    for(int i = mx; i < n; i++){
        h = max(h, arr[i]/arr[mx-1]);
        mapa[arr[i]] = i;
        single[h] += arr[i]%arr[mx-1];
        squared[h] += single[i]*arr[i]%arr[mx-1];
    }


    for(int i = mx; i < n; i++){
        vector<ll> newsingle(h+1, 0), newsquared(h+1, 0), qtt(h+1, -1);
        vector<int> done(h, 0);
        for(int j = 1; j <= h; j++){
            ll minimo = arr[i] * j;
            int ind = (*mapa.lower_bound(minimo)).second;
            int indd = ind--;
            while(arr[ind] / arr[i-1] == j){
                single[j] -= arr[ind] % arr[i-1] % mod;
                squared[j] -= (arr[ind] % arr[i-1] % mod) * (arr[ind] % arr[i-1] % mod) % mod;
                newsingle[arr[ind]/arr[i-1]] += arr[ind] % arr[i] % mod;
                newsquared[arr[ind]/arr[i-1]] += (arr[ind] % arr[i] % mod) * (arr[ind] % arr[i] % mod) % mod;
                ind--;
            }

            qtt[j-1] = ind-qtt[j-1]+1;
            done[j-1] = 1;
            qtt[j] = indd;
        }

        for(int j = 1; j <= h; j++){
            newsingle[j] %= mod; single[j] %= mod; squared[j] %= mod; newsquared[j] %= mod;
            if(!done[j] && qtt[j] != -1){
                h = j+1;
                qtt[j] = n-qtt[j];
            }
        }

        for(int j = 1; j <= h; j++){
            ll diff = (arr[i] - arr[i-1]) * j; diff %= mod;
            ll newnew = single[j] - qtt[j]*diff % mod;
            newnew %= mod;
            newsingle[j] += single[j] - qtt[j]*diff % mod;
            newsquared[j] += qtt[j]*diff % mod *diff % mod - squared[j] + 2 * newnew * single[j] % mod;
            
            newsingle[j] %= mod;
            newsquared[j] %= mod;
            ans += newsquared[j];
        }

        ans += base;
        ans %= mod;
        base += arr[i] * arr[i] % mod;
        base %= mod;
        newsingle = single;
        newsquared = squared;
    }    

    ans %= mod; 
    if(ans < 0) ans += mod;

    cout << ans << endl;

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