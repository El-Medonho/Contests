// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define MOD 998244353
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

ll expo(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans*b)%MOD;
        b = (b*b)%MOD;
        e>>=1;
    }
    return ans;
}

signed main(){
    fastio;

    ll n, a, b, p, q;  cin >> n >> a >> b >> p >> q;

    vector<vector<ll>> dp1(n+1, vector<ll> (n+1, 0)), dp2 = dp1; dp1[0][0] = 1; dp2[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 1; k <= p; k++){
                int h = j+k;
                if(j + k > n-a) h = n-a; 
                dp1[i+1][h] += dp1[i][j];
                dp1[i+1][h] %= MOD;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 1; k <= q; k++){
                int h = j+k;
                if(j + k > n-b) h = n-b; 
                dp2[i+1][h] += dp2[i][j];
                dp2[i+1][h] %= MOD;
            }
        }
    }

    // a = n-a; b = n-b;

    ll ans2 = 0;
    ll tot = 1, tot2 = 1;

    for(int i = 1; i <= n-a; i++){

        ll ans = 1;

        ll aux = 0;
        for(int j = 0; j < n-a; j++){
            aux += dp1[i][j];
            aux %= MOD;
        }

        ans *= tot;
        ans %= MOD;

        ans *= expo((aux+dp1[i][n-a])%MOD, MOD-2);
        ans %= MOD;

        ans *= dp1[i][n-a];
        ans %= MOD;

        ll gg = (aux * expo( (aux+dp1[i][n-a]) % MOD, MOD-2))%MOD;

        tot = (tot*gg)%MOD;

        aux = 0;
        for(int j = 0; j < n-b; j++){
            aux += dp2[i-1][j];
            aux %= MOD;
        }

        gg = (aux * expo((aux+dp2[i-1][n-b]) % MOD, MOD-2))%MOD;

        tot2 = (tot2*gg)%MOD;

        ans *= tot2;
        ans %= MOD;      

        ans2 += ans;  
        ans2 %= MOD;
    }

    cout << ans2 << '\n';
    cout << 5LL*expo(6LL, MOD-2)%MOD << '\n';

    return 0;
}