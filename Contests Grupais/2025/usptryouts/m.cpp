#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<pair<int,int>> a;
    for(int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        if(ai == 0) continue;
        a.emplace_back(i,ai);
    }
    n = a.size();

    if(n == 0 || (n == 1 && a[0].second < d)) {
        cout << -1 << '\n';
        return 0;
    }else if(n == 1 && d <= a[0].second) {
        for(int i = 0; i < d; i++) cout << a[0].first << ' ';
        cout << '\n';
        return 0;
    }

    int curr = 0, i = 0;

    while(curr < d) {
        for(int cnt = 0; cnt < a[i].second && curr < d; cnt++) {
            cout << a[i].first << ' ';
            curr ++;
        }
        i = !i;
    }
    cout << '\n';
};