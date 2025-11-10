#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);

    for(int i=1; i<=n; i++) cin >> v[i];
    v.push_back(1440);

    int cont = 0;
    for(int i=1; i<n+2; i++){
        cont += (v[i] - v[i-1]) / 120;
    }

    cout << (cont >=2 ? "YES" : "NO") << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}