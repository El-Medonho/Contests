#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod1 = 1e9+7, mod2 = 1e9+9, mod3 = 1004669333;

signed solve(){

    int n = 8; //mudar dps
    cin >> n;

    int tamanho = 35;

    uniform_int_distribution<ll> uid(40, 1e17+3);

    vector<vector<ll>> nums(tamanho, vector<ll>(26));

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < 26; j++){
            nums[i][j] = uid(rng);
        }
    }

    // set<array<int,tamanho>> st;
    map<pair<ll,ll>, int> mp;

    vector<string> dict(n);

    for(int i = 0; i < n; i++){
        cin >> dict[i];
    }

    for(int i = 0; i < n; i++){
        ll tot1 = 0, tot2 = 0;

        for(int j = 0; j < tamanho; j++){
            ll cc = 0;
            for(char c: dict[i]){
                int h = c-'a';
                cc = cc + nums[j][h] % mod3;
            }
            tot1 = (tot1 + cc) % mod1;
            tot2 = (tot2 + cc) % mod2;
        }

        int nw = i;
        if(mp.find({tot1, tot2}) != mp.end()){
            nw = mp[{tot1, tot2}];

            string s2 = dict[mp[{tot1, tot2}]], s1 = dict[i];

            if(s2.size() != s1.size()){
                if(s2.size() < s1.size()) nw = i;
            }
            else{
                if(s1 < s2) nw = i;
            }
        }

        mp[{tot1, tot2}] = nw;

        // if(i == 5 || i == 4 || i == 0){
        //     cout << tot1 << ' ' << tot2 << endl;
        // }
    }

    int q; cin >> q;

    while(q--){
        string s;
        cin >> s;

        bool did = false;

        string s2 = "";

        for(int i = (1LL<<s.size()); i > 0; i--){
            ll tot1 = 0, tot2 = 0;

            string st = "";

            for(int hh = 0; hh < s.size(); hh++){
                if(i & (1LL<<hh)) st += s[hh];
            }

            for(int j = 0; j < tamanho; j++){
                ll cc = 0;
                for(char c: st){
                    int h = c-'a';
                    cc = cc + nums[j][h] % mod3;
                }
                tot1 = (tot1 + cc) % mod1;
                tot2 = (tot2 + cc) % mod2;
            }


            if(mp.find({tot1, tot2}) == mp.end()){
                continue;
            }

            int ind = mp[{tot1, tot2}];
            did = true;

            string s1 = dict[ind];

            if(s2.size() != s1.size()){
                if(s2.size() < s1.size()) s2 = s1;
            }
            else{
                if(s1 < s2) s2 = s1;
            }

            // break;
        }
        if(!did) cout << "IMPOSSIBLE\n";
        else cout << s2 << endl;

    }


    return 0;
}



signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);


    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }


    return 0;
}