#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

ll MOD(ll a, ll m) {
    return (a%m + m ) % m;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;

    ll m;
    cin >> m;

    ll ans = 0;

    vector<ll> l(127), r(127);
    vector<vector<ll>> lp(127, vector<ll>(127)), rp(127, vector<ll>(127));
    
    ll currAns = 0;


    for(int i = s.size()-1; i >= 0; i--) {
        char c = s[i];
        for(int c2 = 33; c2 < 127; c2++) {
            rp[c][c2] += r[c2];
        }
        r[c]++;
    }

    for(int i = 0; i < s.size(); i++) {
        r[s[i]]--;
        
        for(int c = 33; c < 127; c++) {
            currAns = MOD(currAns - lp[c][s[i]] * r[c],m);
            rp[s[i]][c] -= r[c];
        }


        if(i > 0) {
            for(int c = 33; c < 127; c++) {
                currAns = MOD(currAns + l[c] * rp[s[i-1]][c],m);
                lp[c][s[i-1]] += l[c];
            }
            l[s[i-1]]++;
        }

        ans += currAns;
        if(ans >= m) ans -= m;
    }

    cout << ans << '\n';

    return 0;
}