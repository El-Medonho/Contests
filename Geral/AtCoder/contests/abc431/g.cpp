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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;
const ll inf = 1e18+5;

void upd(int x, int val, vector<ll> &bit) {
    for(; x < bit.size(); x+=x&-x) bit[x] += val;
}

ll sum(int x, vector<ll> &bit) {
    ll ans = 0;
    for(; x; x-=x&-x) ans += bit[x];
    return ans;
}

signed solve(){
    
    ll n,q; cin >> n >> q;

    vector<int> arr(n);
    for(int &i: arr) {cin >> i;}

    vector<int> sarr = arr;
    sort(sarr.begin(), sarr.end());
    
    vector<ll> same(n+1, 0), s(n+1, 0);
    vector<int> ind(n+1, -1);
    vector<pair<int,int>> ans(q);

    for(int i = 0; i < n; i++){
        same[sarr[i]]++; upd(sarr[i], 1, s);
        ind[arr[i]] = i;
    }

    ll l = 1, r = n*(n-1)/2;
    ll mid = 0;

    vector<pair<ll,int>> qw(q);

    for(int i = 0; i < q; i++){
        ll x; cin >> x;
        qw[i] = {x, i};
    }
    int a = 0, b = q-1;

    sort(qw.begin(), qw.end());
    pair<int,int> set_ind = {-1, -1};

    for(int i = 0; i < n; i++) {
        ll cc = arr[i];

        if(same[cc] > 1) set_ind.first = i;

        mid += same[cc]-1;
        ll csum = sum(cc, s);
        ll nl = l + csum - same[cc], nr = r - (n-1-i - csum);

        while(a < b && qw[a].first < nl) {
            int target = qw[a].first - l + 1;
            int ll = 1, rr = cc, final = -1;

            while(ll <= rr) {
                int md = (ll+rr)/2;
                int v = sum(md, s);
                if(v < target) ll++;
                else {
                    rr--;
                    final = md;
                }
            }

            ans[qw[a].second] = {i, ind[final]};
            a++;
        }

        while(a < b && qw[b].first > nr) {
            int target = r - qw[b].first + 1;
            int ll = cc, rr = n, final = -1;

            while(ll <= rr) {
                int md = (ll+rr)/2;
                int v = sum(n, s) - sum(md, s) + same[md];
                if(v < target) rr++;
                else {
                    ll++;
                    final = md;
                }
            }
            
            ans[qw[b].second] = {i, ind[final]};
            b--;
        }
    }


    for(int i = 0; i < n; i++) {
        if(i == set_ind.first) continue;
        if(arr[i] == arr[set_ind.first]) set_ind.second = i;
    }

    if(set_ind.first > set_ind.second) swap(set_ind.first, set_ind.second);

    while(a < b) {
        ans[qw[a].second] = set_ind; 
        a++;
    }

    for(auto[p, q]: ans) {
        cout << a+1 << ' ' << b+1 << endl;
    }


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