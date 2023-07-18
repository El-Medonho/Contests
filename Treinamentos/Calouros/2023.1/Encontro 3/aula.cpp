#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;

    int n; cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }    

    sort(arr, arr+n); // O(n*logn)

    for(int i = 0; i<n; i++) cout << arr[i] << ' ';
    cout << '\n';

    int val;
    cin >> val;

    int l = 0, r = n-1;
    int ans = -1;

    while(l <= r){
        int meio = (l+r)/2;

        if(arr[meio] == val){
            ans = meio;
            break;
        }
        if(arr[meio] > val){
            r = meio - 1;
        }
        if(arr[meio] < val){
            l = meio + 1;
        }
    }

    int lo = 0, hi = n-1;
    int mid;

    while(lo < hi){
        mid = (lo+hi)/2;
        if(arr[mid] < val) lo = mid+1;
        else hi = mid;
    }

    if(arr[mid] == val) cout << mid << '\n';
    else cout << -1;

    cout << ans << '\n';

    return 0;
}