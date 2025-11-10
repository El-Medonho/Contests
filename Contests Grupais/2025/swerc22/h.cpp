#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int& ai : a) cin >> ai;
    for(int& bi : b) cin >> bi;

    int i = n-1, j = n-1;
    int ans = 0;

    while(i >= 0 && j >= 0) {
        if(a[i] != b[j]) {
            ans++;;
            j++;
        }
        i--,j--;
    }

    cout << ans << '\n';

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