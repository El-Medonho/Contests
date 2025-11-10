#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ld;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> d(n), p(n), c(n), lx(n), rx(n), ly(n), ry(n);
    vector<ld> x(n);

    for(int i = 0; i < n; i++){
        cin >> d[i] >> p[i] >> c[i] >> lx[i] >> rx[i] >> ly[i] >> ry[i];
        x[i] = lx[i] + rx[i];
        x[i] /= 2;
    }

    vector<ld> dp(1<<n, -1e18); dp[0] = 0;
    ld ans = 0;
    vector<ll> t(1<<n, 0);

    for(int m = 0; m < (1<<n); m++){
        if(dp[m] < 0) continue;
        for(int i = 0; i < n; i++){
            if(m&(1<<i)) continue;
            int nm = m ^ (1<<i);
            
            if(t[m] + c[i] > d[i]){
                continue;
            }
            t[nm] = t[m] + c[i];
            ld sum = dp[m]; sum += p[i];
            
            ld eta = ry[i] >= t[nm] ? 1 : 0;
            if(ly[i] != ry[i]) eta = (((ld)ry[i])-(t[nm])) / (ry[i] - ly[i]);
            if(eta < 0) eta = 0;
            if(eta > 1) eta = 1;
            sum += x[i] * eta;
            // if(nm == 2) cout << ry[i] - t[nm] << endl;

            
            dp[nm] = max(dp[nm], sum);
        }

        ans = max(ans, dp[m]);
    }


    cout << fixed << setprecision(15) << ans << endl;


    return 0;
}