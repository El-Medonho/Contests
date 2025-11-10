#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int mod = 10;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> arr(n, vector<int>(n)), ans(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            arr[i][j] = s[j]-'0';
        }
    }

    vector<vector<int>> oarr = arr;

    for(int i = n-1; i > -1; i--){
        for(int j = i+1; j < n; j++){
            arr[i][j] %= 10;
            if(!arr[i][j]) continue;
            ans[i][j] = 1;
            for(int k = j+1; k < n; k++) arr[i][k] -= oarr[j][k];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}