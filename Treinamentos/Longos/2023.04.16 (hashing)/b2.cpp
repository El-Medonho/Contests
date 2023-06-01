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

    ll range(int l, int r){ //index em 0, mesmo h sendo em 1
        return ((h[r+1]-h[l]+m)%m*inv_pow[l])%m;
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
        Hashing hm(m);
        int nn = m.size();

        if(sz[m.size()] == -1){
            sz[nn] = sz_cnt++;
            coord.resize(sz_cnt);
            occur.push_back(vector<vector<int>>(0));
            coord_cnt.push_back(0);

            for(int i = 0; i + nn - 1 < n; i++){
                ll hh = hs.range(i, i+nn-1);
                if(coord[sz[nn]].find(hh) == coord[sz[nn]].end()) {
                    coord[sz[nn]][hh] = coord_cnt[sz[nn]]++;
                    occur[sz[nn]].push_back(vector<int>(0));
                }
                occur[sz[nn]][coord[sz[nn]][hh]].push_back(i);
            }
        }
        ll gg = hm.range(0,nn-1);
        if(coord[sz[nn]].find(gg) == coord[sz[nn]].end()){
            cout << -1 << '\n';
            return 0;
        }
        ll f = coord[sz[nn]][gg];
        vector<int> jj = &occur[sz[nn]][f];
        for(int i = k-1; i < jj.size(); i++){
            int curr = jj[i] - jj[i-(k-1)] + nn;
            ans = min(ans, curr);
        }
        if(ans == 100000000) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}