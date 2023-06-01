    #include "bits/stdc++.h"

    using namespace std;

    #define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

    int solve(){

        long long n,k; cin >> n >> k;

        if(k == 1){
            cout << "yes" << endl;
            return 0;
        }

        if((n&1) && n < k){
            cout << "no" << endl;
            return 0;
        }

        if(!(k&1) && (n&1)){
            cout << "no" << endl;
            return 0;
        }

        cout << "yes" << endl;

        return 0;
    }

    int main(){
        fastio;

        int t; cin >> t;
        while(t--){
            solve();
        }

        return 0;
    }