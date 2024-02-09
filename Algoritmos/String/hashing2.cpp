#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

ll expo(ll b, ll e, ll m){
    ll ans = 1;
    while(e){
        ans = (ans*b)%m;
        b = (b*b)%m;
        e>>=1;
    }
    return ans;
}

const int maxn = 400001;
const int mod = 1004669333, mod2 = 2147483647;

uniform_int_distribution<int> uid(70, mod);
const int base = uid(rng);
const int inv_base = expo(base, mod-2, mod);
vector<int> base_pow(maxn + 1), inv_base_pow(maxn + 1);
void prep() { // 5c2398
    base_pow[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        base_pow[i] = (ll)base_pow[i - 1] * base % mod;
    inv_base_pow[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        inv_base_pow[i] = (ll)inv_base_pow[i - 1] * inv_base % mod;
}
struct hashes_t { // f1dd26
    string s;
    int n;
    vector<int> acc_hash, acc_inv_hash;
    hashes_t(const string &_s): s(_s), n(s.size()), acc_hash(n + 1, 0), acc_inv_hash(n + 1, 0) {
        for (int i = 0; i < n; ++i) {
            acc_hash[i + 1] =
            (acc_hash[i] + (ll)base_pow[i] * (s[i] - 'a' + 1)) % mod;
            acc_inv_hash[i + 1] = (acc_inv_hash[i] + (ll)inv_base_pow[i] * (s[i] - 'a' + 1)) % mod;
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