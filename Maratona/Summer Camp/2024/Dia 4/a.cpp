#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define s second
const int mxn = 1e5+5;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    // vector<pair<ll,ll>> arr(n);
    vector<int> ans(n, 0);

    vector<pair<int,pair<ll,ll>>> arr(n);
    for(int i = 0; i < n; i++){
        ll x,y; cin >> x >> y;
        arr[i] = {i,{x,y}};
    }

    bool ok = false;
    ll p = 1500000;

    while(!ok){
        pair<ll,ll> cc = {0,0};
        ok = true;
        random_shuffle(arr.begin(), arr.end());

        for(int ii = 0; ii < n; ii++){
            auto [i,h] = arr[ii];
            auto [x,y] = h;
            ll a = cc.f, b = cc.s;
            ll c = 0, d = 0;

            c = max(abs(a+x), abs(b+y));
            d = max(abs(a-x), abs(b-y));


            if(c < d){
                ans[i] = 1;
                cc.f += x; cc.s += y;
            }
            else{
                ans[i] = -1;
                cc.f -= x; cc.s -= y;
            }
        }
        if(cc.f * cc.f + cc.s * cc.s > p*p) ok = false;
    }



    for(int i: ans) cout << i << ' ';
    cout << endl;

    return 0;
}