#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long

    int solve(){

        ll n; cin >> n;

        vector<int> arr(0);

        while(n){
            int hh = n%9;

            hh = (hh >= 4) ? (hh+1) : hh;

            arr.push_back(hh);

            n/=9;
        }

        reverse(arr.begin(), arr.end());

        for(int i: arr) cout << i;
        cout << endl;

        return 0;
    }

int main(){
    fastio;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}