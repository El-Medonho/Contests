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

int kmp(string s){
    int n = (int)s.size();
    vector<int> pi(n);
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi[n-1];
}

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
const int maxn = 500001;    //CUIDADO COM ESSA BRINCADEIRA AQUI
const int mod = 1004669333, mod2 = 2147483647;

uniform_int_distribution<int> uid(70, mod), uid2(70, mod2);
const int base = uid(rng), base2 = uid2(rng);
const int inv_base = expo(base, mod-2, mod), inv_base2 = expo(base2, mod2-2, mod2);
vector<int> base_pow(maxn + 1), inv_base_pow(maxn + 1), base_pow2(maxn + 1), inv_base_pow2(maxn + 1);
void prep() { // 5c2398     //CHAMAR O PREP
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

    vector<string> arr(0);

    vector<string> s(n);
    for(string &i: s) cin >> i;
    prep();

    vector<hashes_t> hs(n, hashes_t("a"));

    for(int i = 0; i < n; i++){
        hs[i] = hashes_t(s[i]);
    }
    
    int ans = 0; 


    for(int i = 0; i < n; i++){
        string ss = s[i];

        bool ok = true;

        for(int j = 0; j < n && ok; j++){
            if(ss.size() == s[j].size() && i <= j) continue;
            if(ss.size() > s[j].size()) continue;
            
            for(int k = 0; k + ss.size() < s[j].size(); k++){
                if(hs[j].get_hash(k, k+ss.size()-1) == hs[i].get_hash(0, ss.size()-1)){
                    ok = false;
                    break;
                }
            }
        }

        if(!ok) continue;

        ans += s.size();
        arr.push_back(ss);
    }

    n = arr.size();

    vector<vector<int>> common(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cc = 0;

            if(i == j) continue;

            string h = arr[j] + arr[i];

            common[i][j] = kmp(h);
        }
    }

    vector<vector<int>> dp((1<<n), vector<int>(n, 1e9));
    // vector<int> dp((1<<n), 1e9);

    for(int i = 0; i < n; i++) dp[(1<<i)][i] = arr[i].size();

    for(int i = 1; i < (1<<n); i++){
        for(int j = 0; j < n; j++){
            if(! (i & (1<<j))) continue;
            int ii = i ^ (1<<j);

            for(int k = 0; k < n; k++){
                if(ii & (1<<k)) dp[i][j] = min(dp[i][j], dp[ii][k] + (int) arr[j].size() - common[j][k]);
            }
        }
    }

    cout << (*min_element(dp[(1<<n)-1].begin(), dp[(1<<n)-1].end())) << endl;

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