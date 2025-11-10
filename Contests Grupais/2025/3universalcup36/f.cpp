#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;

    while(t--){
        int n, k, m;
        cin >> n >> m >> k;

        vector<vector<int> > vec(n+1), colors(51), rvec(n+1);
        vector<int> color(n+1);
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            color[i] = x;
            colors[x].push_back(i);
        }
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            rvec[b].push_back(a);
        }
        vector<int> memo(n+1), dist(n+1), memo2(n+1);
        int can = 1;
        for(int i=1; i<=50; i++){
            if(colors[i].size()<=1) continue;
            queue<array<int, 3> > fila;
            for(int j:colors[i]) fila.push({0, j, j});
            int best = n+1;
            fill(memo.begin(), memo.end(), 0);
            while(!fila.empty()){
                auto [d, u, pai] = fila.front();
                fila.pop();
                if(memo[u]) continue;
                dist[u] = d;
                memo[u] = pai;
                for(int i:rvec[u]){
                    fila.push({d+1, i, pai});
                }
            }
            fill(memo2.begin(), memo2.end(), 0);
            for(int j:colors[i]) fila.push({0, j, j});
            while(!fila.empty()){
                auto [d, u, pai] = fila.front();
                fila.pop();
                if(memo2[u] && memo[u]!=memo2[u]){
                    
                }
                if(memo2[u]) continue;
                dist[u] = d;
                memo2[u] = pai;
                for(int i:rvec[u]){
                    fila.push({d+1, i, pai});
                }
            }
            
        }
        cout << (can ? "YES":"NO") << endl;
    }

    return 0;
}