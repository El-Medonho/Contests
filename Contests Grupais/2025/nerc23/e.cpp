#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){

    int n; cin >> n;

    vector<pair<ll,ll>> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    
    bool ok = true;
    
    int cnt = 200;
    vector<pair<ll,ll>> p(0);
    while(cnt-- && ok){
        random_shuffle(arr.begin(), arr.end());
        for(int i = 1; i < n; i++){
            auto [x, y] = arr[i];
            if(x == arr[i-1].first || y == arr[i-1].second || abs(x-arr[i-1].first) == abs(y-arr[i-1].second)) {
                if( (i == 1) || ( x == arr[i-2].first || y == arr[i-2].second || abs(x-arr[i-2].first) == abs(y-arr[i-2].second))) continue;
                swap(arr[i-1], arr[i-2]);
            }
    
            auto [xl, yl] = arr[i-1];
            p.emplace_back(x, yl-(x-xl)); p.emplace_back(xl, y-(xl-x));
            p.emplace_back(x, yl); p.emplace_back(xl, y);
            p.emplace_back(x, yl+(x-xl)); p.emplace_back(xl, y+(xl-x));
            p.emplace_back(xl+(y-yl), y); p.emplace_back(x+(yl-y), yl);
            p.emplace_back(xl - (y-yl), y); p.emplace_back(x - (yl-y), yl);
            ll v = (x-y+xl+yl);
            if(v%2 == 0){
                p.emplace_back(v/2, v/2 + (y-x));
                v = (xl-yl+x+y); p.emplace_back(v/2, v/2+(yl-xl));
            }
            ok = false;
            break;
        }
    }

    if(ok){
        cout << "YES\n";
        cout << arr[0].first << ' ' << arr[0].second << '\n';
        return 0;
    }

    int m = p.size();
    vector<int> valid(m, 1);
    for(int i = 0; i < n; i++){
        auto[x, y] = arr[i];
        for(int j = 0; j < m; j++){
            if(!valid[j]) continue;
            if(!(x == p[j].first || y == p[j].second || abs(x-p[j].first) == abs(y-p[j].second))) valid[j] = false;
        }
    }

    for(int j = 0; j < m; j++){
        if(valid[j] && abs(p[j].first) <= 1000000000 && abs(p[j].second) <= 1000000000){
            cout << "YES\n";
            cout << p[j].first << ' ' << p[j].second << '\n';
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}