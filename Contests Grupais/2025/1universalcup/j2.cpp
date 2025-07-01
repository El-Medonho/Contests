#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for(int& li : l) cin >> li;
    for(int& ri : r) cin >> ri;

    vector<int> dpl(n,-(1e9+5)), dpr(n,-(1e9+5)), dpl2(n, 1e9+5), dpr2(n, 1e9+5);

    dpl[0] = r[0];
    dpl2[0] = l[0];

    for(int i = 1; i < n; i++) {
        if(dpl[i-1] >= l[i]) {
            dpl[i] = min(r[i], dpl[i-1]);
            if(i >= 2 && 2*dpl[i-1] > dpl[i-2] + dpl[i]) {
                if(2*dpl2[i-1] <= dpl2[i-2] + dpl[i]) dpl[i] = 
                else dpl[i] = -(1e9+5);
            } 

        }
    }

    dpr[n-1] = r[n-1];

    for(int i = n-2; i >= 0; i--) {
        if(l[i] <= dpr[i+1]) {
            dpr[i] = min(r[i], dpr[i+1]);
        }
    }

    bool yes = false;

    for(int i = 1; i < n-1; i++) {
        yes = yes || (2*l[i] <= dpl[i-1] + dpr[i+1]);
    }

    cout << (yes ? "Yes" : "No") << '\n';
    return 0;
}