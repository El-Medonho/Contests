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

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<vector<vector<ll>>> dp(11, vector<vector<ll>>(70, vector<ll>(1100, 0))), sum(11, vector<vector<ll>>(70, vector<ll>(1100, 0)));

    // dp[base][digito][quais estao ativos]
    
    for(int g = 2; g <= 10; g++){
        for(int i = 0; i < g; i++){
            dp[g][0][(1<<i)] = 1;
        }
        sum[g][0] = dp[g][0];

        for(int j = 1; j < 66; j++){
            for(int i = 0; i < 1024; i++){
                dp[g][j][i] += dp[g][j-1][i];
                for(int k = 0; k < g; k++){
                    sum[g][j][i ^ (1<<k)] += sum[g][j-1][i];
                }
                for(int k = 1; k < g; k++){
                    dp[g][j][i ^ (1<<k)] += sum[g][j-1][i];
                }
            }
        }
    }
    
    int q; cin >> q;

    while(q--){

        ll b,l,r; cin >> b >> l >> r;
        swap(l, r);
        r--;

        string s = "";

        if(l == 0) s = "0";
        while(l){
            s += '0' + (l % b);
            l /= b;
        }

        // reverse(s.begin(), s.end());

        ll ans = 0, ans2 = 0;
        int cc = 0;


        for(int j = s.size()-1; j > 0; j--){
            int dig = s[j]-'0';

            if(dig != 0){
                for(int i = 1; i < dig; i++){
                    int hh = cc ^ (1<<i);
                    ans += sum[b][j-1][hh];
                }
                if(j == s.size()-1) ans += dp[b][j-1][cc];
                else ans += sum[b][j-1][cc ^ (1)];
            }

            cc ^= (1<<dig);
        }

        int ok = 0;

        for(int i = 0; i < b; i++){
            if(cc & (1<<i)){
                if(i > s[0]-'0') ok += 2;
                ok++;
            }
        }

        if(ok == 1) ans++;

        if(s.size() <= 1) ans = 0;

        cc = 0;
        s = "";

        if(r == 0) s = "0";

        while(r){
            s += '0' + (r % b);
            r /= b;
        }


        // reverse(s.begin(), s.end());

        for(int j = s.size()-1; j > 0; j--){
            int dig = s[j]-'0';


            if(dig != 0){
                for(int i = 1; i < dig; i++){
                    int hh = cc ^ (1<<i);
                    ans2 += sum[b][j-1][hh];
                }
                if(j == s.size()-1) ans2 += dp[b][j-1][cc];
                else ans2 += sum[b][j-1][cc ^ (1)];
            }

            cc ^= (1<<dig);
        }

        ok = 0;

        for(int i = 0; i < b; i++){
            if(cc & (1<<i)){
                if(i > s[0]-'0') ok += 2;
                ok++;
            }
        }

        if(ok == 1) ans2++;

        if(s.size() <= 1) ans2 = 0;

        cout << ans - ans2 << endl;

    }

    return 0;
}