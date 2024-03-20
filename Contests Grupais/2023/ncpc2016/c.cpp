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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;

    int n; cin >> n;

    vector<string> vv(0);
    vector<vector<int>> arr(4);
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vv.push_back(s);

        int ind = -1;
        if(s[1] == 's') ind = 0;
        if(s[1] == 'h') ind = 1;
        if(s[1] == 'd') ind = 2;
        if(s[1] == 'c') ind = 3;

        int val = s[0] - '1';
        if(s[0] == 'T') val = 9;
        if(s[0] == 'J') val = 10;
        if(s[0] == 'Q') val = 11;
        if(s[0] == 'K') val = 12;
        if(s[0] == 'A') val = 13;

        arr[ind].push_back(val);
    }

    vector<int> order = {0,1,2,3};
    int t = 24;

    for(int i = 0; i < 4; i++) sort(arr[i].begin(), arr[i].end());

    int ans = 52;

    while(t--){
        for(int i = 0; i < (1<<4); i++){
            for(int j = 0; j < 4; j++) {
                if( i & (1<<j) ) reverse(arr[j].begin(), arr[j].end());
            }

            vector<int> final;
            
            for(int j: order){
                for(int k: arr[j]) final.push_back(k + 100*j);    
            }

            vector<int> in;

            for(string s: vv){
                int ind = -1;
                if(s[1] == 's') ind = 0;
                if(s[1] == 'h') ind = 1;
                if(s[1] == 'd') ind = 2;
                if(s[1] == 'c') ind = 3;

                int val = s[0] - '1';
                if(s[0] == 'T') val = 9;
                if(s[0] == 'J') val = 10;
                if(s[0] == 'Q') val = 11;
                if(s[0] == 'K') val = 12;
                if(s[0] == 'A') val = 13;

                in.push_back(val + 100*ind);
            
            }

            vector<vector<int>> dp(n+1, vector<int>(n+1,0));

            int cc = 0;

            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dp[i][j] = (final[i-1] == in[j-1]) ? dp[i-1][j-1] + 1: max(dp[i][j-1], dp[i-1][j]);
                    cc = max(cc, dp[i][j]);
                }
            }

            ans = min(ans, n-dp[n][n]);

            for(int j = 0; j < 4; j++) {
                if( i & (1<<j) ) reverse(arr[j].begin(), arr[j].end());
            }
        }

        if(! next_permutation(order.begin(), order.end())) break;
    }

    cout << ans << '\n';

    return 0;
}