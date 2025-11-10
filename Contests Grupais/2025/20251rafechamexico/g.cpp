#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){
    
    int n; cin >> n;
    int A; cin >> A;

    int res = A;

    vector<pair<int,int>> p1(0), p2(0);

    if(n == 3){
        cout << "Yes\n";
        cout << 0 << ' ' << 0 << endl;
        cout << 0 << ' ' << 1 << endl;
        cout << res*2 << ' ' << 0 << endl;
        return 0;
    }

    p1.emplace_back(0,0);
    p2.emplace_back(1,0);
    n-=2;
    int d = 0;

    while(n > 3){
        auto last1 = p1.back();
        auto last2 = p2.back();
        n-=2;
        res--;
        if(d == 0){
            p1.emplace_back(last1.first+1, last1.second+1);
            p2.emplace_back(last2.first+1, last2.second+1);
            d=1;
        }
        else{
            p1.emplace_back(last1.first-1, last1.second+1);
            p2.emplace_back(last2.first-1, last2.second+1);
            d=0;
        }
    }

    if(n == 3){
        res--;
        auto last1 = p1.back();
        auto last2 = p2.back();
    
        p1.emplace_back(last1.first+10, last1.second+2);
    }

    
    if(res <= 0){
        cout << "No\n";
        return 0;
    }
    
    cout << "Yes\n";
    
    cout << 0 << ' ' << -res << endl; 


    for(auto[a, b]: p1){
        cout << a << ' ' << b << endl;
    }

    reverse(p2.begin(), p2.end());

    for(auto[a, b]: p2){
        cout << a << ' ' << b << endl;
    }


    cout << 1 << ' ' << -res << endl;


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