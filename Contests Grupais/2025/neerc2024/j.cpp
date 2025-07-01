#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n,m; cin >> n >> m;

    vector<int> vis(n, 0), sum(n, 0);

    vector<vector<int>> in(n), out(n);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;

        in[b].push_back(a);
        out[a].push_back(b);
    }

    set<pair<int,int>> pq;

    ll ans_sum = 0;

    vector<int> ans(0); ans.reserve(n);

    for(int i = 0; i < n; i++){
        pq.emplace(sum[i] = in[i].size()-out[i].size(), i);
    }

    while(!pq.empty()){
        int cc = (*pq.begin()).second; pq.erase(pq.begin());
        if(vis[cc]) continue;
        vis[cc] = 1;

        ans.push_back(cc);
        ans_sum += -sum[cc];

        for(int j: in[cc]){
            if(vis[j]) continue;
            pq.erase(make_pair(sum[j], j));
            sum[j]++;
            pq.emplace(make_pair(sum[j], j));
        }
        for(int j: out[cc]){
            if(vis[j]) continue;
            pq.erase(make_pair(sum[j], j));
            sum[j]--;
            pq.emplace(make_pair(sum[j], j));
        }
    }

    assert(ans_sum >= 0);

    for(int i: ans) cout << i+1 << ' ';
    cout << endl;


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