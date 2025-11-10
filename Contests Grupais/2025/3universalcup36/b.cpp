#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> memo(n+1);
        for(int i=0; i<m; i++){
            int x;
            cin >> x;

            if(!memo[x]){
                int resp = 0;
                for(int j = x; j<=n; j+=x){
                    resp += (!memo[j]);
                    memo[j] = 1;
                }
                cout << resp << endl;
            } else {
                cout << "the lights are already on!" << endl;
            }
        }

    }

    return 0;
}