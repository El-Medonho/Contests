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
typedef double ld;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void print(pair<ll,ll> a){
    cout << a.first << ' ' << a.second << endl;

    return;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    pair<ll,ll> ini = {1e8,1e8};

    string s; cin >> s;

    vector<pair<ll,ll>> ans(0);

    ans.push_back(ini);

    vector<pair<ll,ll>> pos = ans;

    map<char,pair<int,int>> dir;
    map<char,char> rev;

    int d = 1e5;

    uniform_int_distribution<int> uid(100,200);

    dir['L'] = {-1,0};
    dir['R'] = {1,0};
    dir['D'] = {0,-1};
    dir['U'] = {0,1};

    rev['L'] = 'R';
    rev['R'] = 'L';
    rev['D'] = 'U';
    rev['U'] = 'D';

    char l1 = 'a',l2 = 'a';

    bool ok = false;

    for(char c: s){
        int xn = dir[c].first, yn = dir[c].second;

        ini = pos.back();

        if(c == l2 && l1 == rev[c]){
            ini = pos[pos.size()-2];
            ok = true;
            
            l2 = l1; l1 = c;        

            pos.push_back(ini);

            continue;
        }

        d += uid(rng);

        ini.first += d*xn;
        ini.second += d*yn;

        pos.push_back(ini);

        ini.first += xn;
        ini.second += yn;

        ans.push_back(ini);

        l2 = l1; l1 = c;    

        ok = false;
    }

    pair<ll,ll> diff = {0,0};

    if(s.back() == 'D') diff = {-pos.back().first,3e8};
    if(s.back() == 'U') diff = {-pos.back().first,-3e8};
    if(s.back() == 'L') diff = {3e8,-pos.back().second};
    if(s.back() == 'R') diff = {-3e8,-pos.back().second};

    for(int i = 0; i < ans.size(); i++){
        ans[i].first += diff.first;
        ans[i].second += diff.second;
    }


    if(ok){
        cout << "impossible\n";
        return 0;
    }

    ans.pop_back();
    print(ans[0]);

    cout << ans.size()-1 << endl;

    for(int i = 1; i < ans.size(); i++) print(ans[i]);


    return 0;
}