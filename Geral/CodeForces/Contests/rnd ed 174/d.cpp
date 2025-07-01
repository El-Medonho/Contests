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

    int l = -1, r = n/2;
    vector<int> cnt1(26, 0), cnt2(26, 0);

    for(int i = 0; i < n/2; i++) cnt1[s[i]-'a']++;

    for(int i = (n+1)/2; i < n; i++) cnt2[s[i]-'a']++;

    int ans = n;

    if(cnt1 == cnt2){
        for(int i = 0; i < n/2; i++){
            if(s[i] == s[n-1-i]) l = i;
            else break;
        }

        for(int i = n/2-1; i > -1; i--){
            if(s[i] == s[n-1-i]) r = i;
            else break;
        }

        if(r == 0) ans = 0;
        else ans = r-l-1;
    }

    for(int i = 0; i < n/2; i++){
        if(s[i] == s[n-1-i]) l = i;
        else break;
    }

    if(n%2 == 1){
        cnt1[s[n/2]-'a']++;
        bool ok = true;
        for(int i = 0; i < 26; i++){
            if(cnt1[i] < cnt2[i]) ok = false;
        }
        if(ok){
            ans = min(ans, n/2-l);
        }

        cnt1[s[n/2]-'a']--;
        cnt2[s[n/2]-'a']++;

        ok = true;
        for(int i = 0; i < 26; i++){
            if(cnt2[i] < cnt1[i]) ok = false;
        }
        if(ok){
            ans = min(ans, n/2-l);
        }
    }


    r = n-1-l;

    vector<int> cnt(26, 0);

    for(int i = l+1; i < r; i++){
        cnt[s[i]-'a']++;
    }

    cnt1 = vector<int>(26, 0);

    for(int i = l+1; i < r; i++){
        cnt1[s[i]-'a']++;

        bool ok = true;

        for(int j = 0; j < 26; j++){
            if(cnt1[j] < cnt[j]-cnt1[j]) ok = false;
        }

        if(ok){
            ans = min(i-l, ans);
        }
    }

    cnt1 = vector<int>(26, 0);

    for(int i = r-1; i > l; i--){
        cnt1[s[i]-'a']++;

        bool ok = true;

        for(int j = 0; j < 26; j++){
            if(cnt1[j] < cnt[j]-cnt1[j]) ok = false;
        }

        if(ok){
            ans = min(ans, r-i);
        }
    }

    cout << ans << '\n';

    


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