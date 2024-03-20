// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

signed main(){
    fastio;

    int n,m; cin >> n >> m;

    vector<vector<int>> graph(n), ind(n, vector<int> (n, -1));
    vector<vector<ll>> w(n, vector<ll> (n, -1)), best(n, vector<ll> (n, 1e9+50));
    
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        int c; cin >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        ind[a][b] = i;
        ind[b][a] = i;
        w[a][b] = c;
        w[b][a] = c;
    }

    function<void(int)> djiks;
    
    djiks = [&](int ini){

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n, 0), save(n, 1e9+50), mark(n,0);
        
        save[ini] = 0; vis[ini] = 1; mark[ini] = -1;
        pq.push({0,ini});

        while(!pq.empty()){

            auto [atual, cc] = pq.top();
            pq.pop();
            vis[cc] = 1;

            if(mark[cc] != cc && ind[cc][ini] != -1 && cc != ini){
                int j = mark[cc];
                ll h = atual;
                best[ini][cc] = min(h, best[ini][cc]);
                best[ini][j] = min(h - w[j][ini] + w[cc][ini], best[ini][j]);
                best[j][ini] = min(h - w[ini][j] + w[cc][ini], best[j][ini]);
                best[cc][ini] = min(h, best[cc][ini]);
            }

            if(save[cc] < atual) continue;

            for(int j: graph[cc]){
                ll nxt = w[cc][j] + atual;
                if(cc == ini){
                    pq.push({w[cc][j] + atual, j});
                    save[j] = nxt;
                    mark[j] = j;
                } else{
                    if(vis[j]) {
                        if(mark[j] != -1 && mark[j] != mark[cc]){
                            ll h = atual + save[j] + w[cc][j];
                            best[ini][mark[cc]] = min(h - w[mark[cc]][ini], best[ini][mark[cc]]);
                            best[ini][mark[j]] = min(h - w[mark[j]][ini], best[ini][mark[j]]);
                            best[mark[j]][ini] = min(h - w[ini][mark[j]], best[mark[j]][ini]);
                            best[mark[cc]][ini] = min(h - w[ini][mark[cc]], best[mark[cc]][ini]);
                        }
                        
                    }
                    else if(save[j] > nxt){
                        mark[j] = mark[cc];
                        pq.push({nxt, j});
                        save[j] = nxt;
                    }
                }
            }
        }
    };

    for(int i = 0; i < n; i++){
        djiks(i);
    }

    vector<ll> ans(m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ind[i][j] != -1) {
                ans[ind[i][j]] = best[i][j] == 1e9+50 ? -1: best[i][j];
            }
        }
    }

    for(int i: ans) cout << i << '\n';

    return 0;
}