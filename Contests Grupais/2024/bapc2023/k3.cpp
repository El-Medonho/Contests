#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int print(pair<int,int> c){
    auto[a,b] = c;

    cout << "? " << a+1 << ' ' << b+1 << endl;
    cout.flush();

    int x; cin >> x;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    pair<int,int> cc = {n/2, n/2};

    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int c = 0;
    c = print(cc);

    while(true){
        pair<int,int> mx = {-1, 0};

        for(int i = 0; i < 4; i++){
            pair<int,int> nxt = {cc.first + dir[i].first, cc.second + dir[i].second};

            if(nxt.first < 0 || nxt.first >= n || nxt.second < 0 || nxt.second >= n) continue;

            int h = (print(nxt));

            if(h > mx.first) mx = {h, i};
        }

        if(c > mx.first) break;

        cc.first += dir[mx.second].first;
        cc.second += dir[mx.second].second;

        c = mx.first;
    }

    cout << "! " << c << endl;

    return 0;
}