#include "bits/stdc++.h"

using namespace std;

typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));

    function<void(int,int)> dfs = [&](int cc, int last){
        vector<int> ndp = dp[cc];
        dp[cc][1] = -1e8;

        for(int j: graph[cc]){
            if(j == last) continue;

            dfs(j,cc);
            
            ndp[0] = max(dp[cc][0] + dp[j][0], dp[cc][1] + dp[j][1]);
            ndp[1] = max(dp[cc][0] + dp[j][1], dp[cc][1] + dp[j][0]);

            dp[cc] = ndp;
        }

        ndp[0] += arr[cc];
        ndp[1] += arr[cc]^1;

        dp[cc] = ndp;
    };

    dfs(0,0);

    cout << max(dp[0][0], dp[0][1]) << '\n';


    return 0;
}