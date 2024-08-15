#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n,k; cin >> n >> k;

    vector<vector<int>> freq(k, vector<int>(2, 0));

    for(int i = 0; i < n; i++){
        int x; cin >> x; x%=2;

        freq[i%k][x]++;
    } 

    vector<int> seq(k, 0);
    int sum = 0;

    int ans = 0;

    for(int i = 0; i < k; i++){
        if(freq[i][1] > freq[i][0]){
            seq[i] = 1;
            sum^=1;
            ans += freq[i][0];
        }
        else{
            ans += freq[i][1];
        }
    }

    if(sum == 0){
        cout << ans << endl;
        return 0;
    }

    int cans = 1e9;

    for(int i = 0; i < k; i++){
        int cc = ans;
        if(freq[i][1] > freq[i][0]){
            cc -= freq[i][0];
            cc += freq[i][1];
        }
        else{
            cc -= freq[i][1];
            cc += freq[i][0];
        }

        cans = min(cans, cc);
    }

    cout << cans << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}