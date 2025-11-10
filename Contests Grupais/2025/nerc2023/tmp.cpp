#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const ll mx = 1e18;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    // Regra 1: c = b%n, faz c' = c*c%n até c' ser 0 ou loopar
    // Regra 2: faz i = 1 até b, ve se b^i * b^i = b^i (mod n)
    // Regra 3: faz i = 1 até b, ve se b^i * b^i * b^i = b^i (mod n)

    int t = 1;

    while(t--){
        ll p, q; cin >> p >> q;

        int ok = 0;
        if(p < 0) {cout << "0-"; p *= -1; ok = 1;}
        cout << "1*" << p << "+1*" << p << "-0+1*" << p <<"+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p 
        << "-0-98*" << p << "+99*" << p << "-1*" << p;

        if(p % 10 == 0){
            p--;
            int pp = p; p = 1;
            if( ok) cout << "-";
            else cout << "+";
            cout << "1*" << p << "+1*" << p << "-0+1*" << p <<"+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p 
            << "-0-98*" << p << "+99*" << p << "-1*" << p;
            p = pp;
        }

        cout << "+";

        ok = 0;
        if(p < 0) {cout << "0-"; p *= -1; ok = 1;}
        cout << "1*" << p << "+1*" << p << "-0+1*" << p <<"+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p 
        << "-0-98*" << p << "+99*" << p << "-1*" << p;

        if(p % 10 == 0){
            p--;
            int pp = p; p = 1;
            if( ok) cout << "-";
            else cout << "+";
            cout << "1*" << p << "+1*" << p << "-0+1*" << p <<"+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p << "-0+1*" << p << "+1*" << p 
            << "-0-98*" << p << "+99*" << p << "-1*" << p;
            p = pp;
        }
    }


    return 0;
}