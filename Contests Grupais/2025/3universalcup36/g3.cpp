#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        int k; cin >> k;
    
        vector<ll> vals(n);
        
        int kk = k/n;
        
        int d = 100;
        cout << d << endl; cout.flush();
        d = min(d, 120);
        kk -= d;
        kk = max(kk, 0);

        k -= kk*n;
        
        vector<int> qtt(n, kk);
    
        for(int i = 0; i < n; i++) cin >> vals[i];
    
        sort(vals.begin(), vals.end());
    
        double ans = 1;

        for(int i = 0; i < n; i++){
            double cc = vals[i] * qtt[i];
            
            ans *= (1+cc/100);
        }
    
        for(int g = 0; g < k; g++){
            pair<double, int> best = {0, 0};
            for(int i = 0; i < n; i++){
                double x = ans;
                double cc = vals[i] * qtt[i];
                
                double xx = x/(1+cc/100);
                xx *= (1 + (vals[i] * (qtt[i]+1)) / (double)100);

                if(xx > best.first) best = {xx, i};
            }
            ans = best.first;
            qtt[best.second]++;
        }
    
        cout << fixed << setprecision(10) << ans << endl;
        // for(int i: qtt) cout << i << ' ';
        // cout << endl;
    }




    return 0;
}