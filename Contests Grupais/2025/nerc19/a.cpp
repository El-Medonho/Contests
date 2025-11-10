#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int a, b, n;
    cin >> a >> b >> n;

    pair<int, int> aC = {0, a};
    pair<int, int> bC = {0, b};

    int cont = 0;

    while(aC.second < n || bC.second < n){
        if(cont&1){
            bC.first = aC.first;
            bC.second = bC.first + b;
        }else{
            aC.second = bC.second;
            aC.first = aC.second-a;
        }
        cont++;
    }

    cout << cont << endl;
    return 0;
}