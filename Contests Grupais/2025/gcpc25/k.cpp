#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,l,r; cin >> n >> l >> r;
    int dl, dr;

    if(l == 1 && r == 1){
        cout << "no\n";
        return 0;
    }

    if(l == 1){
        dl = n; dr = n-1;
        r--;
    }
    else {
        dl = n-1; dr = n;
        l--;
    }

    int ind = 1;
    vector<int> ans(n, 0);
    int i = 0;
    for(; i < n && l > 1 && ind < n-1; i++, l--){
        ans[i] = ind++;
    }
    if(i >= n || (ind == n-1 && l != 1)){
        cout << "no\n";
        return 0;
    }
    ans[i] = dl;

    i = n-1;
    for(; ans[i] == 0 && i > -1 && r > 1 && ind < n-1; i--, r-- ){
        ans[i] = ind++;
    }

    if(i < 0 || ans[i] != 0 || (ind == n-1 && r != 1)){
        cout << "no\n";
        return 0;
    }
    ans[i] = dr;

    for(int i = 0; i < n; i++){
        if(ans[i] == 0) ans[i] = ind++;
    }

    cout << "yes\n";
    for(int i: ans) cout << i << ' ';
    cout << endl;

    return 0;
}