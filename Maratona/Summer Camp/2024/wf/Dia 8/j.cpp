#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<ll> arr(6);

    for(ll &i: arr) cin >> i;

    sort(arr.begin(), arr.end());

    map<ll,ll> freq;

    for(int i = 1; i < 6; i++) freq[arr[i]-arr[i-1]]++;

    ll dif = 0;

    for(auto [x, qtt]: freq){
        if(qtt > 2) dif = x;
    }

    for(int i = 1; i < 6; i++){
        if(arr[i]-arr[i-1] != dif){
            cout << arr[i]-dif << endl;
            return 0;
        }
    }

    if(arr[0]-dif > 0 && dif != 0) cout << arr[0]-dif << endl;

    cout << arr[5]+dif << endl;


    return 0;
}