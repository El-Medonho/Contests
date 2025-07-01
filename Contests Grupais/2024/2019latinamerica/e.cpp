#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();

    vector<int> arr(0);

    for(int i = 0; i < n; i++){
        char c = s[i];

        if(c == 'E') arr.push_back(i);
    }

    int temp = arr.size();

    for(int i = 0; i < temp; i++) arr.push_back(arr[i]+n);

    int mx; cin >> mx;

    if(arr.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        int mn = (*lower_bound(arr.begin(), arr.end(), i));

        mn -= i;

        ans += max(0, mx-mn);
    }

    cout << ans << endl;

    return 0;
}