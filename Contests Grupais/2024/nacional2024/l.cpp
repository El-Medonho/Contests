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

    int n,t; cin >> n >> t;

    vector<int> l(n), c(n);

    for(int i = 0; i < n; i++){
        l[i] = i;
        c[i] = i;
    }

    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<int>> memo_c(n, vector<int>(n, 0)), memo_l(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) arr[i][j] = i*n+j;
    }

    while(t--){
        char cc; cin >> cc;
        int a,b; cin >> a >> b; a--; b--;

        if(cc == 'R'){
            swap(l[a], l[b]);
        }   
        else{
            swap(c[a], c[b]);
        }
    }

    vector<vector<int>> temp = arr;

    for(int i = 0; i < n; i++){
        arr[i] = temp[l[i]];
    }

    temp = arr;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) arr[i][j] = temp[i][c[j]];
    }

    vector<int> pai(n*n);

    vector<set<int>> comp_c(n*n), comp_l(n*n);

    for(int i = 0; i < n*n; i++) {
        pai[i] = i;
        comp_c[i].insert(i%n);
        comp_l[i].insert(i/n);
    }

    function<int(int)> ff;

    ff = [&](int x){
        if(pai[x] == x) return x;
        return pai[x] = ff(pai[x]);
    };

    function<void(int, int)> uu;

    uu = [&](int x, int y){
        x = ff(x), y = ff(y);

        if(x == y) return;

        if(x > y) swap(x, y);

        pai[y] = x;

        if(comp_c[y].size() + comp_l[y].size() > comp_c[x].size() + comp_l[x].size()) {
            swap(comp_c[x], comp_c[y]);
            swap(comp_l[x], comp_l[y]);
        }

        for(int cc: comp_c[y]) comp_c[x].insert(cc);
        for(int cc: comp_l[y]) comp_l[x].insert(cc);

        return;
    };

    function<void(int,int)> uuu;

    uuu = [&](int x, int y){
        x = ff(x), y = ff(y);

        if(x == y) return;

        pai[y] = x;

        for(int i: comp_c[y]) memo_c[x][i] = 1;
        for(int i: comp_l[y]) memo_l[x][i] = 1;

        return;
    };



    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cc = i*n+j;
            if(arr[i][j] == cc) continue;
            uu(arr[i][j], cc); 
        }
    }

    for(int j = 0; j < n; j++){
        if(ff(j) != j){
            cout << "*\n";
            return 0;
        }

        for(int i: comp_c[j]) memo_c[j][i] = 1;
        for(int i: comp_l[j]) memo_l[j][i] = 1;
    }


    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            vector<int> vis(n, 0);

            for(int ii = 0; ii < i; ii++) vis[ff(ii*n+j)] = 1;
            for(int jj = 0; jj < j; jj++) vis[ff(i*n+jj)] = 1;

            
            if(ff(i*n+j) < n) {
                if(vis[ff(i*n+j)]){
                    cout << "*\n";
                    return 0;
                }

                continue;
            }


            for(int h = j, cnt = 0; cnt < n; cnt++, h = ((h+1 >= n) ? h+1-n : h+1)){
                if(vis[h] == 0){
                    bool ok = true;
                    for(int cc: comp_c[ff(i*n+j)]){
                        if(memo_c[h][cc]) ok = false;
                    }

                    for(int cc: comp_l[ff(i*n+j)]){
                        if(memo_l[h][cc]) ok = false;
                    }

                    if(ok) {
                        uuu(h, i*n+j);
                        break;
                    }
                }
            }

            if(ff(i*n+j) >= n){
                cout << "*\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ff(i*n+j)+1 << ' ';
        }
        cout << '\n';
    }


    return 0;
}