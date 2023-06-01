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
    vector<vector<int>> graph(n);
    for(int i = 1; i < n; i++){
        int a; cin >> a; a--;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }

    queue<int> qq; vector<int> vis(n,0);
    vector<int> leaf(0);
    qq.push(0); vis[0] = 1;
    while(!qq.empty()){
        int cc = qq.front(); qq.pop();
        int hh = -1;
        for(int j: graph[cc]){
            if(vis[j]) continue;
            hh = j;
            vis[j] = 1;
            qq.push(j);
        }
        if(hh == -1){
            leaf.push_back(cc);
        }
    }

    vector<int> ans = {1};

    vector<int> ch(n,0);
    // function<void(int,int)> dfs;

    // dfs = [&](int curr, int last){
    //     for(int j: graph[curr]){
    //         if(j == last) continue;
    //     }
    // };
    // dfs(0,-1)

    vector<int> div;
    for(int i = 2; i < n; i++){
        if(n%i == 0) div.push_back(i);
    }

    for(int kk: div){
        vector<int> at(n,0);
        vector<int> vis(n,0);
        vector<int> hj(n,0);

        queue<int> qw;
        for(int jj: leaf) {
            at[jj] = 1;
            vis[jj] = 1;
            hj[jj] = 1;
            qw.push(jj);
        }

        bool pass = true;
        while(!qw.empty()){
            int cc = qw.front(); qw.pop();

            for(int j: graph[cc]){
                if(vis[j]) continue;
                hj[j]++;
                if( (j != 0 && hj[j] != graph[j].size()-1) || (j == 0 && hj[j] != graph.size()) ){
                    continue;
                }else{
                    int ss = 0;
                    for(int k: graph[j]){
                        if(!vis[k]) continue;
                        // if(ss && at[k] != kk){
                        //     pass = false;
                        //     break;
                        // }
                        // else if(at[k] != kk) ss = at[k];
                        if(at[k] != kk) ss += at[k];
                    }
                    if(ss >= kk) pass = false;
                    at[j] = ss%kk+1;
                    // if(at[j] > kk) pass = false;
                    if(!pass) break;
                    vis[j] = 1;
                    qw.push(j);
                }
            }
            if(!pass) break;
        }
        if(pass) ans.push_back(n/kk);
    }
    sort(ans.begin(), ans.end());

    for(int i: ans) cout << i << ' ';
    cout << n << '\n';

    return 0;
}