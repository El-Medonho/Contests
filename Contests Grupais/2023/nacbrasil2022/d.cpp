#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){

    int n; cin >> n;
    int h1,h2; cin >> h1 >> h2;

    while(n--){
        char x; cin >> x;
        if(!h2 || x == 'Y'){
            cout << "Y ";
            h2++;
            h1--;
        }else cout << "N ";
        
        cin >> x;
        if(!h1 || x == 'Y'){
            cout << "Y\n";
            h1++;
            h2--;
        }else cout << "N\n";
    }

    return 0;
}