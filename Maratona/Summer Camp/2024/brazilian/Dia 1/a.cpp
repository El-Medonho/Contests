#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n; cin >> n;
    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    function<void(int,int)> dfs;

    vector<int> lvl(n, 0), dp(n, 1), vis(n, 0), pai(n, 0);
    int ans = 0, mx = 0;

    vector<vector<int>> arr(n+1);

    dfs = [&](int cc, int last){
        if(lvl[cc] <= 2) dp[cc] = 2;
        pai[cc] = last;

        for(int j: graph[cc]){
            if(j == last) continue;
            lvl[j] = lvl[cc]+1;
            dfs(j, cc);
        }

        if(graph[cc].size() == 1) {arr[lvl[cc]].push_back(cc); dp[cc] = 1;}

        mx = max(mx, lvl[cc]);
    };

    dfs(0,0);

    queue<int> qw;

    if(mx <= 2){
        cout << 0 << endl;
        return 0;
    }

    for(int i: arr[mx]) {qw.push(i); vis[i] = 1;}

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();
        int j = pai[cc];
        // cout << cc << ' ' << dp[cc] << endl;

        ans += dp[cc] == 0;
        if(lvl[cc] <= 2) continue;


        if(lvl[cc] != mx){
            for(int i: arr[lvl[cc]]) {qw.push(i); vis[i] = 1;}
        }
        mx = lvl[cc];

        if(dp[cc] == 1){
            dp[j] = 0;
        }
        else if(dp[cc] == 0 && dp[j] != 0) dp[j] = 2;
        
        if(!vis[j]){
            qw.push(j);
            vis[j] = 1;
        }
    }

    cout << ans << endl;


    return 0;
}