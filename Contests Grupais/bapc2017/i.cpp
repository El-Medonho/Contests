#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int mxn = 1e5+5;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int a,b; cin >> a >> b;

    if(a&1 && b%2==0 && a < b){
        cout << 2 << endl;
    }else if(a%2==0){
        cout << 0 << endl;
    }else if(a&1 && b&1){
        cout << 1 << endl;
    }else cout << 0 << endl;



    return 0;
}