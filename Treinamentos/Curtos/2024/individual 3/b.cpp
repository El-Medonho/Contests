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

struct line{
    int xi,yi,xf,yf;
    line(int _xi = 0, int _yi = 0, int _xf = 0, int _yf = 0) : xi(_xi), yi(_yi), xf(_xf), yf(_yf) {}
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<line> arr(n);

    for(int i = 0; i < n; i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        arr[i] = line(a,b,c,d);
    }

    vector<vector<int>> graph(n);

    for(int i = 0; i < n; i++){
        if(arr[i].xi == arr[i].xf) continue;
        for(int j = 0; j < n; j++){
            if(arr[j].yi == arr[j].yf) continue;

            if( (arr[i].xi <= arr[j].xi && arr[i].xf >= arr[j].xi) && (arr[j].yi <= arr[i].yi && arr[j].yf >= arr[i].yi) ){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> vis(n, 0);

    int ans = 0;

    function<void(int,int,int)> dfs;

    vector<array<int,2>> dp(n, {-1,-1});

    dfs = [&](int cc, int last, int estado){
        vis[cc] = 1;

        int resp = 0;
        int save = 0;

        if(estado == 1){
            resp++;
            for(int j: graph[cc]){
                if(j == last) continue;
                if(dp[j][0] == -1) dfs(j,cc,0);
                resp += dp[j][0];
            }
        }

        save = max(save, resp);

        resp = 0;
        for(int j: graph[cc]){
            if(j == last) continue;
            if(dp[j][1] == -1) dfs(j,cc,1);
            resp += dp[j][1];
        }

        save = max(save, resp);

        dp[cc][estado] = save;

        return;
    };

    for(int i = 0; i < n; i++){
        if(!vis[i]) {dfs(i,i,1); ans += dp[i][1];}
    }

    cout << ans << endl;

    return 0;
}