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

    int mn = max(0, qtt_w/2-10);
    int mx = min(N, qtt_w/2+10);

    int qtt = 0;
    int bqt = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == 'W') qtt++;
        if(i >= n-1) sum[qtt]++;
        if(i == n-1) bqt = qtt;
    }

    int diff = 0;

    for(int j = mn; j <= mx; j++){
        if(j+diff > N) break;
        ans[j] += sum[j+diff];
    }

    // cout << sum[1] << endl;

    for(int i = 0; i < n; i++){
        if(s[i] == 'W') diff++;
        sum[bqt+diff]--;

        for(int j = mn; j <= mx; j++){
            if(j+diff > N) break;
            ans[j] += sum[j+diff];
        }

        if(s[i+n] == 'W') bqt--;
    }

    for(int j = mn; j <= mx; j++){
        if(ans[j] >= n){
            cout << j << endl;
            return 0;
        }
    }

    assert(0 == 1);


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