#include "bits/stdc++.h"

#define endl '\n'

typedef long long ll;

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    ll minx = 1e9, maxx = -1, miny = 1e9, maxy = -1;

    while(n--){
        ll x,y; cin >> x >> y;

        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }

    cout << (maxx-minx+2)*2 + (maxy-miny+2)*2 << endl;

    return 0;
}