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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;

signed solve(){
    
    string s; cin >> s;
    int n = s.size();

    int a,b,t0,t1;

    cin >> a >> b >> t0 >> t1;

    char cr = s[0]; int qt = 1;

    vector<vector<int>> dp(n + 5, vector<int>(3, 0));
    vector<int> base(2, 0);

    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            if(qt%2 == 1) {
                base[cr-'A']++; qt--;

                if(qt/2){
                    dp[qt/2][2]++;
                }
            }

            else dp[qt/2][cr-'A']++;

            qt = 0; cr = s[i];
        }

        qt++;
    }

    if(qt%2 == 1) {
        base[cr-'A']++; qt--;

        if(qt/2){
            dp[qt/2][2]++;
        }
    }

    else dp[qt/2][cr-'A']++;

    int res = min(a-base[0], b-base[1]);

    if(res < 0){
        cout << "NO\n";
        return 0;
    }

    vector<int> base2(2, 0);
    vector<vector<int>> qtt(2);

    for(int i = 0; i <= n; i++){
        base2[0] += i * dp[i][0];
        for(int j = 0 ; j < dp[i][0]; j++) qtt[0].push_back(i);
        base2[1] += i * dp[i][1];
        for(int j = 0 ; j < dp[i][1]; j++) qtt[1].push_back(i);
    }

    vector<int> base3 = base2;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < dp[i][2]; j++){
            if(base3[0]+i <= t0) base3[0] += i;
            else base3[1] += i;
        }
    }

    int h = base3[1]-t1;
    
    for(int i = 0; i < res; i++){
        h--;
        if(i >= qtt[1].size()) continue;
        int d = min(t0-base3[0], qtt[1][qtt[1].size()-1-i]-1);
        d = max(0, d);
        h -= d;
        base3[0] += d;
    }
    
    if(h <= 0 && base3[0] <= t0){
        cout << "YES\n";
        return 0;
    }



    base3 = base2;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < dp[i][2]; j++){
            if(base3[1]+i <= t1) base3[1] += i;
            else base3[0] += i;
        }
    }


    h = base3[0]-t0;

    
    for(int i = 0; i < res; i++){
        h--;
        if(i >= qtt[0].size()) continue;
        int d = min(t1-base3[1], qtt[0][qtt[0].size()-1-i]-1);
        d = max(0, d);
        h -= d;
        base3[1] += d;
    }
    
    if(h <= 0 && base3[1] <= t1){
        cout << "YES\n";
        return 0;
    }

        cout << "NO\n";


    return 0;
}

signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}