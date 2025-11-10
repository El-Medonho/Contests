#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct P {
    ll x;
    ll y;
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<P> p(n);
    for(auto& [x,y] : p) cin >> x >> y;

    sort(p.begin(), p.end(), [](P a, P b){ return a.x > b.x; });

    ll cnt = 0, ans = 0;
    ll bot = 1e9, top = -1;
    
    for(int i = 0; i <= 1e8; i++) {
        while(!p.empty() && p.back().x == i) {
            P curr = p.back();
            p.pop_back();
            if(bot == 1e9) {
                top = curr.y+1;
                bot = curr.y-1;
                ans = 2;
            }else {
                
            }
        }
    }
    return 0;
}