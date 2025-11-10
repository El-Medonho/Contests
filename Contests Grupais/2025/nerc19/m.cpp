#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;
        ll ans = 0;

        unordered_map<int,int> cnt;
        for(int i = 1; i < n; i++) cnt[a[i]]++;
        
        for(int j = 1; j < n; j++) {
            cnt[a[j]]--;
            for(int i = j-1; i >= 0; i--) {
                //cout << j << ' ' << i << endl;
                ans += cnt[2*a[j]-a[i]];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}