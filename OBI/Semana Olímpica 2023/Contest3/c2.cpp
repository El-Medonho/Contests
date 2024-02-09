#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,k; cin >> n >> k;

    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for(int l = 0, r = n-1; l < r;){
        int x = arr[l].first + arr[r].first;
        if(x < k) l++;
        else if(x > k) r--;
        else{
            cout << arr[l].second + 1 << ' ' << arr[r].second + 1 << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}