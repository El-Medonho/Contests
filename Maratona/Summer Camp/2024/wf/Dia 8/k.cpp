    #include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n; cin >> n;
    string s = "ba", t = "ab";

    while(s.size() < 2*n){
        s+="ba";
        t+="ab";
    }

    cout << s << endl << t << endl;

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