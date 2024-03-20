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

struct qu{
    int u,v,k;
    qu(int uu = 0, int vv = 0, int kk = 0){
        u = uu;
        v = vv;
        k = kk;
    }
};

signed solve(){

    int q; cin >> q;

    int n = 1;

    vector<vector<int>> graph(1, vector<int>(0));
    vector<int> val = {1};

    vector<qu> querry(0);

    while(q--){
        char op; cin >> op;

        if(op == '+'){
            int u,w; cin >> u >> w;
            u--;
            graph.push_back(vector<int>(0));
            graph[u].push_back(n);
            // graph[n].push_back(u);

            val.push_back(w);
            n++;
        }

        else{
            int u,v,k; cin >> u >> v >> k;
            u--; v--;
            querry.push_back(qu(u,v,k));
        }
    }

    vector<int> lvl(n, 0);
    vector<vector<int>> bl(22, vector<int>(n, 0)), sum(22, vector<int>(n, 0));
    vector<vector<pair<int,int>>> suf(22, vector<pair<int,int>>(n, {0,0})), pre(22, vector<pair<int,int>>(n, {0,0})), best(22, vector<pair<int,int>>(n, {0,0}));

    function<void(int,int)> dfs;

    dfs = [&](int cc, int last){
        bl[0][cc] = last;
        
        int w = val[cc];
        sum[0][cc] = w;
        suf[0][cc] = {max(0, w), min(0, w)};
        pre[0][cc] = {max(0, w), min(0, w)};
        best[0][cc] = {max(0, w), min(0, w)};

        for(int j: graph[cc]){
            lvl[j] = lvl[cc]+1;
            dfs(j, cc);
        }
    };

    dfs(0,0);

    for(int g = 1; g < 22; g++){
        for(int i = 0; i < n; i++){
            int h = bl[g-1][i];
            bl[g][i] = bl[g-1][bl[g-1][i]];

            sum[g][i] = sum[g-1][i] + sum[g-1][h];
            
            suf[g][i] = {max(suf[g-1][h].first, suf[g-1][i].first + sum[g-1][h]), min(suf[g-1][h].second, suf[g-1][i].second + sum[g-1][h])};
            pre[g][i] = {max(pre[g-1][i].first, pre[g-1][h].first + sum[g-1][i]), min(pre[g-1][i].second, pre[g-1][h].second + sum[g-1][i])};

            best[g][i] = {max(best[g-1][h].first, best[g-1][i].first), min(best[g-1][h].second, best[g-1][i].second)};
            best[g][i] = {max(best[g][i].first, suf[g-1][i].first + pre[g-1][h].first), min(best[g][i].second, suf[g-1][i].second + pre[g-1][h].second)};
        }
    }

    for(auto[a,b,k] : querry){
        if(lvl[b] > lvl[a]) swap(a,b);

        pair<int,int> ca = {0,0}, cb = {0,0}, ans = {0,0};

        
        for(int i = 21; i > -1; i--){
            int h = bl[i][a];
            if(lvl[h] <= lvl[b]) continue;

            ans = {max(ans.first, ca.first + pre[i][a].first), min(ans.second, ca.second + pre[i][a].second)};
            ans = {max(ans.first, best[i][a].first), min(ans.second, best[i][a].second)};

            ca = {max(suf[i][a].first, ca.first + sum[i][a]), min(suf[i][a].second, ca.second + sum[i][a])};

            a = h;
        }

        if(lvl[a] != lvl[b]){
            ans = {max(ans.first, ca.first + pre[0][a].first), min(ans.second, ca.second + pre[0][a].second)};
            ans = {max(ans.first, best[0][a].first), min(ans.second, best[0][a].second)};

            ca = {max(suf[0][a].first, ca.first + sum[0][a]), min(suf[0][a].second, ca.second + sum[0][a])};

            a = bl[0][a];
        }

        assert(lvl[a] == lvl[b]);

        if(a == b){
            ans = {max(ans.first, ca.first + pre[0][a].first), min(ans.second, ca.second + pre[0][a].second)};
            ans = {max(ans.first, best[0][a].first), min(ans.second, best[0][a].second)};

            ca = {max(suf[0][a].first, ca.first + sum[0][a]), min(suf[0][a].second, ca.second + sum[0][a])};

            if(k <= ans.first && k >= ans.second) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        for(int i = 21; i > -1; i--){
            int h = bl[i][a], j = bl[i][b];
            if(h == j) continue;

            ans = {max(ans.first, ca.first + pre[i][a].first), min(ans.second, ca.second + pre[i][a].second)};
            ans = {max(ans.first, best[i][a].first), min(ans.second, best[i][a].second)};

            ca = {max(suf[i][a].first, ca.first + sum[i][a]), min(suf[i][a].second, ca.second + sum[i][a])};

            a = h;   

            ans = {max(ans.first, cb.first + pre[i][b].first), min(ans.second, cb.second + pre[i][b].second)};
            ans = {max(ans.first, best[i][b].first), min(ans.second, best[i][b].second)};

            cb = {max(suf[i][b].first, cb.first + sum[i][b]), min(suf[i][b].second, cb.second + sum[i][b])};

            b = j;         
        }

        int x = bl[0][a];

        int w = val[x];

        ans = {max(ans.first, ca.first + pre[1][a].first), min(ans.second, ca.second + pre[1][a].second)};
        ans = {max(ans.first, best[1][a].first), min(ans.second, best[1][a].second)};

        ca = {max(suf[0][a].first, ca.first + sum[0][a]), min(suf[0][a].second, ca.second + sum[0][a])};

        ans = {max(ans.first, cb.first + pre[1][b].first), min(ans.second, cb.second + pre[1][b].second)};
        ans = {max(ans.first, best[1][b].first), min(ans.second, best[1][b].second)};

        cb = {max(suf[0][b].first, cb.first + sum[0][b]), min(suf[0][b].second, cb.second + sum[0][b])};

        a = x; b = x;

        pair<int,int> cca = ca, ccb = cb;

        cca = {max(suf[0][a].first, ca.first + sum[0][a]), min(suf[0][a].second, ca.second + sum[0][a])};
        ccb = {max(suf[0][b].first, cb.first + sum[0][b]), min(suf[0][b].second, cb.second + sum[0][b])};

        ans = {max(ans.first, cca.first + cb.first), min(ans.second, cca.second + cb.second)};
        ans = {max(ans.first, ca.first + ccb.first), min(ans.second, ca.second + ccb.second)};

        if(k <= ans.first && k >= ans.second) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}


// 1) Pre montar o grafo
// 2) Fazer o hld
// 3) Para cada segmento, salvar a soma de todos, manter o best