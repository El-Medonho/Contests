#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

signed solve(ll l, ll r){
    // map<pair<int, int>, int> pairs;

    // map<pair<queue<int>, queue<int> >, int> mapa;

    // queue<int> a, b;
    // for(int i=1; i<=l; i++){
    //     a.push(i);
    // }

    // for(int i=1; i<=r; i++){
    //     b.push(l+i);
    // }

    ll realResp = 0;

    if(l == r){
        realResp = 3*l;
    }else if(r >= l){
        ll ini = 3*l + 4 + l - 2;
        realResp = ini + (r-l-1)*2;
    } else {
        if(l - r == 1){
            realResp = 3 + (l - 2) * 2;
        }else if(l - r == 2){
            realResp = 6 + (l - 3) * 3;
        } else {
            realResp = 10 + (l - 5 + r) * 2;
        }
    }

    // int resp = 0;
    // int par = 0;

    // while(1){
    //     if(mapa[{a, b}]) break;
    //     mapa[{a, b}] = 1;

    //     int fa = a.front();
    //     int fb = b.front();

    //     if(!pairs[{fa, fb}]) pairs[{fa, fb}] = 1, pairs[{fb, fa}] = 1, resp++;

    //     if(!par){
    //       a.pop();
    //         b.push(fa);
    //     }else{
    //         b.pop();
    //         a.push(fb);
    //     }
    //     par++;
    //     par%=2;
    // }
    cout << realResp << endl;
    // if(resp!=realResp){
    //     cout << l << ' ' << r << endl;
    //     exit(0);
    // }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    // for(int l = 2; l<=10; l++){
    //     for(int r = 1; r<=10; r++){
    //         solve(l, r);
    //     }
    // }
    ll l, r;
    cin >> l >> r;
    solve(l, r);
    return 0;
}