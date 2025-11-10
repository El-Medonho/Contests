#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    int k; cin >> k;

    vector<int> qtt(n, 0);
    vector<ll> vals(n);

    

    for(int i = 0; i < n; i++) cin >> vals[i];

    sort(vals.begin(), vals.end());

    double ans = 0;

    for(int g = 0; g < k; g++){
        pair<double, int> best = {0, 0};
        for(int i = 0; i < n; i++){
            double x = 1;
            for(int j = 0; j < n; j++){
                double cc = vals[j] * qtt[j];
                if(j == i) cc += vals[j];
                x *= (1+cc/100);
            }
            if(!(abs(x - best.first) < 1e-9) && x > best.first) best = {x, i};
        }
        ans = best.first;
        qtt[best.second]++;
    }

    cout << fixed << setprecision(10) << ans << endl;
    for(int i: qtt) cout << i << ' ';
    cout << endl;



    return 0;
}