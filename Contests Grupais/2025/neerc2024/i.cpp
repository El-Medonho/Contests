#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n; cin >> n;

    vector<pair<int,int>> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i].first;
    for(int i = 0; i < n; i++) cin >> arr[i].second;

    sort(arr.begin(), arr.end());

    int l = -1, big = -1;

    int d = 0;

    for(auto[a, b]: arr){
        if((b <= big && a > l) || b < a){
            cout << -1 << endl;
            return 0;
        }

        big = b;
        l = a;
        d = max(d, b-a);
    }

    cout << d << endl;


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