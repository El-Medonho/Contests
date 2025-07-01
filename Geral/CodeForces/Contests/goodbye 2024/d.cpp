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

const int mod = 998244353;

ll expo(ll b, ll e){
    ll res=1;
    while(e){
        if(e&1) res=res*b%mod;
        b=b*b%mod;
        e >>= 1;
    }
    return res;
}

signed solve(){
    
    int n,q; cin >> n >> q;

    vector<ll> a(n), b(n);

    vector<pair<ll,ll>> traa(n), trab(n);

    vector<int> mpa(n), mpb(n), impa(n), impb(n);

    for(ll &i: a) cin >> i;

    for(ll &i: b) cin >> i;

    for(int i = 0; i < n; i++){
        traa[i] = {a[i], i};
        trab[i] = {b[i], i};
    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    sort(traa.begin(), traa.end());

    sort(trab.begin(), trab.end());

    for(int i = 0; i < n; i++){
        mpa[traa[i].second] = i;
        mpb[trab[i].second] = i;
        impa[i] = traa[i].second;
        impb[i] = trab[i].second;
    }

    // relaciona o numero com a posição mais a direita
    map<ll,ll> posa, posb;
    ll ans = 1;

    for(int i = 0; i < n; i++){
        if(i != n-1 && a[i+1] != a[i]) posa[a[i]] = i;
        if(i != n-1 && b[i+1] != b[i]) posb[b[i]] = i;

        ans = ans * min(a[i], b[i]) % mod;
    }

    cout << ans << ' ';

    posa[a[n-1]] = n-1;
    posb[b[n-1]] = n-1;

    while(q--){
        int o, x; cin >> o >> x; x--;

        if(o == 1){
            int xx = x;
            x = mpa[x];
            ll val = a[x];

            int ind = posa[val];

            swap(mpa[xx], mpa[traa[ind].second]);
            swap(traa[x].second, traa[ind].second);

            if(posa.find(val+1) == posa.end()) posa[val+1] = ind;

            if(ind > 0 && a[ind-1] == val){
                posa[val] = ind-1;
            }
            else{
                posa.erase(val);
            }

            ans = ans * expo(min(a[ind], b[ind]), mod-2) % mod;

            a[ind]++;

            ans = ans * min(a[ind], b[ind]) % mod;
        }

        else{
            int xx = x;
            x = mpb[x];
            ll val = b[x];

            int ind = posb[val];

            swap(mpb[xx], mpb[trab[ind].second]);
            swap(trab[x].second, trab[ind].second);

            if(posb.find(val+1) == posb.end()) posb[val+1] = ind;

            if(ind > 0 && b[ind-1] == val){
                posb[val] = ind-1;
            }
            else{
                posb.erase(val);
            }

            ans = ans * expo(min(a[ind], b[ind]), mod-2) % mod;

            b[ind]++;

            ans = ans * min(a[ind], b[ind]) % mod;
        }

        cout << ans << ' ';
    }

    cout << '\n';



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