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

    for(int i = 0; i < n; i++){
        int k2 = k - arr[i].first;
        for(int l = i+1, r = n-1; l < r;){
            int x = arr[l].first + arr[r].first;
            if(x < k2) l++;
            else if(x > k2) r--;
            else{
                cout << arr[i].second + 1 << ' ' << arr[l].second + 1 << ' ' << arr[r].second + 1 << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}