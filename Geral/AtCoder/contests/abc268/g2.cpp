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

ll expo(ll b, ll e, ll m){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%m;
        b = (b*b)%m;
        e>>=1;
    }
    return ans;
}
const int wpp = 998244353;
const int maxn = 400001;
const int mod = 1004669333, mod2 = 2147483647;

uniform_int_distribution<int> uid(70, mod), uid2(70, mod2);
const int base = uid(rng), base2 = uid2(rng);
const int inv_base = expo(base, mod-2, mod), inv_base2 = expo(base2, mod2-2, mod2);
vector<int> base_pow(maxn + 1), inv_base_pow(maxn + 1), base_pow2(maxn + 1), inv_base_pow2(maxn + 1);
void prep() { // 5c2398
    base_pow[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        base_pow[i] = (ll)base_pow[i - 1] * base % mod;
    inv_base_pow[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        inv_base_pow[i] = (ll)inv_base_pow[i - 1] * inv_base % mod;

    base_pow2[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        base_pow2[i] = (ll)base_pow2[i - 1] * base2 % mod2;
    inv_base_pow2[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        inv_base_pow2[i] = (ll)inv_base_pow2[i - 1] * inv_base2 % mod2;
}
struct hashes_t { // f1dd26
    string s;
    int n;
    vector<pair<int,int>> acc_hash, acc_inv_hash;
    hashes_t(const string &_s): s(_s), n(s.size()), acc_hash(n + 1, {0,0}), acc_inv_hash(n + 1, {0,0}) {
        for (int i = 0; i < n; ++i) {
            acc_hash[i + 1].first = (acc_hash[i].first + (ll)base_pow[i] * (s[i] - 'a' + 1)) % mod;
            acc_inv_hash[i + 1].first = (acc_inv_hash[i].first + (ll)inv_base_pow[i] * (s[i] - 'a' + 1)) % mod;

            acc_hash[i + 1].second = (acc_hash[i].second + (ll)base_pow2[i] * (s[i] - 'a' + 1)) % mod2;
            acc_inv_hash[i + 1].second = (acc_inv_hash[i].second + (ll)inv_base_pow2[i] * (s[i] - 'a' + 1)) % mod2;
        }
    }
    pair<int,int> get_hash(int a, int b) { // 04a73b
        assert(a <= b);
        pair<int,int> hash = {acc_hash[b + 1].first - acc_hash[a].first, acc_hash[b + 1].second - acc_hash[a].second};
        if (hash.first < 0) hash.first += mod;
        hash.first = (ll)hash.first * inv_base_pow[a] % mod;
        
        if (hash.second < 0) hash.second += mod2;
        hash.second = (ll)hash.second * inv_base_pow2[a] % mod2;
        return hash;
    }
    pair<int,int> get_inv_hash(int a, int b) { // d3dfd9
        assert(a <= b);
        pair<int,int> hash = {acc_inv_hash[b + 1].first - acc_inv_hash[a].first, acc_inv_hash[b + 1].second - acc_inv_hash[a].second};
        if (hash.first < 0) hash.first += mod;
        hash.first = (ll)hash.first * base_pow[b] % mod;
        
        if (hash.second < 0) hash.second += mod2;
        hash.second = (ll)hash.second * base_pow2[b] % mod2;
        return hash;
    }
};

signed solve(){

    int n; cin >> n;

    vector<string> arr(n);
    vector<hashes_t> hash(n, string(""));

    map<pair<int,int>, vector<int>> mp;
    prep();

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        hash[i] = hashes_t(arr[i]);
        pair<int,int> lh = hash[i].get_hash(0, arr[i].size()-1); 
        mp[lh].push_back(i);
    }

    vector<int> infront(n, 0), inback(n, 0);

    for(int i = 0; i < n; i++){
        int m = arr[i].size();
        inback[i]--; infront[i]--;
        for(int j = 0; j < m; j++){
            pair<int,int> h = hash[i].get_hash(0, j);
            if(mp.find(h) != mp.end()){
                inback[i] += mp[h].size();
                for(int k: mp[h]) {
                    infront[k]++;
                }
            }
        }
    } 

    for(int i = 0; i < n; i++){
        ll b = 1 + inback[i];
        ll r = n - infront[i];

        ll x = expo(r-b+1, wpp-2, wpp);

        ll sum = (r+b)*(r-b+1)/2;

        cout << (sum * expo(r-b+1, wpp-2, wpp)) % wpp << endl;
    }
    

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