#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'
const int mxn = 3e3 + 5;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, ma[mxn][mxn];
ll dp[mxn][mxn][2][3];

ll sol(int i, int j, int foi, int last){
    if(i == n || j == m) return 0;
    if(i<0 || j<0) return -INFL;

    ll &ans = dp[i][j][foi][last];
    if(ans!=-1) return ans;
    
    ll dir = -INFL, bai = -INFL, lef = -INFL;

    if(last == 2) dir = sol(i, j+1,  foi, 0) + ma[i][j] - ma[i][j+1];
    else dir = sol(i, j+1, foi, 0) + ma[i][j];
    bai = sol(i+1, j, foi, 1) + ma[i][j];

    if(!foi){
        if(last == 0 && j>0){
            lef = sol(i, j-1, 1, 2) + ma[i][j] - ma[i][j-1];
        }else{
            lef = sol(i, j-1, 1, 2) + ma[i][j];
        }
    }

    return ans = max({dir, bai, lef});
}

signed solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ma[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<2; k++){
                for(int z = 0; z<3; z++){
                    dp[i][j][k][z]=-1;
                }
            }
        }
    }
    cout << sol(0, 0, 0, 0) << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}