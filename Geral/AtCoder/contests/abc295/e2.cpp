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
    ll resp = 1;
    while(e){
        if(e&1) resp = (resp * b) % mod;
        b = (b*b) % mod;
        e>>=1;
    }
    return resp;
}

signed solve(){
    
    vector<ll> fat(1e6, 1), inv(1e6), invf(1e6);

    for(int i = 1; i < 8e5; i++) fat[i] = fat[i-1] * i % mod;

    for(int i = 1; i < 8e5; i++) {inv[i] = expo(i, mod-2); invf[i] = expo(fat[i], mod-2);}

    invf[0] = invf[1];

    int n,m,k; cin >> n >> m >> k;

    vector<int> arr;
    vector<int> freq(m+3, 0);


    int num = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0) num++;
        else {arr.push_back(x); freq[x]++;}
    }

    sort(arr.begin(), arr.end());

    int sz = arr.size();

    int p1 = sz-1;

    ll den = expo(m, num);

    ll ans = 0;

    int es = sz;

    for(int x = m; x > 0; x--){
        ll resp = 0;
        
        while(p1 >= 0 && arr[p1] >= x) {
            es--; p1--;
        }

        for(ll l = 0; l <= num; l++){
            if(l + es >= k) break;
            ll qtt = max(k - (l + es + freq[x]), 0LL);
            ll rr = num - (qtt+l);
            if(rr < 0) continue;

            ll escolhe = (fat[num-l] * expo( fat[qtt] * fat[num-l-qtt] % mod, mod-2) % mod ) % mod;

            ll crr = expo(m - x, rr);

            ll cnt = escolhe * crr % mod;

            while(rr >= 0){
                resp = (resp + cnt) % mod; 
                rr--; qtt++;

                crr = crr * inv[m - x] % mod;

                if(rr == 0) crr = 1;

                escolhe = (fat[num-l] * ( invf[qtt] * invf[num-l-qtt] % mod) % mod );

                cnt = crr * escolhe % mod;
            }

            resp = resp * (fat[num] * expo( fat[l] * fat[num-l] % mod, mod-2 ) % mod * expo(x-1, l) % mod) % mod;
        }

        ans = (ans + resp * x % mod) % mod;
    }

    ans = ans * expo(den, mod-2) % mod;

    cout << ans << endl;

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