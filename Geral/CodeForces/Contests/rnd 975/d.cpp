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
    
    int n,k,q; cin >> n >> k >> q;

    vector<ll> ans(n+1, 1e9); ans[n] = 0;
    vector<int> arr(n);

    for(int &i: arr) cin >> i;

    map<int,int> mp;

    multiset<int> st;

    for(int i = 0; i < k; i++){
        if(mp[i-arr[i]]) st.erase(st.find(-mp[i-arr[i]]));
        mp[i-arr[i]]++;
        st.insert(-mp[i-arr[i]]);
    }

    for(int i = 0; i + k <= n; i++){
        ans[i] = k+(*st.begin());

        int j = i+k;

        if(mp[i-arr[i]]) st.erase(st.find(-mp[i-arr[i]]));
        mp[i-arr[i]]--;
        if(mp[i-arr[i]]) st.insert(-mp[i-arr[i]]);

        if(j >= n) continue;

        if(mp[j-arr[j]]) st.erase(st.find(-mp[j-arr[j]]));
        mp[j-arr[j]]++;
        st.insert(-mp[j-arr[j]]);
    }

    stack<int> stk; stk.push(n);

    vector<vector<pair<ll,ll>>> bl(22, vector<pair<ll,ll>>(n, {n, 0}));

    for(int i = n-1; i > -1; i--){
        while(ans[stk.top()] >= ans[i] && stk.top() != n) stk.pop();

        bl[0][i] = {stk.top(), (stk.top()-i) * ans[i]};
        stk.push(i);
    }

    for(int j = 1; j < 22; j++){
        for(int i = 0; i < n; i++){
            auto cc = bl[j-1][i];
            
            if(cc.first == n) {
                bl[j][i] = bl[j-1][i];
                continue;
            }
            
            auto cn = bl[j-1][bl[j-1][i].first];
            bl[j][i] = {cn.first, cc.second + cn.second};
        }
    }

    while(q--){
        int l,r; cin >> l >> r; l--; r-=k;

        ll resp = 0;

        while(l <= r){
            // if(l == r) {
            //     resp += ans[l];
            //     l++; continue;
            // }

            int j = 21;

            for(j = 21; j > -1; j--){
                int h = bl[j][l].first;
                if(h <= r) break;
            }

            if(j == -1){
                resp += ans[l] * (r-l+1);
                l = r+1;
            }

            else{
                resp += bl[j][l].second;
                l = bl[j][l].first;
            }
        }

        cout << resp << endl;
    }

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