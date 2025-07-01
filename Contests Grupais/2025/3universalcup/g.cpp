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

    int n; cin >> n;

    vector<string> arr(n);

    for(string &i: arr) cin >> i;

    vector<vector<int>> vis(n, vector<int>(n, 0));

    int b = 0, ans = 0;

    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}, {1,1}, {-1,-1},{1,-1},{-1,1}};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j]) continue;
            
            if(arr[i][j] != 'M' && arr[i][j] != 'O' && arr[i][j] != 'P') continue;

            b++;
            ans++;

            vis[i][j] = 1;
            queue<pair<int,int>> qw;

            for(auto[xn, yn]: dir){
                int x = i+xn, y = j+yn;
    
                if(x < 0 || x == n || y < 0 || y == n) continue;
    
                if(vis[x][y]) continue;

                if((arr[i][j] == 'M' && arr[x][y] == 'P') || (arr[i][j] == 'O' && arr[x][y] == 'O') || (arr[i][j] == 'P' && arr[x][y] == 'M')){
                    b++; ans++;
                }

                if((arr[i][j] == 'M' && arr[x][y] == 'p') || (arr[i][j] == 'O' && arr[x][y] == 'o') || (arr[i][j] == 'P' && arr[x][y] == 'm')){
                    qw.push({x,y});
                    vis[x][y] = 1;
                }
            }

            while(!qw.empty()){
                auto [x, y] = qw.front(); qw.pop();

                vis[x][y] = 1;

                if(arr[x][y] == 'm') arr[x][y] = 'M';
                if(arr[x][y] == 'o') arr[x][y] = 'O';
                if(arr[x][y] == 'p') arr[x][y] = 'P';

                ans++;

                for(auto[xn, yn]: dir){
                    int x2 = x+xn, y2 = y+yn;
        
                    if(x2 < 0 || x2 == n || y2 < 0 || y2 == n) continue;
    
                    if((arr[x][y] == 'M' && arr[x2][y2] == 'P') || (arr[x][y] == 'O' && arr[x2][y2] == 'O') || (arr[x][y] == 'P' && arr[x2][y2] == 'M')){
                        ans++;
                    }
    
                    if((arr[x][y] == 'M' && arr[x2][y2] == 'p') || (arr[x][y] == 'O' && arr[x2][y2] == 'o') || (arr[x][y] == 'P' && arr[x2][y2] == 'm')){
                        if(!vis[x2][y2]) qw.push({x2,y2});
                        vis[x2][y2] = 1;
                    }
                }
            }
        }
    }

    cout << b << ' ' << ans << '\n';

    for(int i = 0; i < n; i++) cout << arr[i] << '\n';

    return 0;
}