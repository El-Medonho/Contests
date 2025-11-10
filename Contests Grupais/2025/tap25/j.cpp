#include "bits/stdc++.h"

#define endl '\n'

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    vector<vector<int>> t0(t), tf(t);
    for(int i = 0; i < t; i++) {
        int k;
        cin >> k;
        while(k--) {
            int curr;
            cin >> curr;
            t0[i].push_back(curr);
        }
    }
    for(int i = 0; i < t; i++) {
        int k;
        cin >> k;
        while(k--) {
            int curr;
            cin >> curr;
            tf[i].push_back(curr);
        }
    }

    if(t >= 3) {
        map<int,int> f0, ff;
        for(int i = 0; i < t; i++) {
            for(int curr : t0[i]) f0[curr]++;
            for(int curr : tf[i]) ff[curr]++;
        }
        cout << (f0 == ff ? "S" : "N") << '\n';
    }else if(t == 1) {
        cout << (t0 == tf ? "S" : "N") << '\n';
    }else {
        while(t0[0].size() > tf[0].size() && (t0[1].empty() || t0[0].back() <= t0[1].back())) {
            t0[1].push_back(t0[0].back());
            t0[0].pop_back();
        }
        while(t0[0].size() < tf[0].size() && !t0[1].empty() && (t0[0].empty() || t0[0].back() >= t0[1].back())) {
            t0[0].push_back(t0[1].back());
            t0[1].pop_back();
        }
        cout << (t0 == tf ? "S" : "N") << '\n';
    }

    return 0;
}