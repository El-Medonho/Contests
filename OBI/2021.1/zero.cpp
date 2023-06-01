
#include "bits/stdc++.h"

using namespace std;

int main(){
    
    int n; cin >> n;
    vector<int> arr(0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0){
            arr.pop_back();
        }else{
            arr.push_back(x);
        }
    }

    int soma = 0;
    for(int i: arr) soma += i;

    cout << soma << '\n';

    return 0;
}