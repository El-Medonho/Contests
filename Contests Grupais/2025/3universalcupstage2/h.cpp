#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

bool cmp(double a, double b){
    double eps = 1e-9;
    if(abs(a-b) < eps || a > b) return 1;
    return 0;
}

void upd(int x, int val, vector<int> &bit){
    for(;x < bit.size(); x+=x&-x) bit[x]=max(val, bit[x]);
}

int sm(int x, vector<int> &bit) {
    int ans = -1e9;
    for(; x > 0; x-=x&-x) ans = max(bit[x], ans);
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,k; cin >> n >> k;

    vector<int> sarr(n);
    for(int &i: sarr) cin >> i;
    double l = 1, r = 1000;

    int cont = 0;

    while(r-l > 1e-12){
        
        double md = (l+r)/2;
        vector<double> arr(n+1, 0);
        double sum = 0;
        // cout << md << endl;
        for(int i = 0; i < n; i++){
            sum += sarr[i]-md;
            arr[i+1] = sum;
            //cout << sum << ' ';
        } 
        //cout << endl;

        // if(cmp(sum, 0) == 0){
        //     r = md;
        //     continue;
        // }

        vector<pair<double,int>> oarr(n, make_pair(-1e18, 0));
        for(int i = 0; i < n; i++) oarr[i] = make_pair(arr[i+1], i+1);
        sort(oarr.begin(), oarr.end());

        int cnt = 1;
        vector<int> mapa(n+5, 0);
        vector<int> dp(n+5, -1e9);

        for(int i = 0; i < n; i++){
            if(i > 0 && abs(oarr[i].first-oarr[i-1].first) < 1e-9) mapa[oarr[i].second] = cnt;
            else mapa[oarr[i].second] = ++cnt;
        }
        int ans = -1;

        for(int i = 1; i <= n; i++){
            int best = -10000000;
            if(cmp(arr[i], 0)) best = 0;
            
            best = max(best, sm(mapa[i], dp));
            best++;
            if(i == n) ans = best;
            upd(mapa[i], best, dp);
        }
        // cout << endl;

        if(ans >= k){
            l = md;
        }
        else r = md;

    }

    cout << fixed << setprecision(10) << l << endl;


    return 0;
}