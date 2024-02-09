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

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m,q; cin >> n >> m >> q;
    vector<int> pai(n, 0), peso(n, 1);

    vector<vector<pair<int,int>>> graph(n), bl(22, vector<pair<int,int>>(n));

    for(int i = 0; i < n; i++) pai[i] = i;

    function<int(int)> ff;

    ff = [&](int x){
        if(pai[x] == x) return x;
        return pai[x] = ff(pai[x]);
    };

    function<void(int,int)> uu;

    uu = [&](int x, int y){
        x = ff(x); y = ff(y);
        if(x == y) return;
        if(peso[y]<peso[x]) swap(x,y);
        pai[x] = y;
        peso[y] += peso[x];
    };

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        a = ff(a); b = ff(b);
        if(a == b) continue;
        uu(a,b);
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
    }

    vector<bool> vis(n, 0);
    vector<int> lvl(n, 0);

    function<void(int)> dfs;

    dfs = [&](int cc){
        vis[cc] = 1;

        for(auto [j, ind]: graph[cc]){
            if(vis[j]) continue;
            bl[0][j] = {cc, ind};
            lvl[j] = lvl[cc]+1;
            dfs(j);
        }
    };

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
            bl[0][i] = {i,0};
        }
    }

    for(int i = 1; i < 22; i++){
        for(int j = 0; j < n; j++){
            bl[i][j].first = bl[i-1][bl[i-1][j].first].first;
            bl[i][j].second = max(bl[i-1][bl[i-1][j].first].second, bl[i-1][j].second);
        }
    }

    while(q--){
        int a,b; cin >> a >> b; a--; b--;
        int x = ff(a), y = ff(b);

        if(x != y){
            cout << -1 << endl;
            continue;
        }

        int ans = -1;

        if(lvl[a] < lvl[b]) swap(a,b);

        int k = lvl[a]-lvl[b];

        for(int i = 0; i < 22; i++){
            if(k & (1<<i)){
                ans = max(ans, bl[i][a].second);
                a = bl[i][a].first;
            }
        }

        if(a == b){
            cout << ans+1 << endl;
            continue;
        }

        for(int i = 21; i > -1; i--){
            if(bl[i][a].first == bl[i][b].first) continue;

            ans = max(ans, bl[i][a].second);
            ans = max(ans, bl[i][b].second);

            a = bl[i][a].first;
            b = bl[i][b].first;
        }

        ans = max(ans, bl[0][a].second);
        ans = max(ans, bl[0][b].second);

        cout << ans+1 << endl;
    }

    return 0;
}