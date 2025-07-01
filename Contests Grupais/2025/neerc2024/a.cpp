#include "bits/stdc++.h"
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int l, h;
    cin >> l >> h;
    if(l&1){
        cout << h << endl;
    }else{
        cout << (h/2)*2 << endl;
    }
 
 
    return 0;
}