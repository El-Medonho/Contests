#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].second;
    }
    for(int i=0; i<n; i++){
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());

    vector<int> diffs(n);
    int l = -1;
    for(int i=0; i<n; i++){
        diffs[i] = v[i].first - v[i].second;
        if(diffs[i]<0 || v[i].second < l){
            cout << -1 << endl;
            return 0;
        }
        l = v[i].second;
    }
    if(is_sorted(diffs.begin(), diffs.end())){
        cout << diffs[n-1] << endl;
    }else{
        cout << -1 << endl;
    }

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