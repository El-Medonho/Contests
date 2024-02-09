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

const int wpp = 998244353;
const int maxn = 400001;
const int mod = 1004669333, base = 33, inv_base = 121778101;
vector<int> base_pow(maxn + 1), inv_base_pow(maxn + 1);
void prep() { // 5c2398
base_pow[0] = 1;
for (int i = 1; i <= maxn; ++i)
base_pow[i] = (ll)base_pow[i - 1] * base % mod;
inv_base_pow[0] = 1;
for (int i = 1; i <= maxn; ++i)
inv_base_pow[i] = (ll)inv_base_pow[i - 1] * inv_base
% mod;
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
assert(a <= b);
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

struct Hashing{
    int n;
    int p=31; //se tiver maiúscula, 53 pode ser uma boa opção
    int m=1e9+7;
    ll inv_p=129032259;
    vector<ll> p_pow, inv_pow, h;
    string s;
    
    Hashing(string s) : s(s){
        n=s.size();
        p_pow.resize(n+1);
        inv_pow.resize(n+1);
        h.resize(n+1);

        p_pow[0]=1;
        inv_pow[0]=1;
        for(int i=1; i<n; i++){
            p_pow[i]=(p_pow[i-1]*p)%m;
            inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
        }
        for(int i=1; i<=n; i++){
            h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
        }
    }

    // void build(){
    //     p_pow[0]=1;
    //     inv_pow[0]=1;
    //     for(int i=1; i<n; i++){
    //         p_pow[i]=(p_pow[i-1]*p)%m;
    //         inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
    //     }
    //     for(int i=1; i<=n; i++){
    //         h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
    //     }
    // }
    ll range(int l, int r){ //index em 0, mesmo h sendo em 1
        return (((h[r+1]-h[l]%m+m)%m)*inv_pow[l])%m;
    }
};

ll expo(ll b, ll e, ll m){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%m;
        b = (b*b)%m;
        e>>=1;
    }
    return ans;
}


signed solve(){

    int n; cin >> n;

    vector<string> arr(n);
    vector<hashes_t> hash(n, string(""));
    vector<Hashing> hash2(n, string(""));

    map<pair<int,int>, vector<int>> mp;
    prep();

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        hash[i] = hashes_t(arr[i]); hash2[i] = Hashing(arr[i]);
        int lh = hash[i].get_hash(0, arr[i].size()-1), l2 = hash2[i].range(0, arr[i].size()-1); 
        mp[{lh, l2}].push_back(i);
    }

    vector<int> infront(n, 0), inback(n, 0);

    for(int i = 0; i < n; i++){
        int m = arr[i].size();
        inback[i]--; infront[i]--;
        for(int j = 0; j < m; j++){
            int h = hash[i].get_hash(0, j), h2 = hash2[i].range(0, j);
            if(mp.find({h, h2}) != mp.end()){
                inback[i] += mp[{h, h2}].size();
                for(int k: mp[{h, h2}]) {
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