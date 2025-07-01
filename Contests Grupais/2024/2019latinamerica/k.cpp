#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;
typedef __int128_t lll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s; cin >> s;

    int n = s.size();

    vector<lll> p(1, 1);

    int l = 0;

    for(int i = n-1; i > -1; i--){
        char c; c = s[i];

        if((c == 'A' && l == -1) || (c == 'H' && l == 1)) continue;
        // if(i == 5) return 0;

        if(l == 0){
            if(c == 'A'){
                p[0] = -1;
            }
            if(c == 'A') l = -1;
            else l = 1;
            continue;
        }


        if(c == 'A') l = -1;
        else l = 1;

        int coef = 2*(i+1)+1;

        vector<lll> np(p.size()+1, 0);

        for(int i = 0; i < p.size(); i++) np[i+1] = p[i];

        if(p.size() == 1){
            // cout << i << endl;
            if(p[0] == -1) np[0] = coef;
            else np[0] = -coef;

            p = np;
            continue;
        }

        for(int i = 0; i < p.size(); i++) np[i] += p[i] * (-coef);

        p = np;
    }

    cout << p.size()-1 << endl;

    vector<ll> pp(p.size());

    for(int i = 0; i < p.size(); i++){
        pp[i] = p[i];
    }

    for(int i = p.size()-1; i > -1; i--) cout << pp[i] << ' ';
    cout << endl;

    return 0;
}