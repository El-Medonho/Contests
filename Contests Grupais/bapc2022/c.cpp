#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;
#define double long double
const int mxn = 1e5+5;


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int c,t,r; cin >> c >> t >> r;

    double p; cin >> p;
    p = 1-p;

    double mi = 1/p;

    vector<double> arr(c+1, 0);

    function<double(int)> f;

    f = [&](int part){

        double tot = 1;
        double ans = 0;
        for(int i = 0; i < part; i++){
            tot *= mi;
            ans += tot;
        }

        ans += (tot-1)*(r);

        ans += t;

        return ans;
    };

    for(int i = 1; i <= c; i++){
        arr[i] = f(i);
    }

    vector<double> dp(c+1,1e30);

    for(int i = 1; i <= c; i++){
        for(int j = 0; j < i; j++){
            if(j == 0) dp[i] = arr[i];
            else dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }
    }

    cout << fixed << setprecision(10) << dp[c] << '\n';

    return 0;
}