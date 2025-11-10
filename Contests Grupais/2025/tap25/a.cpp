#include "bits/stdc++.h"

#define endl '\n'

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string ss;
    cin >> ss;

    int cont = 0;

    for(char i:ss){
        if(i == 'T' && cont == 0) cont++;
        if(i == 'A' && cont == 1) cont++;
        if(i == 'P' && cont == 2) cont++; 
    }

    if(cont == 3){
        cout << 'S' << endl;
    }else{
        cout << 'N' << endl;
    }

    return 0;
}