#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
    
        ll ans = 0;
    
        for(int i = 62; i > 0; i--){
            if(x >= ((1LL<<i)-1)) {ans++; x-= ((1LL<<i)-1);}
            if(x >= ((1LL<<i)-1)) {ans++; x -= ((1LL<<i)-1);}
        }
    
        assert(x == 0);
    
        cout << ans-1 << endl;
    }


    return 0;
}