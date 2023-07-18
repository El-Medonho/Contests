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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

signed solve(){

    int n,m; cin >> n >> m;
    int k; cin >> k;
    vector<vector<pair<int,int>>> eq(n, vector<pair<int,int>>(m, make_pair(-1,-1))), 
    inv(n, vector<pair<int,int>>(m, make_pair(-1,-2)));
    vector<vector<int>> board(n, vector<int>(m, -1));
    vector<vector<int>> qw;

    for(int i = 0; i < k; i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2; x1--; x2--; y1--; y2--;
        eq[x1][y1] = make_pair(x2,y2);
        eq[x2][y2] = make_pair(x1,y1);
        qw.push_back({x1,y1,x2,y2});
    }

    bool can = true;

    function<void(int, int)> dfs;
    dfs = [&](int i, int j){
        if(eq[i][j] == inv[i][j]) {
            can = false;
            board[i][j] = -1;
            return;
        }

        if(!can) {
            board[i][j] = -1;
            return;
        }

        if(eq[i][j].f != -1){
            int x = eq[i][j].f;
            int y = eq[i][j].s;
            if(board[x][y] != -1){
                if(board[x][y] != board[i][j]){
                    can = false;
                    board[i][j] = -1;
                    return;
                }
            }else {
                board[x][y] = board[i][j]; 
                dfs(x,y);
                if(!can) {
                    board[i][j] = -1;
                    return;
                }
                inv[x][j] = make_pair(i, y);
                inv[i][y] = make_pair(x, j);
                board[x][j] = (board[i][j]+1) % 3;
                dfs(x,j);
            }
        }

        if(!can) {
            board[i][j] = -1;
            return;
        }

        if(inv[i][j].f != -1){
            int x = inv[i][j].f;
            int y = inv[i][j].s;
            if(board[x][y] != -1){
                if(board[x][y] != (board[i][j]+1)%3){
                    can = false;
                    board[i][j] = -1;
                    return;
                }
            }else {board[x][y] = (board[i][j]+1) % 3; dfs(x,y);}
        }

        if(!can) {
            board[i][j] = -1;
            return;
        }

        return;
    };

    for(int i = 0; i < k; i++){
        int x,y;
        x = qw[i][0]; y = qw[i][1];
        for(int j = 0; j < 3; j++){
            can = true;
            board[x][y] = j;
            dfs(x,y);
            if(can) break;
        }
        if(!can){
            cout << "NO\n";
            return 0;
        }
    }

    if(!can) {cout << "NO\n"; return 0;}

    cout << "YES\n";

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}