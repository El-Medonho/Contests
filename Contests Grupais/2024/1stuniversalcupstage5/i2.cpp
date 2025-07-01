#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mod = 998244353;

ll n;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    if(n<=2) cout << 1 << endl;
    else cout << (n*2)%mod << endl;

    return 0;
}