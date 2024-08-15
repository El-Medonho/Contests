#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    string a,b; cin >> a >> b;

    while(a.back() == '0') a.pop_back();
    while(b.back() == '0') b.pop_back();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int p = stoi(a), q = stoi(b);

    int h = p+q;

    string s = to_string(h);

    while(s.back() == '0') s.pop_back();

    reverse(s.begin(), s.end());

    cout << s << endl;

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