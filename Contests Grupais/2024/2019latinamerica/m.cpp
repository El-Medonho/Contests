#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    int count = 1;
    int ans = count;
    int last;
    cin >> last;

    for(int i = 0; i < n-1; i++) {
        int curr;
        cin >> curr;
        if(curr-last > x) count = 0;
        count++;
        last = curr;
        ans = max(ans,count);
    }

    cout << ans << '\n';
    
    return 0;
}