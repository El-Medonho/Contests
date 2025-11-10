#include "bits/stdc++.h"

#define endl '\n'

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int a,b,c; cin >> a >> b >> c;
    b -= a;

    if(b%c == 0) cout << "S\n";
    else cout << "N\n";

    return 0;
}