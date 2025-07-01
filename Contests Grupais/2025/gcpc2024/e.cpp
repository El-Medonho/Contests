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

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<pair<char,int>> p(0),i(0),d(0);

    map<pair<char,int>,int> mp;

    for(int g = 0; g < n; g++){
        char c; int b; cin >> c >> b;

        if(c == '*' && b %2==0) p.emplace_back(c,b);
        else if(c == '+' && b % 2 == 1) i.emplace_back(c,b);
        else d.emplace_back(c,b);
    }

    
    int P, I, D;
    P = p.size(), I = i.size(), D = d.size();
    
    vector<vector<vector<vector<int>>>> memo(P+1, vector<vector<vector<int>>>(I+1, vector<vector<int>>(D+1, vector<int>(2, 0))));

    auto dp = [&](auto&& self, int a, int b, int c, int par) -> int {
        if(memo[a][b][c][par]) return memo[a][b][c][par]-1;
        vector<int> qt(2, 0);

        if(a == 0 && b == 0 && c == 0) {
            memo[a][b][c][par] = par+1;
            return par;
        } 

        if(a != 0) qt[self(self,a-1,b,c,0)]++;
        if(b != 0) qt[self(self,a,b-1,c,(par+1)%2)]++;
        if(c != 0) qt[self(self,a,b,c-1,par)]++;

        int s = a+b+c;
        
        if((n-s)%2 == 0){   //vez do primeiro jogador
            if(qt[1] == 0){
                memo[a][b][c][par] = 1;
                return 0;
            }
            memo[a][b][c][par] = 2;
            return 1;
        }

        if(qt[0] == 0){
            memo[a][b][c][par] = 2;
            return 1;
        }

        memo[a][b][c][par] = 1;
        return 0;
    };

    int x; cin >> x; x%=2;

    int h = dp(dp,P,I,D,x);

    int pc = 0, ic = 0, dc = 0;

    if(h == 1){
        cout << "me" << endl;

        while(n){
            if(n){
                if(P != 0 && (memo[P-1][I][D][0]-1)) {
                    x = 0;
                    while(mp[p[pc]]) pc++;
                    cout << p[pc].first << ' ' << p[pc].second << endl; 
                    pc++;
                    P--;
                }
                else if(I != 0 && (memo[P][I-1][D][(x+1)%2]-1)){
                    x = (x+1)%2;
                    while(mp[i[ic]]) ic++;
                    cout << i[ic].first << ' ' << i[ic].second << endl; 
                    ic++;
                    I--;
                }
                else if(D != 0 && (memo[P][I][D-1][x]-1)){
                    while(mp[d[dc]]) dc++;
                    cout << d[dc].first << ' ' << d[dc].second << endl;
                    dc++;
                    D--;
                }
                n--;
            }
    
            if(n){
                char c; int b; cin >> c >> b;
                mp[make_pair(c,b)]++;
    
                if(c == '*' && b %2==0) {
                    x = 0; P--;
                }
                else if(c == '+' && b % 2 == 1) {
                    x = (x+1)%2; I--;
                }
                else D--;
    
                n--;
            }
        }
    }

    else{
        cout << "you" << endl;

        while(n){
            if(n){
                char c; int b; cin >> c >> b;
                mp[make_pair(c,b)]++;
    
                if(c == '*' && b %2==0) {
                    x = 0; P--;
                }
                else if(c == '+' && b % 2 == 1) {
                    x = (x+1)%2; I--;
                }
                else D--;
    
                n--;
            }

            if(n){
                if(P != 0 && memo[P-1][I][D][0]-1 == 0) {
                    x = 0;
                    while(mp[p[pc]]) pc++;
                    cout << p[pc].first << ' ' << p[pc].second << endl; 
                    pc++;
                    P--;
                }
                else if(I != 0 && memo[P][I-1][D][(x+1)%2]-1 == 0){
                    x = (x+1)%2;
                    while(mp[i[ic]]) ic++;
                    cout << i[ic].first << ' ' << i[ic].second << endl; 
                    ic++;
                    I--;
                }
                else if(D != 0 && memo[P][I][D-1][x]-1 == 0){
                    while(mp[d[dc]]) dc++;
                    cout << d[dc].first << ' ' << d[dc].second << endl;
                    dc++;
                    D--;
                }
                n--;
            }
    
        }
    }

    return 0;
}