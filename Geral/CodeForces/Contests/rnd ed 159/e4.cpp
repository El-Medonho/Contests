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

ll expo(ll b, ll e, ll m){
    ll res = 1;
    while(e){
        if(e&1) res = (res*b)%m;
        b = (b*b)%m;
        e>>=1;
    }
    return res;
}

struct splitmix64_hash {
	static uint64_t splitmix64(pair<unsigned, unsigned> P) {
		return P.first * 57 + P.second;
	}
	size_t operator()(pair<unsigned, unsigned> P) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64({P.first + FIXED_RANDOM, P.second + FIXED_RANDOM});
	}
};
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;


const int maxn = 1000001;
ll mod = 1004669333;
uniform_int_distribution<int> f1(58, mod-1);
ll base = f1(rng);
ll inv_base = expo(base, mod-1, mod);
ll mod2 = 1e9+7;
uniform_int_distribution<int> f2(58, mod2-1);
ll base2 = f2(rng);
ll inv_base2 = expo(base2, mod2-1, mod2);
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
// string s;
int n;
vector<int> acc_hash, acc_inv_hash;
hashes_t(const string &_s): n(_s.size()), acc_hash(n
+ 1, 0)
, acc_inv_hash(n + 1, 0) { 
for (int i = 0; i < n; ++i) {
acc_hash[i + 1] =
(acc_hash[i] + (ll)base_pow[i] * (_s[i] - 'a'
+ 1)) % mod;
acc_inv_hash[i + 1] = (acc_inv_hash[i] + (ll)inv_base_pow[i] * (_s[i
] - 'a' + 1)) % mod;
}
}
int get_hash(int a, int b) { // 04a73b
int hash = acc_hash[b + 1] - acc_hash[a];
if (hash < 0) hash += mod;
hash = (ll)hash * inv_base_pow[a] % mod;
return hash;
}
int get_inv_hash(int a, int b) { // d3dfd9
assert(a <= b);
int hash = acc_inv_hash[b + 1] - acc_inv_hash[a];
if (hash < 0) hash += mod;
hash = (ll)hash * base_pow[b] % mod;
return hash;
}
};

struct hashes_t2 { // f1dd26
// string s;
int n;
vector<int> acc_hash, acc_inv_hash;
hashes_t2(const string &_s): n(_s.size()), acc_hash(n
+ 1, 0)
, acc_inv_hash(n + 1, 0) { 
for (int i = 0; i < n; ++i) {
acc_hash[i + 1] =
(acc_hash[i] + (ll)base_pow2[i] * (_s[i] - 'a'
+ 1)) % mod2;
acc_inv_hash[i + 1] = (acc_inv_hash[i] + (ll)inv_base_pow2[i] * (_s[i
] - 'a' + 1)) % mod2;
}
}
int get_hash(int a, int b) { // 04a73b
int hash = acc_hash[b + 1] - acc_hash[a];
if (hash < 0) hash += mod2;
hash = (ll)hash * inv_base_pow2[a] % mod2;
return hash;
}
int get_inv_hash(int a, int b) { // d3dfd9
assert(a <= b);
int hash = acc_inv_hash[b + 1] - acc_inv_hash[a];
if (hash < 0) hash += mod2;
hash = (ll)hash * base_pow2[b] % mod2;
return hash;
}
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n; cin >> n;
    prep();
    vector<string> s(n);
    vector<hashes_t> hsn(n, hashes_t(""));
    vector<hashes_t2> hs(n, hashes_t2(""));
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    hash_map<pair<int,int>,ll> mp;
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        tot += s[i].size(); hs[i] = hashes_t2(s[i]); hsn[i] = hashes_t(s[i]);
    }

    for(int i = 0; i < n; i++){
        int k = s[i].size();
        for(int j = 0; j < s[i].size(); j++){
            int gg = hs[i].get_inv_hash(k-1-j, k-1);
            int g = hsn[i].get_inv_hash(k-1-j, k-1);
            mp[{gg,g}]++;
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans += tot + s[i].size() * n;
        int k = s[i].size();
        ll exc = 0;
        for(ll j = k-1; j > -1; j--){
            int gg = hs[i].get_hash(0, j);
            int g = hsn[i].get_hash(0, j);
            ll hh = mp[{gg, g}] - exc;
            ans -= hh*(j+1LL)*2LL;
            exc += hh;
        }
    }
    
    cout << ans << '\n';
   

    return 0;
}