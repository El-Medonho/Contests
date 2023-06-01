#include "bits/stdc++.h"

using namespace std;

#define mxn 1e5+5
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define pii pair<int,int>
typedef long long ll;


int solve(){

    int n,k; cin >> n >> k;

    vector<string> gg(n);
    vector<vector<char>> grid(n, vector<char> (n));

    for(string &s: gg) cin >> s;
    int cc1 = 0,cc2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = gg[i][j];
            if(grid[i][j] == 'x') cc1++;
            else if(grid[i][j] == 'o') cc2++;
        }
    }

    if(abs(cc1-cc2) > 1){
        cout << "NIE\n";
        return 0;
    }

    pii a1 = {-1,-1}, a2 = {-1,-1};    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // bool pj = false;
            if(i + k <= n){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i+g][j] != 'x') pass = false;
                }
                if(pass) a1 = {i,j};
            }

            if(j + k <= n){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i][j+g] != 'x') pass = false;
                }
                if(pass) a1 = {i,j};
            }

            if(i + k <= n && j + k <= n){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i+g][j+g] != 'x') pass = false;
                }
                if(pass) a1 = {i,j};
            }

            if(i + k <= n && j - k >= -1){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i+g][j-g] != 'x') pass = false;
                }
                if(pass) a1 = {i,j};
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // bool pj = false;
            if(i + k <= n){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i+g][j] != 'o') pass = false;
                }
                if(pass) a2 = {i,j};
            }

            if(j + k <= n){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i][j+g] != 'o') pass = false;
                }
                if(pass) a2 = {i,j};
            }

            if(i + k <= n && j + k <= n){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i+g][j+g] != 'o') pass = false;
                }
                if(pass) a2 = {i,j};
            }

            if(i + k <= n && j - k >= -1){
                bool pass = true;
                for(int g = 0; g < k; g++){
                    if(grid[i+g][j-g] != 'o') pass = false;
                }
                if(pass) a2 = {i,j};
            }
        }
    }

    if((a1.first != -1 && a2.first != -1) || (a1.first == -1 && a2.first == -1 && cc1+cc2 != n*n) ){
        cout << "NIE\n";
        return 0;
    }

    if(a1.first == -1 && a2.first == -1){
        cout << "TAK\n";

        bool cross = (cc2 > cc1) ? false : true;
        bool doo = true;
        while(doo){
            doo = false;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(cross && grid[i][j] == 'x'){
                        cout << i+1 << ' ' << j+1 << endl;
                        cross = false;
                        grid[i][j] = '.';
                        doo = true;
                    }
                    if(!cross && grid[i][j] == 'o'){
                        cout << i+1 << ' ' << j+1 << endl;
                        cross = true;
                        grid[i][j] = '.';
                        doo = true;
                    }
                }
            }
        }
        return 0;
    }

    char w = '.';
    pii am;
    if(a1.first != -1){
        am = a1;
        w = 'x';
    }else {
        am = a2;
        w = 'o';
    }

    am = {-1,-1};

    for(int ii = 0; ii < n; ii++){
        for(int jj = 0; jj < n; jj++){
            if(grid[ii][jj] != w) continue;
            bool aa = false;

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // bool pj = false;
                    if(i + k <= n){
                        bool pass = true;
                        for(int g = 0; g < k; g++){
                            if(grid[i+g][j] != w) pass = false;
                            if(i+g == ii && j == jj) pass = false;

                        }
                        if(pass) aa = true;
                    }

                    if(j + k <= n){
                        bool pass = true;
                        for(int g = 0; g < k; g++){
                            if(grid[i][j+g] != w) pass = false;
                            if(i == ii && j+g == jj) pass = false;
                        }
                        if(pass) aa = true;
                    }

                    if(i + k <= n && j + k <= n){
                        bool pass = true;
                        for(int g = 0; g < k; g++){
                            if(grid[i+g][j+g] != w) pass = false;
                            if(i+g == ii && j+g == jj) pass = false;
                        }
                        if(pass) aa = true;
                    }

                    if(i + k <= n && j - k >= -1){
                        bool pass = true;
                        for(int g = 0; g < k; g++){
                            if(grid[i+g][j-g] != w) pass = false;
                            if(i+g == ii && j-g == jj) pass = false;
                        }
                        if(pass) aa = true;
                    }

                }
            }

            if(aa){
                continue;
            }
            if(!aa){
                am = {ii,jj};
            }

        }
    }

    if(am.first == -1){
        cout << "NIE\n";
        return 0;
    }

    if((w == 'x' && cc1 < cc2) || (w == 'o' && cc2 < cc1)){
        cout << "NIE\n";
        return 0;
    }

    grid[am.first][am.second] = '.';

    cout << "TAK\n";
    vector<pair<int,int>> ans(0);

    bool cross = (w == 'x') ? false : true;
    bool doo = true;
    while(doo){
        doo = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cross && grid[i][j] == 'x'){
                    ans.push_back(make_pair(i, j));
                    cross = false;
                    grid[i][j] = '.';
                    doo = true;
                }
                if(!cross && grid[i][j] == 'o'){
                    ans.push_back(make_pair(i, j));
                    cross = true;
                    grid[i][j] = '.';
                    doo = true;
                }
            }
        }
    }    

    reverse(ans.begin(), ans.end());

    ans.push_back(am);

    for(int i = 0; i < (int) ans.size(); i++){
        cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
    }

    return 0;
}

int main(){
    fastio;

    int t = 1; 
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}