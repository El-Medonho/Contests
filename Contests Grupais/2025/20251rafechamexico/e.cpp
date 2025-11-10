#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;
    
    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    for(int i = 0; i < n; i++){
        if(arr[i] >= m) {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}