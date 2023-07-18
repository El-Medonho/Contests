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

    int a,b,c; cin >> a >> b >> c;

    int x = -1,y,z;

    if(a == b && b == c){
        cout << a << '\n';
        for(int i = 0; i < a; i++) cout << i-90 << ' ' << i-90 << ' ' << i-90 << '\n';
        return 0;
    }

    function<void()> aba;

    aba = [&](){

        for(int i = 1; i <= a; i++){

            for(int j = 1; j + i - 1 <= a; j++){
                if(i*j < a) continue;

                for(int k = 1; ( k + j -1 <= b ) && ( k + i - 1 <= c) ; k++){

                    if( (i*k < c) || (j*k < b) ) continue;

                    x = j; y = i; z = k;
                    return;
                }
            }
        }
        return;
    };

    aba();

    if(x == -1){
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> ans(0);

    ans.push_back({0,0,0});

    for(int i = 1; i < x; i++) ans.push_back({i,0,0});
    for(int i = 1; i < y; i++) ans.push_back({0,i,0});
    for(int i = 1; i < z; i++) ans.push_back({0,0,i});

    a-=x;
    a-=y;
    a++;

    for(int i = 1; i < x; i++){
        if(a == 0) break;
        for(int j = 1; j < y; j++){
            if(a == 0) break;
            a--;
            ans.push_back({i,j,0});
        }
    }

    b-=x;
    b-=z;
    b++;

    for(int i = 1; i < x; i++){
        if(b == 0) break;
        for(int j = 1; j < z; j++){
            if(b == 0) break;
            b--;
            ans.push_back({i,0,j});
        }
    }

    c-=z;
    c-=y;
    c++;

    for(int i = 1; i < y; i++){
        if(c == 0) break;
        for(int j = 1; j < z; j++){
            if(c == 0) break;
            c--;
            ans.push_back({0,i,j});
        }
    }

    set<vector<int>> st;

    for(int i = 0; i < ans.size(); i++) st.insert(ans[i]);

    if(st.size() != ans.size() || c > 0 || b > 0 || a > 0 || ans.size() > 1e6){
        ans[100000000] = {1,1,1};
    }

    cout << ans.size() << '\n';

    for(vector<int> cc: ans){
        cout << cc[0]-90 << ' ' << cc[1]-90 << ' ' << cc[2]-90 << '\n';
    }


    return 0;
}