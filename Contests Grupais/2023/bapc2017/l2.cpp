#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long ll;

const int mxn = 1e5+5;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int m; cin >> m;

    map<string,int> mpini;

    vector<pair<ld,pair<int,int>>> arr(m+1);

    int n = 0;

    for(int i = 0; i < m; i++){
        string a,b; cin >> a >> b;
        ld h; cin >> h;
        if(mpini.find(a) == mpini.end()){
            mpini[a] = n++;
        }
        if(mpini.find(b) == mpini.end()){
            mpini[b] = n++;
        }
        arr[i] = {log2(h), {mpini[b],mpini[a]}};
    }

    if(mpini.find("pink") == mpini.end() || mpini.find("blue") == mpini.end()){
        cout << 0 << endl;
        // cout << "aa" << endl;
        return 0;
    }

    int ini = mpini["pink"], fim = mpini["blue"];

    vector<ld> mx(n, log2(0));
    mx[ini] = 0;

    for(int i = 0; i < m; i++){
        auto [a,b] = arr[i].second;
        ld tax = arr[i].first;

        ld cc = mx[a];

        tax += cc;

        mx[b] = max(mx[b], tax);
    }

    // cout << fixed << setprecision(20) << min(ld(10), (mx[fim] >= 10) ? 20 :  (mx[fim] < -(1e8-60) && mx[fim] > -1e8) ? 0 : pow(ld(2), mx[fim])) << endl;
    cout << fixed << setprecision(20) << min(ld(10), pow(ld(2), mx[fim])) << endl;

    return 0;
}