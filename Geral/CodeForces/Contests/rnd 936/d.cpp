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
typedef tree<ll,null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 1e9+7;

signed solve(){
    
    ll n,x; cin >> n >> x;

    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    vector<vector<ll>> pos(34);

    set<pair<ll,ll>> st;

    bool ok = true;

    for(ll i = 0; i < n; i++){
        st.insert({i,i});

        for(ll j = 0; j < 33; j++){
            if(arr[i] & (1LL<<j)){
                pos[j].push_back(i);
            }
        }
    }

    ll ans = -1;

    for(ll j = 32; j >= 0; j--){
        ll m = pos[j].size();

        if(pos[j].size() % 2) {
            if(x & (1LL<<j)) continue;
            else {
                ok = false;
                break;
            }
        }

        vector<pair<ll,ll>> del, nw;

        for(ll k = 0; k < m; k+=2){
            ll l = pos[j][k], r = pos[j][k+1];

            auto itl = st.upper_bound({l, 1e17}), itr = st.upper_bound({r, 1e17});

            itl--; itr--;

            if(itl != itr){
                l = (*itl).first; r = (*itr).second;

                while(itl != itr){
                    del.push_back((*itr));
                    st.erase(itr);
                    
                    itr = st.upper_bound({r, 1e17});
                    itr--;
                }

                del.push_back((*(itl)));
                st.erase(itl);

                st.insert({l, r});
                nw.push_back({l,r});
            }

        }

        if(x & (1LL<<j)){
            ans = max(ans, (ll)st.size());

            for(auto h: nw) st.erase(h);
            for(auto h: del) st.insert(h);
        }
    }

    if(ok){
        ans = max(ans, (ll)st.size());
    }

    cout << ans << endl;

    return 0;
}

signed main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}