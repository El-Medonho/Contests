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

signed solve(){

    int n,m; cin >> n >> m;

    vector<vector<int>> graph(n), igraph(n);

    vector<int> ch(n), ich(n);

    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        igraph[b].push_back(a);

        ch[a] = graph[a].size();
        ich[b] = igraph[b].size();
    }

    queue<int> qw;

    vector<int> dist(n, 0), vis(n, 0), tdist(n, 0);

    for(int i = 0; i < n; i++) {
        vis[i] = 0;
        dist[i] = 0;

        if(ich[i] == 0) {
            vis[i] = 1;
            qw.push(i);
        }
    }

    while(!qw.size()){
        int cc = qw.front(); qw.pop();

        vis[cc] = 1;


        for(int j: graph[cc]){
            ich[j]--;
            dist[j] = max(dist[j], dist[cc]+1);

            if(ich[j] == 0) qw.push(j);
        }
    }

    for(int i = 0; i < n; i++) {
        tdist[i] = dist[i];
        vis[i] = 0;
        dist[i] = 0;

        if(ch[i] == 0) {
            vis[i] = 1;
            qw.push(i);
        }
    }

    while(!qw.size()){
        int cc = qw.front(); qw.pop();

        vis[cc] = 1;


        for(int j: graph[cc]){
            ch[j]--;
            dist[j] = max(dist[j], dist[cc]+1);

            if(ch[j] == 0) qw.push(j);
        }
    }

    int mx = 0, mx2 = 0;

    for(int i = 0; i < n; i++){
        ch[i] = graph[i].size();
        ich[i] = igraph[i].size();

        tdist[i] += dist[i];

        if(tdist[i] > mx){ mx2 = mx; mx = tdist[i];}
        if(tdist[i] > mx2 && tdist[i] != mx){ mx2 = tdist[i];}
    }

    

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1; 
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}