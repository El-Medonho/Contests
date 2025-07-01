#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n; cin >> n;

    int l1 = -1, l2 = -1;

    int d = 2;

    for(int i = 0; i < n; i++){
        int x = 0;
        string s; cin >> s;
        x += 60*s[0]-'0';
        x += 10*s[2]-'0';
        x += s[3]-'0';

        if(x - l1 <= 10) d = min(d, 1);
        if(x - l2 <= 10) d = min(d, 0);

        l2 = l1; l1 = x;
    }

    cout << d << endl;


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