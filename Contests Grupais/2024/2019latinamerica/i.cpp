#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;

const int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,l; cin >> n >> l;

    vector<vector<int>> graph(l), clients(l);

    for(int i = 0; i < l; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int a; cin >> a; a--;
            if(a >= l) clients[i].push_back(a);
            else graph[i].push_back(a);
        }
    }

    vector<int> reach(l, 0);
    queue<int> qw; qw.push(0);

    set<int> ans2;

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();

        for(int j: graph[cc]){
            reach[j]++;

            if(reach[j] != 1) continue;

            qw.push(j);
        }

        for(int j: clients[cc]) ans2.insert(j);
    }

    ll ans = 0;

    vector<ll> times(l, 0); times[0] = 1;
    qw.push(0);

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();

        for(int j: graph[cc]){
            times[j] += times[cc];
            if(times[j] >= mod) times[j] -= mod;
            reach[j]--;

            if(reach[j]) continue;

            qw.push(j);
        }

        ans = ans + (times[cc] * clients[cc].size()) % mod;
        ans %= mod;
    }

    cout << ans << ' ' << ans2.size() << endl;

    return 0;
}