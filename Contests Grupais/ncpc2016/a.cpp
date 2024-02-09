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

vector<int> pai, peso;
vector<vector<int>> dir = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int curr = 0;

int ff(int x){
    if(pai[x] == x) return x;
    return pai[x] = ff(pai[x]);
}

void uu(int x, int y){
    if(pai[x] == -1 || pai[y] == -1) {
        // cout << pai[(long long)1e9]; 
        return;
    }

    x = ff(x); y = ff(y);
    if( x == y ) return;

    if(peso[y] > peso[x]) swap(x,y);

    curr--;

    peso[x] += peso[y];
    pai[y] = x;
    
    return;
}

int main(){
    fastio;

    int n,m,q; cin >> n >> m >> q;
    vector<vector<int>> grid(n, vector<int> (m, 1e7)), id(n, vector<int> (m,0));
    vector<vector<pair<int,int>>> ops(q);

    {
        int cc = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                id[i][j] = ++cc;
            }
        }

        pai.resize(cc+50,-1); peso.resize(cc+50, 1);
        // for(int i = 0; i < cc+30; i++) pai[i] = i;
    }

    for(int i = 0; i < q; i++){
        int x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == x2){
            if(y1 > y2) swap(y1,y2);
            for(int j = y1; j <= y2; j++){
                if(i < grid[x1-1][j-1]){
                    ops[i].push_back(make_pair(x1-1,j-1));
                }
                grid[x1-1][j-1] = min(grid[x1-1][j-1], i);
            }
        }else{
            swap(y1,x1); swap(y2,x2);
            if(y1 > y2) swap(y1,y2);
            for(int j = y1; j <= y2; j++){
                if(i < grid[j-1][x1-1]){
                    ops[i].push_back(make_pair(j-1, x1-1));
                }
                grid[j-1][x1-1] = min(grid[j-1][x1-1], i);
            }
        }
    }
    
    vector<int> ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1e7 && pai[id[i][j]] == -1){
                curr++;
                queue<pair<int,int>> qw;
                qw.push(make_pair(i,j));
                pai[id[i][j]] = id[i][j];
                peso[id[i][j]] = 1;

                while(!qw.empty()){
                    int a = qw.front().first, b = qw.front().second; qw.pop();
                    for(int k = 0; k < 4; k++){
                        int aa = a+dir[k][0], bb = b+dir[k][1];
                        if(aa > -1 && aa < n && bb > -1 && bb < m){
                            if(grid[aa][bb] == 1e7 && pai[id[aa][bb]] == -1) { 
                                pai[id[aa][bb]] = pai[id[i][j]];
                                peso[id[i][j]]++; 
                                qw.push(make_pair(aa,bb)); 
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = q-1; i > -1; i--){
        ans.push_back(curr);
        for(int j = 0; j < ops[i].size(); j++){
            int a = ops[i][j].first, b = ops[i][j].second;
            grid[a][b] = 1e7;
            pai[id[a][b]] = id[a][b]; 
            peso[id[a][b]] = 1;
            curr++;
            for(int k = 0; k < 4; k++){
                int aa = a+dir[k][0], bb = b+dir[k][1];
                if(aa > -1 && aa < n && bb > -1 && bb < m){
                    // if(grid[aa][bb] == 1e7 && pai[id[aa][bb]] != -1) uu(id[a][b], id[aa][bb]);       //WA
                    if(grid[aa][bb] == 1e7) uu(id[a][b], id[aa][bb]);       //RTE
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++) cout << (grid[i][j] == 1e7 ? ff(id[i][j]) : -1) << ' ';
        //     cout << '\n';
        // }
    }

    reverse(ans.begin(), ans.end());
    for(int i: ans) cout << i << '\n';

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++) cout << ff(id[i][j]) << ' ';
    //     cout << '\n';
    // }

    return 0;
}