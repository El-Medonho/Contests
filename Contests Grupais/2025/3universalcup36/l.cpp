#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<int> arr(n);
    vector<int> comp(n, 0), ch(n, 0), vis(n, 0), dvis(n, 0), tempv(n, 0);

    for(int &i: arr) {cin >> i; i--; ch[i]++;}

    int cnt = 1, rep = -1;

    auto dfs = [&](auto&& self, int cc) {
        if(tempv[cc]){
            rep = cc;
            return;
        }
        
        tempv[cc] = 1;
        int nxt = arr[cc];
        if(dvis[nxt] || comp[nxt]) { dvis[cc] = 1; return;}

        self(self, nxt);

        if(rep != -1){
            comp[cc] = cnt;
            if(rep == cc) {
                rep = -1;
                cnt++;
            }
        }

        dvis[cc] = 1;
    };

    for(int i = 0; i < n; i++){
        if(ch[i] == 0) dfs(dfs, i);
    }

    for(int i = 0; i < n; i++){
        if(dvis[i] == 0) dfs(dfs, i);
    }

    int ans = 0;
    vector<int> dont_pick(n, 0), color(n, 0);

    queue<int> qw;

    for(int i = 0; i < n; i++){
        if(ch[i] == 0) qw.push(i);
    }

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();
        int nxt = arr[cc];
        ch[nxt]--;

        if(comp[nxt]){
            if(color[cc] == 0) dont_pick[nxt]++;
            continue;
        } else if(ch[nxt] == 0) qw.push(nxt);


        if(color[cc] == 0 && comp[nxt] == 0){
            ans++;
            color[nxt] = 1;
        }
    }

    // first - pegou o ultimo
    // second - n pegou o ultimo
    pair<int,int> dp;
    bool can = true; int ini = -1;

    auto dfs2 = [&](auto&& self, int cc) {
        vis[cc] = 1;
        int nxt = arr[cc];

        if(nxt == cc) {
            dp.second = dont_pick[cc];
            return;
        }

        if(can && cc == ini){
            dp.second = dont_pick[cc];
            self(self, nxt);
            return;
        } else if(cc == ini){
            dp.first++;
            dp.second = dont_pick[cc];
            self(self, nxt);
            return;
        }

        pair<int,int> ndp = {0, 0};

        if(nxt != ini || can) ndp.first = dp.second + 1;
        ndp.second = max(dp.first + dont_pick[cc], dp.second + dont_pick[cc]);
        dp = ndp;
        if(nxt == ini) return;
        self(self, nxt);
    };

    for(int i = 0; i < n; i++){
        if(vis[i] || comp[i] == 0) continue;
        dp = {0, 0};
        ini = i;
        int cmax = 0;
        can = false;
        dfs2(dfs2, i);
        cmax = max(cmax, max(dp.first, dp.second));

        dp = {0, 0};
        can = true;
        dfs2(dfs2, i);
        cmax = max(cmax, max(dp.first, dp.second));

        ans += cmax;
    }

    // for(int i = 0; i < n; i++) cout << comp[i] << endl;
    cout << ans << endl;

    return 0;
}