#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    ll l = 0, r = n/2;

    ll ans = 0;

    int count = 0;

    for(char c: s){
        if(count == 0 && c == '('){
            ans += l*r;
            l = 0;
        }

        if(c == '(') {l++; count++;}
        else {r--; count--;}
    }

    cout << ans << endl;

    return 0;
}