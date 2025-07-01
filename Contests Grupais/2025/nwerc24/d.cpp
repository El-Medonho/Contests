#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int mxn = 1e5+5;

int main(){
    
    int n; cin >> n;

    int sum = 0;
    vector<int> arr(n);
    ll ans = 0;

    for(int &i: arr){
        cin >> i;
        sum += i;
    }

    vector<ll> dp(sum+1, 0); dp[0] = 1;

    sort(arr.rbegin(), arr.rend());

    int l = (sum+2)/2;
    
    for(int i = 0; i < n; i++){
        int r = l + arr[i] - 1;
        for(int j = sum; j >= arr[i]; j--){
            dp[j] += dp[j-arr[i]];
            if(j >= l && j <= r) ans += dp[j-arr[i]];
        }
    }

    cout << ans << endl;



    return 0;
}