#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long double ld;
typedef long long ll;

const int mxn = 1e5+5;

void upd(int ind, ld val, vector<ld> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]=max(val,bit[ind]);
        ind+=ind&-ind;
    }
}
ld sum(int ind, vector<ld> &bit){         //O(logn)
    ld ans=0;
    while(ind){
        ans=max(bit[ind],ans);    
        ind-=ind&-ind;    
    }
    return ans;
}

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
        arr[i] = {h, {mpini[b],mpini[a]}};
    }

    if(mpini.find("pink") == mpini.end() || mpini.find("blue") == mpini.end()){
        cout << 0 << endl;
        // cout << "aa" << endl;
        return 0;
    }

    int ini = mpini["pink"], fim = mpini["blue"];

    vector<vector<ld>> bit(n, vector<ld>(1,0));
    bit[ini].push_back(0);

    for(int i = 0; i < m; i++){
        auto [a,b] = arr[i].second;
        bit[a].push_back(0);
        bit[b].push_back(0);
    }

    upd(1, 1, bit[ini]);

    vector<int> ind(n, 1);
    ind[ini] = 2;

    // cout << sum(ind[ini], bit[ini]) << endl;

    for(int i = 0; i < m; i++){
        auto [a,b] = arr[i].second;
        ld tax = arr[i].first;

        ld cc = sum(ind[a], bit[a]); ind[a]++;

        tax *= cc;

        // cout << i << ' ' << tax << '\n';
        upd(ind[b], tax, bit[b]); ind[b]++;
    }

    cout << fixed << setprecision(20) << min(ld(10), sum(bit[fim].size()-1, bit[fim])) << endl;



    return 0;
}