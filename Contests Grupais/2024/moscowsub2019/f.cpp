#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

signed solve(){

    ll n,l,a,b; cin >> n >> l >> a >> b;

    vector<pair<int,int>> arr(n);

    int entries = 0;

    for(int i = 0; i < n; i++){
        char c; cin >> c;

        int p; cin >> p;

        if(c == 'E') {arr[i] = {p, 1}; entries++;}
        else arr[i] = {p, 0};
    }

    if(2*a <= b){
        cout << a*n << endl;
        return 0;
    }

    ll c = 0;

    if(a < b){
        c = entries * a;
    }

    else c = entries * b;

    int last = 1;

    sort(arr.begin(), arr.end());

    // cout << c << endl;

    for(int i = 0; i < n; i++){
        if(!last && !arr[i].second) c += min(a,b);

        last = arr[i].second;
    }

    cout << c << endl;


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