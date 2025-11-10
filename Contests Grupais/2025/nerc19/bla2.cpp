#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int INF = 1e9;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int i0 = 0;
    int cnt = 4e6;
    unordered_map<int, int> prev;
    vector<pair<double, int> > lis;
    lis.reserve(5e4+5);

    for(int i = i0; cnt > 0; i+=10, cnt--) {
        auto it = lower_bound(lis.begin(), lis.end(), make_pair(sin(i), 0));

        if(it == lis.end()){
            lis.emplace_back();
            it = lis.end()-1;   
        }
        *it = {sin(i), i};
        prev[i] = it == lis.begin() ? 0 : (it-1)->second;
    }
    int L = lis.size(), cur = lis.back().second;
    //cout << L << endl;
    vector<int> ans(L);
    while(L--) ans[L] = cur, cur = prev[cur];

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}