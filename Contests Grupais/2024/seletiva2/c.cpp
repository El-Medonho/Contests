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

#define endl '\n'

typedef long long ll;

const int mod = 1e9+7;

signed solve(){

    int n; cin >> n;

    vector<ll> pot(1e5+5, 1), pot2( 1e5+5, 1);

    for(int i = 1; i < 1e5; i++) pot[i] = pot[i-1] * 10 % mod;

    for(int i = 1; i < 1e5; i++) pot2[i] = pot2[i-1] * 2 % mod;

    vector<ll> fat(1e5+5, 1);

    for(int i = 1; i < 1e5; i++) fat[i] = fat[i-1] * i % mod;

    vector<vector<ll>> escolhe(105, vector<ll>(105, 0));

    escolhe[0][0] = 1;

    for(int i = 1; i < 102; i++){
        escolhe[i][0] = 1;
        for(int j = 1; j <= i; j++) escolhe[i][j] = (escolhe[i-1][j-1] + escolhe[i-1][j]) % mod;
    }

    vector<int> arr(n);

    vector<int> freq(11, 0);

    for(int &i: arr){
        string x; cin >> x;
        i = stoi(x);
        freq[x.size()]++;
    }

    vector<ll> pans(11, 0);

    int lim = 1e3+5;

    for(int i = 1; i < 11; i++){
        if(freq[i] == 0) continue;
        freq[i]--;

        vector<vector<ll>> dp(n+1, vector<ll>(1e3+200, 0));

        dp[0][0] = 1;

        for(int a = 1; a < 11; a++){
            for(int b = 0; b < freq[a]; b++){
                for(int j = n-1; j > -1; j--){
                    for(int k = lim; k > -1; k--){
                        dp[j+1][k+a] = (dp[j+1][k+a] + dp[j][k]) % mod;
                    }
                }
            }
        }

        ll bb = 0;

        for(int a = 0; a < n; a++){
            for(int b = 0; b < lim; b++){

                if(!dp[a][b]) continue;

                ll h = dp[a][b] * pot[b] % mod;

                h = h * fat[a] % mod;
                
                int tot = n-a-1;

                ll hh = 0;

                for(int c = tot; c > -1; c--){
                    hh = (hh + escolhe[tot][c] * fat[c] % mod) % mod;
                }

                h = h * hh % mod;

                bb = (bb + h) % mod;
            }
        }

        pans[i] = bb;


        freq[i]++;
    }

    ll ans = 0;

    for(ll i: arr){
        string s = to_string(i);

        ans = (ans + pans[s.size()] * i % mod) % mod;
    }

    cout << ans << endl;

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