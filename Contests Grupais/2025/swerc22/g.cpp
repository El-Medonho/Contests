#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){
    int n;
    cin >> n;

    vector<int> v(2*n), prefix(2*n), mapa(2*n);
    vector<ll> cont(2*n), add(2*n);
    for(int i=1; i<=2*n-1; i++){
        char x;
        cin >> x;
        v[i] = (x == 'W');
        prefix[i] = prefix[i-1] + v[i];
    }
    for(int i=n; i<=2*n-1; i++){
        mapa[prefix[i] - prefix[i-n]]++;
    }
    pair<int, int> maior = {0, 0};
    for(int i=0; i<2*n; i++){
        maior = max(maior, {mapa[i], i});
    }

    cout << maior.second << endl;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}