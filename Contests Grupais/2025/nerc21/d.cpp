#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){

    string s,t; cin >> s >> t;

    vector<int> ch(26, 0);

    bool ok = true;
    int i = s.size()-1, j = t.size()-1;
    for(; i > -1 && j > -1;) {
        if(s[i] == t[j]){
            if(ch[s[i]-'A']){
                ok = false;
                break;
            }
            i--; j--;
        } 
        else {
            ch[s[i]-'A'] = 1;
            i--;
        }
    }

    if(ok && j == -1){
        cout << "YES\n";
    } else cout << "NO\n";

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}