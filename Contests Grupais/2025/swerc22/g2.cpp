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

    int qtt = 0;
    int bqt = -1;

    for(int i = 0; i < N; i++){
        if(s[i] == 'W') qtt++;
        if(i >= n-1) sum[qtt]++;
        if(i == n-1){
            bqt = qtt;
        }
    }

    for(int i = 0; i < N; i++){
        if(sum[i]) st.insert(make_pair(sum[i], i));
    }

    int diff = 0;

    ans[bqt-diff] += sum[bqt];
{
    int cnt = 10;
    auto it = st.rbegin();
    while(cnt-- && it != st.rend()){
        auto[x, ind] = *it;
        ans[ind-diff] += x;
    }
}

    for(int i = 0; i < n; i++){
        if(s[i] == 'W') diff++;
        if(sum[bqt] > 0) st.erase(make_pair(sum[bqt], bqt));
        sum[bqt]--;
        if(sum[bqt] > 0) st.insert(make_pair(sum[bqt], bqt));

        ans[bqt-diff] += sum[bqt];

        int cnt = 10;
        auto it = st.rbegin();
        while(cnt-- && it != st.rend()){
            auto[x, ind] = *it;
            ans[ind-diff] += x;
        }

        if(s[i+n] == 'W') bqt++;
    }

    for(int i = 0; i <= N; i++){
        if(ans[i] >= n){
            cout << i << endl;
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