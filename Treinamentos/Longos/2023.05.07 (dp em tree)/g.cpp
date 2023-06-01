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

int main(){
    fastio;

    int n; cin >> n;
    
    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    map<int,int> all;
    for(int i: arr) all[i]++;

    vector<vector<int>> graph(n);

    vector<vector<int>> ig(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    map<int,int> mapa;

    vector<int> occ(n,0);

    function<void(int,int)> dfs;

    dfs = [&](int curr, int last){

        int h = mapa[arr[curr]];

        int s = h;
        for(int j: graph[curr]){
            if(j == last) {
                ig[curr].push_back(0);
                continue;
            }
            dfs(j,curr);
            ig[curr].push_back(mapa[arr[curr]]-s);
            s = mapa[arr[curr]];
        }
        mapa[arr[curr]]++;
        occ[curr] = mapa[arr[curr]]-h;
        return;
    };

    dfs(0,-1);

    int qtt = 0;
    for(int i: occ) if(i != 1) qtt++;

    int ans = 0;

    function<void(int,int)> dfs2;

    dfs2 = [&](int curr, int last){

        if(qtt == 0 && mapa[arr[curr]] == 1) ans++;

        bool add = false;
        if(occ[curr] > 1){
            add = true;
            qtt--;
        }

        if(occ[curr] != 1){
            bool pass = true;
            if(occ[curr] != 1 && occ[curr] != mapa[arr[curr]]) pass = false;

            for(int i : ig[curr]){
                if(i != 0 && i + 1 != mapa[arr[curr]]) pass = false;
            }

            if(pass){
                for(int i = 0; i < graph[curr].size(); i++){
                    int j = graph[curr][i];
                    if(j == last) continue;
                    if(ig[curr][i] != 0) dfs2(j, curr);
                }
            }
        }
        else if(occ[curr] == mapa[arr[curr]]){
            for(int j: graph[curr]){
                if(j == last) continue;
                dfs2(j, curr);
            }
        }

        if(add) {
            // cout << ans << '\n';
            // return 0;
            qtt++;
        }

        return;
    };

    dfs2(0,-1);

    cout << ans << '\n';

    return 0;
}
