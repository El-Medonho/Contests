#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int x; cin >> x;
    cout << 1 << endl;

    if(x == 25){
        cout << 50 << endl;
        for(int i = 0; i < 49; i++) cout << 5 << ' ';
        cout << 5 << endl;
    } else{
        cout << 2*x+1 << endl;
        for(int i = 0; i < 2*x; i++) cout << 1 << ' ';
        cout << x << endl;
    }


    return 0;
}