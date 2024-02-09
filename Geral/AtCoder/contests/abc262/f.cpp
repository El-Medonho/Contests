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

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
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

signed solve(){
    
    int n,k; cin >> n >> k;

    vector<int> arr(n), s(0), s2(0);

    for(int &i: arr) {cin >> i; i--;}

    vector<int> mp(n, -1);
    for(int i = 0; i < n; i++) mp[arr[i]] = i;

    if(k == 0){
        for(int i: arr) cout << i+1 << ' ';
        cout << endl;
        return 0;
    }


    int ch = -1;
    for(int i = 0; i < n; i++){
        if(n - mp[i] > k && mp[i] > k) continue;
        ch = i;
        break;
    }

    int kk = k;

    // string s = "", s2 = "";

    int l = ch;
    bool p = 1;
    if(n - mp[ch] <= k){
        k -= n - mp[ch];
        s.push_back(l);
        for(int i = ch + 1; i < n; i++){
            if(mp[i] > mp[l] && k && p){
                // k--;
                l = i;
                s.push_back(l);
            }
            else if(mp[i] < mp[ch]){
                if(p && k >= mp[i]){
                    k -= mp[i];
                    l = i;
                    p = 0;
                    s.push_back(l);
                }
                else if(!p && k >= mp[i] - mp[l] - 1 && mp[i] > mp[l] && mp[i] - mp[l] - 1 > 0){
                    k -= mp[i] - mp[l] - 1;
                    l = i;
                    p = 0;
                    s.push_back(l);
                }
            }
        }
        if(p) {
            for(int i = mp[l]+1; i < n; i++) s.push_back(arr[i]);
            vector<int> mark(0);
            for(int i = 0; i < mp[ch]; i++) {
                while(mark.size() && arr[i] < mark.back() && k) {mark.pop_back(); k--;}
                mark.push_back(arr[i]); 
            }
            for(int i: mark) s.push_back(i);
            while(k) {s.pop_back(); k--;}
        }
        else{
            vector<int> mark(0);
            for(int i = mp[l]+1; i < mp[ch]; i++) {
                while(mark.size() && arr[i] < mark.back() && k) {mark.pop_back(); k--;}
                mark.push_back(arr[i]); 
            }
            for(int i: mark) s.push_back(i);
            while(k) {s.pop_back(); k--;}
        }
    }

    


    k = kk;
    l = ch;

    if(mp[ch] <= k){
        k -= mp[ch];
        // int l = ch;
        s2.push_back(l);
        // for(int i = ch+1; i < n; i++){
        //     int h = mp[i] - mp[l] - 1;
        //     if(mp[i] > mp[l] && mp[i] - mp[l] - 1 <= k && h){
        //         k -= mp[i] - mp[l] - 1;
        //         l = i;
        //         s2.push_back(l);
        //     }
        // }
        vector<int> mark(0);
        for(int i = mp[l]+1; i < n; i++) {
            while(mark.size() && arr[i] < mark.back() && k) {mark.pop_back(); k--;}
            mark.push_back(arr[i]); 
        }
        for(int i: mark) s2.push_back(i);
        while(k) {s2.pop_back(); k--;}
    }


    bool ok = false;
    for(int i = 0; i < max(s.size(), s2.size()); i++){
        if(s2.size() == 0) break;
        if(s.size() == 0) {ok = true; break;}
        if(s2.size() == 0 || i >= s.size() || s[i] < s2[i]) break;
        if(s.size() == 0 || i >= s2.size() || s[i] > s2[i]){
            ok = true;
            break;
        }
    }

    if(ok) swap(s, s2);
    

    for(int i: s) cout << i+1 << ' ';
    cout << endl;

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}
