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

signed main(){
    fastio;

    int n; cin >> n;

    int num = 2*1e3+50;
    // num = 2*9;

    vector<vector<bool>> arr(num, vector<bool> (num, false)), vis = arr;

    int xx,yy; cin >> xx >> yy; xx<<=1; yy<<=1;

    while(n--){
        int x,y; cin >> x >> y; x<<=1; y<<=1;

        if(x == xx){
            for(int i = min(y,yy); i <= max(y,yy); i++) arr[x][i] = 1;
        }else{
            for(int i = min(x,xx); i <= max(x,xx); i++) arr[i][y] = 1;
        }

        xx = x; yy = y;
    }



    queue<pair<int,int>> qw; vis[0][0] = 1; qw.push({0,0});

    vector<pair<int,int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1} };

    while(!qw.empty()){
        int x = qw.front().first, y = qw.front().second;
        qw.pop();

        for(auto [xn,yn] : dir){
            xn += x; yn += y;
            if(xn >= num || xn < 0 || yn >= num || yn < 0 || vis[xn][yn] || arr[xn][yn]) continue;
            vis[xn][yn] = 1;
            qw.push({xn, yn});
        }
    }

    int ans = 0;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(!vis[i][j] && !arr[i][j]){
                qw.push({i,j});
                vis[i][j] = 1;
                int cc = 0;

                while(!qw.empty()){
                    int x = qw.front().first, y = qw.front().second;
                    if((x & 1) && (y & 1)) cc++;
                    qw.pop();

                    for(auto [xn,yn] : dir){
                        xn += x; yn += y;
                        if(xn >= num || xn < 0 || yn >= num || yn < 0 || vis[xn][yn] || arr[xn][yn]) continue;
                        vis[xn][yn] = 1;
                        qw.push({xn, yn});
                    }
                }

                ans = max(ans, cc);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}