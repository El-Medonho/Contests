#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n, a, b;
    cin >> n >> a >> b;

    ll div = b/a;

    for(int i=0; i<=min(61LL, n); i++){
        if((1LL<<i)>b/a){
            cout << i << endl;
           return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}