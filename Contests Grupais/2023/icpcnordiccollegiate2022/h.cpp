#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int main(){
    fastio;
    
    int n; cin >> n;
    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    ll ans = 0;

    for(int i = 1; i < n-1; i++){
        int l = i, r = i;

        if(arr[i-1] > arr[i] || arr[i+1] > arr[i]) continue;
        
        while(l > 0){
            if(arr[l-1] <= arr[l]) l--;
            else break;
        }

        while(r < n-1){
            if(arr[r+1] <= arr[r]) r++;
            else break;
        }

        while(i < n-1){
            if(l == i || r == i) break;
            // int h = (i-l > r-i) ? r-i : i-l;
            // ans = max(ans, min(arr[i]-arr[i-h], arr[i] - arr[i+h]));
            ans = max(ans, min(arr[i]-arr[l], arr[i] - arr[r]));
            if(i == n-1 || arr[i+1] != arr[i]) break;
            i++;
        }
    }

    cout << ans << '\n';

    return 0;
}