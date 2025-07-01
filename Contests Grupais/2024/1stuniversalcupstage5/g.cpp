#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> resp(n, vector<char>(n));
    
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            resp[i][j]='U';
        }
    }
    if(n>2){
        int k = (n-2);
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                resp[i][j]='.';
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << resp[i][j];
        }
        cout << endl;
    }

    return 0;
}