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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

struct Hashing{
    int n;
    string s;
    ll m = 1e9+7;
    ll p = 31;
    vector<ll> pow;
    vector<ll> h;

    Hashing(string str){
        s = str;
        n = s.size();
        h.resize(n+1,0); pow.resize(n+1,1);

        for(int i = 1; i <= n; i++) pow[i] = (pow[i-1]*p)%m;

        for(int i = 1; i <= n; i++) h[i] = ((h[i-1]*p)%m + (s[i-1]-'a'+1))%m;
    }

    ll range(int l, int r){
        r++;
        return ((h[r] - (h[l]*pow[r-l])%m) + m) % m;
    }

};

int main(){
    fastio;

    string s; cin >> s;
    Hashing hs(s);
    int n = s.size();

    vector<int> sz(n+1,-1); int sz_cnt = 0;
    vector<map<ll,ll>> coord(0); vector<int> coord_cnt(0);
    vector<vector<vector<int>>> occur(0);

    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        string m; cin >> m;
        if(m.size()+k-1 > s.size()){
            cout << -1 << '\n';
            continue;
        }
        int ans = 100000000;
        ll gg = 0;
        int nn = m.size();
        for(int i = 0; i < nn; i++){
            gg = ((gg*31)%(1000000007) + (m[i]-'a'+1))%(1000000007);
        }

        int l = -1;
        if(sz[m.size()] == -1){
            sz[nn] = sz_cnt++;
            l = sz[nn];
            coord.resize(sz_cnt);
            occur.push_back(vector<vector<int>>(0));
            coord_cnt.push_back(0);

            for(int i = 0; i + nn - 1 < n; i++){
                ll hh = hs.range(i, i+nn-1);
                if(coord[l].find(hh) == coord[l].end()) {
                    coord[l][hh] = coord_cnt[l]++;
                    occur[l].push_back(vector<int>(0));
                }
                occur[l][coord[l][hh]].push_back(i);
            }
        }
        l = sz[nn];
        if(coord[l].find(gg) == coord[l].end()){
            cout << -1 << '\n';
            continue;
        }
        ll f = coord[l][gg];
        if(occur[l][f].size() < k){
            cout << -1 << '\n';
            continue;
        }
        for(int i = k-1; i < occur[l][f].size(); i++){
            int curr = occur[l][f][i] - occur[l][f][i-(k-1)] + nn;
            ans = min(ans, curr);
        }
        cout << ans << '\n';
    }

    return 0;
}