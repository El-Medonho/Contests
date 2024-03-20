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

// ifstream ciin("maxflow.in");
// ofstream coout("maxflow.out");

void upd(int x, int val, vector<int>& bit){
    while(x < bit.size()){
        bit[x] += val;
        x += x&-x;
    }
}

int sum(int x, vector<int>& bit){
    int ans = 0;
    while(x){
        ans += bit[x];
        x -= x&-x;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    int q; cin >> q;
    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> bl(22, vector<int>(n));
    vector<int> lvl(n, 0);
    
    vector<int> in(n, -1), out(n, -1);
    int tempo = 1;

    function<void(int,int)> dfs;

    dfs = [&](int cc, int last){

        bl[0][cc] = last;
        in[cc] = tempo++;

        for(int j: graph[cc]){
            if(j == last) continue;
            lvl[j] = lvl[cc]+1;
            dfs(j, cc);
        }

        out[cc] = tempo++;

        return;
    };

    function<int(int,int)> lca;


    lca = [&](int a, int b){

        if(a == b) return a;

        if(lvl[a] < lvl[b]) swap(a,b);

        for(int i = 21; i > -1; i--){
            int h = bl[i][a];
            if(lvl[h] < lvl[b]) continue;

            a = h;
        }

        if(a == b) return a;

        for(int i = 21; i > -1; i--){
            int g = bl[i][a], h = bl[i][b];
            if(g == h) continue;

            a = g; b = h;
        }

        return bl[0][a];
    };

    dfs(0,0);

    for(int g = 1; g < 22; g++){
        for(int i = 0; i < n; i++){
            bl[g][i] = bl[g-1][bl[g-1][i]];
        }
    }

    vector<int> bit(tempo, 0);

    while(q--){
        int s,t; cin >> s >> t; s--; t--;

        int c = lca(s,t);

        if(s != c && t != c){
            upd(in[c],1,bit);
            upd(in[c]+1,1,bit);
            upd(in[t]+1, -1, bit);
            upd(in[s]+1, -1, bit);
        }

        else if(s == t){
            upd(in[c], 1, bit);
            upd(in[c]+1, -1, bit);
        }

        else{
            upd(in[c],1,bit);
            if(s != c){
                upd(in[s]+1, -1, bit);
            }
            if(t != c){
                upd(in[t]+1, -1, bit);
            }
        }
    }

    int mx = -1e8;
    for(int i = 0; i < n; i++){
        int qu = sum(in[i], bit) - sum(out[i], bit);
        mx = max(mx, qu);
    }

    cout << mx << endl;

    return 0;
}