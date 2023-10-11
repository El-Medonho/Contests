#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int mxn = 1e5+5;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ind = 0;
    int resp[] = {0,0};
    for(int i = n-1; i > -1; i--){
        resp[ind] += arr[i];
        ind = (ind+1)%2;
    }

    cout << resp[0] << ' ' << resp[1] << endl;

    return 0;
}