#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){

    int n; cin >> n;
    int N = 2*n-1;
    string s; cin >> s;

    set<pair<int,int>> st;

    vector<ll> ans(2*n, 0);
    vector<int> sum(2*n, 0);

    int qtt_w = 0;

    for(char c: s){
        if(c == 'W') qtt_w++;
    }

    cout << (qtt_w+1)/2 << endl;





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