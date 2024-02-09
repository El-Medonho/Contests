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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// struct Hashing{
//     int n;
//     int p=31; //se tiver maiúscula, 53 pode ser uma boa opção
//     int m=1e9+7;
//     ll inv_p=129032259;
//     vector<ll> p_pow, inv_pow, h;
//     string s;
    
//     Hashing(string s) : s(s){
//         n=s.size();
//         p_pow.resize(n+1);
//         inv_pow.resize(n+1);
//         h.resize(n+1);

//         p_pow[0]=1;
//         inv_pow[0]=1;
//         for(int i=1; i<n; i++){
//             p_pow[i]=(p_pow[i-1]*p)%m;
//             inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
//         }
//         for(int i=1; i<=n; i++){
//             h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
//         }
//     }

//     // void build(){
//     //     p_pow[0]=1;
//     //     inv_pow[0]=1;
//     //     for(int i=1; i<n; i++){
//     //         p_pow[i]=(p_pow[i-1]*p)%m;
//     //         inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
//     //     }
//     //     for(int i=1; i<=n; i++){
//     //         h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
//     //     }
//     // }
//     ll range(int l, int r){ //index em 0, mesmo h sendo em 1
//         return (mod(h[r+1]-h[l], m)*inv_pow[l])%m;
//     }
// };

const int maxn = 1000001;
const int mod = 1004669333, base = 33, inv_base = 121778101;
const int mod2 = 1e9+7, base2 = 31, inv_base2 = 129032259;
vector<int> base_pow(maxn + 1), inv_base_pow(maxn + 1), base_pow2(maxn + 1), inv_base_pow2(maxn+1);
void prep() { // 5c2398
base_pow[0] = 1;
for (int i = 1; i <= maxn; ++i)
base_pow[i] = (ll)base_pow[i - 1] * base % mod;
inv_base_pow[0] = 1;
for (int i = 1; i <= maxn; ++i)
inv_base_pow[i] = (ll)inv_base_pow[i - 1] * inv_base
% mod;

base_pow2[0] = 1;
for (int i = 1; i <= maxn; ++i)
base_pow2[i] = (ll)base_pow2[i - 1] * base2 % mod2;
inv_base_pow2[0] = 1;
for (int i = 1; i <= maxn; ++i)
inv_base_pow2[i] = (ll)inv_base_pow2[i - 1] * inv_base2
% mod2;
}
struct hashes_t { // f1dd26
string s;
int n;
vector<int> acc_hash, acc_inv_hash;
hashes_t(const string &_s): s(_s), n(s.size()), acc_hash(n
+ 1, 0)
, acc_inv_hash(n + 1, 0) { 
for (int i = 0; i < n; ++i) {
acc_hash[i + 1] =
(acc_hash[i] + (ll)base_pow[i] * (s[i] - 'a'
+ 1)) % mod;
acc_inv_hash[i + 1] = (acc_inv_hash[i] + (ll)inv_base_pow[i] * (s[i
] - 'a' + 1)) % mod;
}
}
int get_hash(int a, int b) { // 04a73b
int hash = acc_hash[b + 1] - acc_hash[a];
if (hash < 0) hash += mod;
hash = (ll)hash * inv_base_pow[a] % mod;
return hash;
}
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n; cin >> n;
    prep();
    vector<string> s(n);
    // vector<Hashing> hs(n, Hashing(""));
    vector<hashes_t> hsn(n, hashes_t(""));
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    map<int,ll> mp;
    ll tot = 0;
    for(int i = 0; i < n; i++) {tot += s[i].size(); hsn[i] = hashes_t(s[i]);}

    for(int i = 0; i < n; i++){
        string sn = s[i];
        reverse(sn.begin(), sn.end());
        hashes_t sg(sn);
        for(int j = 0; j < s[i].size(); j++){
            ll g = sg.get_hash(0, j);
            mp[g]++;
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans += tot + s[i].size() * n;
        int k = s[i].size();
        ll exc = 0;
        for(ll j = k-1; j > -1; j--){
            int g = hsn[i].get_hash(0, j);
            ll hh = mp[g] - exc;
            ans -= hh*(j+1LL)*2LL;
            exc += hh;
        }
    }
    
    cout << ans << '\n';

    return 0;

   

    return 0;
}