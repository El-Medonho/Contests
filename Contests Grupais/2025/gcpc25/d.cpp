#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    pair<int,int> x = {-2e9, 2e9}, y = {-2e9, 2e9};
    
    while(n--){
        int a,b; cin >> a >> b; 
        x.first = max(x.first, a);
        x.second = min(x.second, a);

        y.first = max(y.first, b);
        y.second = min(y.second, b);
    }

    cout << 4 << endl;
    cout << x.first << ' ' << y.first << endl;
    cout << x.second << ' ' << y.first << endl;
    cout << x.second << ' ' << y.second << endl;
    cout << x.first << ' ' << y.second << endl;


    

    return 0;
}