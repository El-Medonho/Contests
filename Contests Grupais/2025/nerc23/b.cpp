#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t; while(t--){

        ll x; cin >> x;
        vector<int> ans(0); int mx = 0;
        for(int i = 2; i <= 30000; i++){
            int cnt = 0;
            ll s = x;
            while(x){
                if(x%i == 0) cnt++;
                x /= i;
            }
            x = s;
            if(mx == cnt){
                ans.push_back(i);
            }
            else if(cnt > mx){
                mx = cnt; ans.clear();
                ans.push_back(i);
            }
        }

        if(x > 30000){
            for(int h: ans){
                ll lh = x/h;
            }
            if(mx == 1) ans.push_back(x);
        }

        cout << mx << ' ' << ans.size() << '\n';
        for(int i: ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}