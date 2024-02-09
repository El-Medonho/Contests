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

signed solve(){

    set<pair<int,int>> st[3];

    map<int,int> qtt[3];

    int n; cin >> n;

    map<int, int> mp, rev;
    vector<vector<int>> arr(n, vector<int>(3));

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        int x; cin >> x;
        mp[x] = i; rev[i] = x;

        st[0].insert({arr[i][0], x}); qtt[0][arr[i][0]]++;
        st[1].insert({arr[i][1], x}); qtt[1][arr[i][1]]++;
        st[2].insert({arr[i][2], x}); qtt[2][arr[i][2]]++;
    }

    set<pair<int,int>> uni;
    vector<int> vals(n, 0);

    for(int g = 0; g < 3; g++){
        for(auto [x, ind]: st[g]){
            if(qtt[g][x] > 1) continue;
            auto hh = st[g].lower_bound({x,ind});
            if(hh == st[g].begin()) hh = st[g].end();
            --hh;
            int h = (*hh).first;
            vals[mp[ind]] += (h < x) ? x + 360-h : x-h;

            hh = st[g].upper_bound({x,ind});
            if(hh == st[g].end()) hh = st[g].begin();
            h = (*hh).first;

            vals[mp[ind]] += (x > h) ? h + 360-x : h-x;
        }
    }

    for(int i = 0; i < n; i++) uni.insert({vals[i], -rev[i]});

    while(!uni.empty()){
        int ch = -(*uni.begin()).second;

        // if(uni.size() == 2) {
        //     ch = max( -(*uni.begin()).second, -(*uni.rbegin()).second );
        //     if(ch == -(*uni.begin()).second) uni.erase(*uni.begin());
        //     else uni.erase(*uni.rbegin());
        // }
        // else uni.erase(*uni.begin());

        uni.erase(*uni.begin());

        cout << ch << endl;


        if(uni.size() <= 1) continue;

        for(int g = 0; g < 3; g++){
            int ind = ch;
            int x = arr[mp[ind]][g];
            qtt[g][x]--;
            
            auto hr = st[g].upper_bound({x, ind}), hl = st[g].lower_bound({x, ind});

            if(hr == st[g].end()) hr = st[g].begin();

            if(hl == st[g].begin()) hl = st[g].end();
            hl--;

            auto[hhr, xr] = (*hr);
            auto[hhl, xl] = (*hl);

            int dr = (x > hhr) ? hhr + 360-x : hhr-x;
            int dl = (hhl < x) ? x + 360-hhl : x-hhl;

            uni.erase({vals[mp[xl]], -xl});
            uni.erase({vals[mp[xr]], -xr});
            
            if(qtt[g][hhl] == 1) 
                vals[mp[xl]] -= dr;
                vals[mp[xl]] += (hhl < hhr) ? hhr + 360-hhl : hhr-hhl;
            if(qtt[g][hhr] == 1) 
                vals[mp[xr]] -= dl;
                vals[mp[xr]] += (hhr > hhl) ? hhr + 360-hhl : hhr-hhl;

            uni.insert({vals[mp[xl]], -xl});
            uni.insert({vals[mp[xr]], -xr});

            st[g].erase({x, ind});
        }
    }
    
    // cout << "abza\n";

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