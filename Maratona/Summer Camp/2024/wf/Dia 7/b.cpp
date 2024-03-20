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

using namespace std;

#define endl '\n'

typedef long long ll;

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

const int maxn = 1e6+5;    //CUIDADO COM ESSA BRINCADEIRA AQUI
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

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<string>> s(n, vector<string>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> s[i][j];
    }

    prep();

    if(n == 2){

        hashes_t s1(s[0][1]), s2(s[1][0]);

        if(s[0][1].size() != s[1][0].size() || s[0][1].size() < 2){
            cout << "NONE\n";
            return 0;
        }

        int k = s[0][1].size();

        int pos = -1;
        for(int i = 0; i < k-1; i++){
            if(s1.get_hash(0, i) == s2.get_hash(k-i-1, k-1) && s1.get_hash(i+1, k-1) == s2.get_hash(0, k-2-i)){
                if(pos == -1) pos = i;
                else{
                    cout << "MANY\n";
                    return 0;
                }
            }
        }

        if(pos == -1){
            cout << "NONE\n";
            return 0;
        }

        cout << "UNIQUE\n";

        cout << s[0][1].substr(0, pos+1) << endl;
        cout << s[0][1].substr(pos+1, k-pos-1) << endl;

        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            if(s[i][j].size() <= 1){
                cout << "NONE\n";
                return 0;
            }
        }
    }

    string a = s[0][1], b = s[0][2];

    string c1 = s[1][2];

    string c2 = s[0][1] + s[0][2];

    int k = (c2.size() - c1.size()) / 2;

    if(c1.size() < 2 || a.size() < 2 || b.size() < 2 || k <= 0){
        cout << "NONE\n";
        return 0;
    }

    if((c2.size() - c1.size()) % 2 != 0 || k >= a.size()){
        cout << "NONE\n";
        return 0;
    }

    vector<string> base(n);

    base[0] = a.substr(0, k);

    for(int i = 1; i < n; i++){
        base[i] = s[0][i].substr(k, s[0][i].size()-k);
    }

    bool ok = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(s[i][j].size() != base[i].size() + base[j].size() || (base[j].size() == 0) || (base[i].size() == 0)) ok = false;
            for(int h = 0; h < base[i].size(); h++){
                if(s[i][j][h] != base[i][h]) ok = false;
            }
            for(int h = base[i].size(); h < s[i][j].size(); h++){
                if(s[i][j][h] != base[j][h-base[i].size()]) ok = false;
            }
        }
    }



    if(!ok){
        cout << "NONE\n";
    }
    else{
        cout << "UNIQUE\n";

        for(string i: base){
            cout << i << endl;
        }
    }

    return 0;
}