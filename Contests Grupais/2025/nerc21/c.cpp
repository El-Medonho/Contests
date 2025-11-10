#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){
    pair<int, int> a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

    vector<pair<int, int> > v;
    v.push_back(a), v.push_back(b), v.push_back(c);
    sort(v.begin(), v.end());

    int resp = 0;

    do {

        for(int i=0; i<2; i++){
            int x1 = v[0].first, y1 = v[0].second;
            int x2 = v[1].first, y2 = v[1].second;

            if(x1 == x2){

            }
            for(int j=0; j<2; j++) {

            }
        }


    } while(next_permutation(v.begin(), v.end()));

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve;
    }

    return 0;
}