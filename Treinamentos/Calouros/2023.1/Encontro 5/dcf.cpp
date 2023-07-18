#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int solve(){

    int n; cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());   //O(nlogn)

    function<bool(int)> check;

    check = [&](int ans){

        long long atual = -1e12;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if( abs(arr[i] - atual) > ans ) {
                atual = arr[i] + ans; 
                cnt++;
            }
        }

        return (cnt <= 3);

        // mesma coisa
        if(cnt <= 3) return true;
        else return false;

    };

    int l = 0, r = 1e9+20;

    int resposta = 1e9+50;

    while(l <= r){
        int meio = (l+r)/2;

        bool isPossible = check(meio);

        if(isPossible){
            // resposta = min(resposta, meio);
            resposta = meio;  // mesma coisa do de cima
            r = meio - 1;
        }else{
            l = meio+1;
        }
    }

    cout << resposta << '\n';

    return 0;
}

signed main(){
    fastio;

    int t; cin >> t;

    while(t > 0){
        t--;
        solve();
    }

    return 0;
}