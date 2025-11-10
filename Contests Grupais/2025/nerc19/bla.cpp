#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int INF = 1e9;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    for(int t = 0; t < 1000; t++) {
        int i0 = 0;
        vector<int> prev(1e7+5);
        vector<pair<double, int> > lis;
        int cnt = 7e6;

        for(int i = i0; cnt > 0; i++, cnt--) {
            auto it = lower_bound(lis.begin(), lis.end(), make_pair(sin(i), 0));

            if(it == lis.end()){
                lis.emplace_back();
                it = lis.end()-1;   
            }
            *it = {sin(i), i-i0};
            prev[i-i0] = it == lis.begin() ? 0 : (it-1)->second;
        }
        int L = lis.size(), cur = lis.back().second;
        cout << L << endl;
        vector<int> ans(L);
        //while(L--) ans[L] = cur, cur = prev[cur];

        // int n;
        // cin >> n;

        // for(int i=0; i<n; i++){
        //     cout << ans[i] << endl;
        // }
    }

    return 0;
}