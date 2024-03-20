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

const int save = 1e8;

signed solve(){

    int n; cin >> n;

    ll x,y,s; cin >> x >> y >> s;

    ll kk = x%y;

    if(x + (n-1)*(x%y) > s || (kk*n%y) != s % y){
        cout << "NO\n";
        return 0;
    }
    
    s -= kk*n;

    s/=y;

    kk = x/y;

    vector<int> ans = {};

    ll resto = x % y;

    s -= kk;
    // kk++;
    n--;

    if(s == 0){
        cout << "YES\n";
        cout << x << ' ';
        for(int i = 0; i < n; i++){
            cout << resto << ' ';
        }
        cout << endl;
        return 0;
    }

    vector<unordered_map<int,int>> momentos(s+1);
    vector<vector<int>> dp(s+1, vector<int>(0));
    vector<int> sums(n+2, 0);

    dp[0].push_back(0);

    ll sum = 0;
    sum = kk+1;

    for(int i = kk+1; sum <= s; i++){
        int j = 0;

        int nxt = j+sum;
        for(int k: dp[j]){
            int h = k+i-kk;
            if(h > n || momentos[nxt].find(h) != momentos[nxt].end()) continue;
            momentos[nxt][h] = save+i;
            dp[nxt].push_back(h);
        }
        

        sum += i+1;
    }

    sum = 1;

    for(int i = 1; sum <= s && i < n; i++){
        sums[i] = sum;
        for(int j = 0; j + sum <= s; j++){
            int nxt = j+sum;
            for(int k: dp[j]){
                int h = k+i+1;
                if(h > n || momentos[nxt].find(h) != momentos[nxt].end()) continue;     //sera q h ta passando de n?
                momentos[nxt][h] = i;
                dp[nxt].push_back(h);
            }
        }

        sum += i+1;
    }

    int qual = 0;
    bool ok = false;

    for(int i = 0; i <= n; i++){
        if(momentos[s][i]){
            ok = true;
            qual = i;
            break;
        }
    }

    if(!ok){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for(int i = qual; i < n; i++) ans.push_back(resto);

    int cnt = qual, cc = s;
    while(cnt){
        int h = momentos[cc][cnt];
        int cap = 0;
        if(h > save){
            cap = kk+1;
            cnt = 0;
            h-=save;
        }
        else{
            cnt -= h+1;
            cc -= sums[h];
        }

        for(int i = h; i >= cap; i--){
            ans.push_back(i*y+resto);
        }

        
    }
    ans.push_back(kk*y+resto);

    reverse(ans.begin(), ans.end());

    for(int i: ans) cout << i << ' ';
    cout << endl;

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