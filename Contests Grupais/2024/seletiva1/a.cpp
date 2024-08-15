#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n; cin >> n;

    map<char,int> mp;

    for(int i = 0; i < n; i++){
        char x; cin >> x;
        mp[x]++;
    }

    pair<int,char> ans = {1e9,'A'};

    if(mp['A'] < ans.first) ans = {mp['A'], 'A'};
    if(mp['T'] < ans.first) ans = {mp['T'], 'T'};
    if(mp['G'] < ans.first) ans = {mp['G'], 'G'};
    if(mp['C'] < ans.first) ans = {mp['C'], 'C'};

    cout << ans.first << endl;

    for(int i = 0; i < n; i++){
        cout << ans.second;
    }
    cout << endl;



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