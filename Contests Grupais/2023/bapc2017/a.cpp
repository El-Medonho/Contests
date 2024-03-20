#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int mxn = 1e5+5;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;
    double r; cin >> r;

    int xa,ya,xb,yb; cin >> xa >> ya >> xb >> yb;

    double nresp = 1e18;

    for(int ymin = 0; ymin <= m; ymin++){
        double nr = double(ymin)/m * r;

        double resp = 0;

        double pi = atan(1)*4;

        pi *= abs(xa-xb)/double(n);

        resp += pi*nr;
        // cout << resp << endl;
        resp += abs(ya-ymin)/double(m)*r;
        resp += abs(yb-ymin)/double(m)*r;
        nresp = min(resp, nresp);
    }

    // cout << nresp << endl;

    cout << fixed << setprecision(15) << nresp << endl;



    return 0;
}