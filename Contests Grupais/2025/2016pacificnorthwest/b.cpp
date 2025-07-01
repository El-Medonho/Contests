#include "bits/stdc++.h"

using namespace std;

const int inf = 1e8;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> grid[i][j];
    }

    string s; cin >> s;

    vector<pair<int,int>> nxt = {{0,1},{1,0},{-1,0},{0,-1}};

    map<char,pair<int,int>> mov; 
    mov['L'] = {0,-1};
    mov['R'] = {0,1};
    mov['U'] = {-1,0};
    mov['D'] = {1,0};

    pair<int,int> R, E;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'R') R = {i,j};
            if(grid[i][j] == 'E') E = {i,j};
        }
    }

    queue<int> qw; qw.push(E.first*m+E.second);
    vector<int> dist(n*m, inf);
    dist[E.first*m+E.second] = 0;

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();
        int x = cc/m, y = cc%m;

        for(auto[X,Y]: nxt){
            int xn = x+X, yn = y+Y;
            if(xn < 0 || xn >= n || yn < 0 || yn >= m || grid[xn][yn] == '#') continue;

            int j = xn*m+yn;
            if(dist[j] > dist[cc]+1) {
                dist[j] = dist[cc]+1;
                qw.push(j);
            }
        }
    }

    vector<vector<int>> dp(s.size()+1, vector<int>(n*m, inf));

    dp[0][R.first*m+R.second] = 0;

    int ans = inf;

    for(int j = 0; j < s.size(); j++){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < n*m; i++) pq.emplace(dp[j][i], i);
     
        while(!pq.empty()){
            auto [cost,cc] = pq.top(); pq.pop();
            int x = cc/m, y = cc%m;

            dp[j+1][cc] = min(dp[j+1][cc], dp[j][cc]+1);
    
            for(auto[X,Y]: nxt){
                int xn = x+X, yn = y+Y;
                if(xn < 0 || xn >= n || yn < 0 || yn >= m || grid[xn][yn] == '#') continue;
    
                int cx = xn*m+yn;
                if(dp[j][cx] > dp[j][cc]+1) {
                    dp[j][cx] = dp[j][cc]+1;
                    pq.emplace(dp[j][cx], cx);
                }
            }

            auto[X,Y] = mov[s[j]];
            int xn = x+X, yn = y+Y;
            if(xn < 0 || xn >= n || yn < 0 || yn >= m || grid[xn][yn] == '#') {xn = x, yn = y;}
            int cx = xn*m+yn;

            dp[j+1][cx] = min(dp[j+1][cx], dp[j][cc]);
        }

        for(int a = 0; a < n; a++){
            for(int b = 0; b < m; b++){
                int cc = a*m+b;
                //cout << i << ' ' << j << ": " << dp[1][cc] << ' ' << dist[cc] << '\n';
                if(dp[j][cc] == inf || dist[cc] == inf) continue;
                ans = min(ans, dp[j][cc] + dist[cc]);
            }
        }
    }
    
    int h = s.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cc = i*m+j;
            //cout << i << ' ' << j << ": " << dp[1][cc] << ' ' << dist[cc] << '\n';
            if(dp[h][cc] == inf || dist[cc] == inf) continue;
            ans = min(ans, dp[h][cc] + dist[cc]);
        }
    }

    cout << ans << '\n';

    return 0;
}