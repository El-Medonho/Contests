#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;

    int n; cin >> n;
    
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    int x; cin >> x;

    int ans = -1;
    
    int l = 0, r = n-1;
    while(l <= r){
        int meio = (l+r)/2;
        if(arr[meio] == x) {
            ans = meio;
            break;
        }
        if(arr[meio] < x) l = meio+1;
        if(arr[meio] > x) r = meio-1;
    }

    cout << ans << '\n';

    int lo = 0, hi = n-1;
    int mid;

    while(lo < hi){
        mid = (lo + hi)/2;
        if (arr[mid] <= x) lo = mid+1;
        else hi = mid;
    }

    if(arr[mid] == x) cout << mid;
    else cout << -1;
    cout << '\n';


    int list[10];

    vector<int> v;

    cin >> n;

    for(int i )

    return 0;
}