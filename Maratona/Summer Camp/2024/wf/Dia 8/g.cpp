#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<int> arr(n);

    for(int &i: arr) cin >> i;

    bool ok = true;

    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            if(ok) ok = false;
            else {
                cout << "Lie\n";
                return 0;
            }
        }
    }

    if(arr[0] < arr[n-1] && ok == false){
        cout << "Lie\n";
        return 0;
    }

    cout << "Phew\n";


    return 0;
}