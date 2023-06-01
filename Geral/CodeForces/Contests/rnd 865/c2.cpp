#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int main(){
    fastio;
    int t; cin >> t;

    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n);
        for(ll &i: arr) cin >> i;

        ll o = 0,e = 0;

        for(int i = 0; i < n; i++){
            ll a; a = arr[i];
            if(i&1) o+=a;
            else e+=a;
        }

        if(n&1){
            cout << "yes" << endl;
        }else{
            if(o < e) cout << "no" << endl;
            else cout << "yes" << endl;
        }
    }
    return 0;
}