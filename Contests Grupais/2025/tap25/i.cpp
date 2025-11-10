#include "bits/stdc++.h"

#define endl '\n'

typedef long long ll;

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    // vector<ll> x(m), y(m);

    vector<ll> ans(n+1, 0);

    for(int i = 0; i < m; i++){
        ll x,y; cin >> x >> y;
        int pote = 0;
        vector<int> cc(n);
        for(int j = 0; j < n; j++){
            cin >> cc[j];
            if(cc[j] == 1) pote++;
        }

        if(x/(pote+1) >= y){
            pote++; ans[n] += x/pote;
        }
        else ans[n] += y;

        for(int j = 0; j < n; j++){
            if(cc[j] == 1) ans[j] += x/pote;
            else ans[j] += y;
        }
    }

    for(int i: ans) cout << i << ' ';
    cout << endl;

    return 0;
}