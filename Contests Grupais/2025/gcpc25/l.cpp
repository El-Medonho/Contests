#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;

    if(t <= 360){
        cout << 0 << endl;
    }else if(t <= 390){
        cout << t - 360 << endl;
    }else if(t <= 570){
        cout << 30 << endl;
    }else if(t <= 585){
        cout << 30 + t - 570 << endl;
    }else if(t <= 645){
        cout << 45 << endl;
    } else {
        cout << 45 + t - 645 << endl;
    }

    return 0;
}