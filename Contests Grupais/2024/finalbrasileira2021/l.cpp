#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

const int mod = 1e9+7;

ll expo(ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1) res = (res*b)%mod;
        b = (b*b)%mod;
        e>>=1;
    }
    return res;
}

int N = 4e6;

ll num = 0, den = 0;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<ll> fat(N+50, 1);
    for(int i = 1; i <= N+5; i++) fat[i] = fat[i-1]*i%mod;

    vector<ll> ele(N+50, 1);
    for(int i = 1; i < N+5; i++) ele[i] = ele[i-1]*2%mod;

    ll n,g,i,e; cin >> n >> g >> i >> e;

    if(g+e >= 2*n){
        cout << 2*n << endl;
        return 0;
    }

    ll s = (g>n?2*n-g:g);

    // cout << s << endl;

    for(; s > -1; s-=2){
        ll q = fat[n] * expo( fat[(g-s)/2] * fat[n - (g-s)/2] % mod, mod-2) % mod;

        ll h = n-(g-s)/2;

        q = q * (fat[h] * expo(fat[s] * fat[h-s] % mod, mod-2) % mod) % mod;

        q = q * ele[s] % mod;

        q = q * fat[g] % mod;

        // q = q * fat[e] % mod;

        // q = q * fat[2*n - g - e] % mod;

        ll f = g;

        if(e > s){
            f += e - (g+e)%2;

            h = n-(g-s)/2-s;
            ll hh = (e-s+1)/2;

            // q = q * fat[s] % mod;

            // cout << hh << endl;

            // q = q * (fat[h] * expo(fat[hh] * fat[h-hh] % mod, mod-2) % mod) % mod;
            // q = q * fat[hh] % mod;

            // if((g+e)%2) q = q * ( hh * 2 ) % mod;

            ll p = (g+e)%2;

            h -= (e-s+1)/2;
            // cout << f << ' ' << q << endl;

            if(i <= h){
                // q = q * (fat[h] * expo(fat[i] * fat[h-i] % mod, mod-2) % mod) % mod;
                // q = q * ele[i] % mod;
                // q = q * fat[i] % mod;
                f += i;
            }

            else if(i == h + p){
                // q = q * ele[h] % mod;
                // q = q * fat[h] % mod;
                f += i;
            }

            else if(i-h-p<h){
                // q = q * (fat[h] * expo(fat[i-h-p] * fat[h-(i-h-p)] % mod, mod-2) % mod) % mod;
                // q = q * ele[h] % mod;
                
                // q = q * fat[h] % mod;
                // q = q * fat[i-h-p] % mod;

                f += h-(i-h-p)+p;
            }
            else{
                // q = q * ele[h] % mod;
                // q = q * fat[h] % mod;
                // q = q * fat[h] % mod;
                f += p;
            }
        }
        else{

            // q = q * fat[e] % mod;

            f += e;

            // q = q * (fat[s] * expo(fat[e] * fat[s-e] % mod, mod-2) % mod) % mod;

            h = n-(g-s)/2-s;

            // cout << i << ' ' << h << endl;

            if(i <= h){
                // q = q * (fat[h] * expo(fat[h-i]*fat[i]%mod, mod-2) % mod) % mod;
                // q = q * ele[i] % mod;
                // q = q * fat[i] % mod;

                f += i;
            }

            else if(i <= h+(s-e)){
                // q = q * (fat[s-e] * expo(fat[i-h] * fat[s-e-(i-h)] % mod, mod-2) % mod) % mod;
                // q = q * ele[h] % mod;
                // cout << 'a' << endl;
                
                // q = q * fat[h] % mod;
                // q = q * fat[(i-h)] % mod;

                f += h;
            }

            else if(i-h-(s-e) < h){
                // q = q * (fat[h] * expo(fat[i-h-(s-e)] * fat[h - (i-h-(s-e))] % mod, mod-2) % mod) % mod;
                // q = q * ele[h - (i-h-(s-e))] % mod;
                // q = q * ele[h] % mod;

                // q = q * fat[h] % mod;
                // q = q * fat[s-e] % mod;
                // q = q * fat[h - (i-h-(s-e))] % mod;

                f += h - (i-h-(s-e));
            }
            else{
                // q = q * ele[h] % mod;

                // q = q * fat[h] % mod;

                // q = q * fat[s-e] % mod;

                // q = q * fat[h] % mod;
            }
        }

        f %= mod;

        // cout << s << ": " << q << ' ' << f << endl;

        den = (den + q) % mod;
        num = (num + q * f % mod) % mod;
    }


    ll ans = num * expo(den, mod-2) % mod;

    cout << ans << endl;

    return 0;
}