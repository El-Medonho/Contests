#include "bits/stdc++.h"

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,k,r; cin >> n >> k >> r;
    vector<int> l(n,0);

    for(int i = 0; i < k; i++){
        int p; cin >> p; p--;
        l[p] = 1;
    }

    int soma = 0,resp = 0,pos_i = 0, ultimo = 0;
    for(int i = 0; i < r; i++) {soma += l[i]; if(l[i] == 0) ultimo = i;}

    if(soma < 2) {
        if(soma == 0){
            l[r-2] = 1; l[r-1] = 1; soma = 2; resp += 2;
        }
        else{resp++; l[ultimo] = 1;soma++;}
    }

    for(int i = r; i < n; i++){
        soma -= l[pos_i];
        soma += l[i];

        if(soma < 2){resp++; l[i] = 1; soma++;}
        pos_i++;
    }

    cout << resp << '\n';

    return 0;
}