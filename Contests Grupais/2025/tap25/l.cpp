#include "bits/stdc++.h"

#define endl '\n'

using namespace std;

typedef long long ll;

const int mxn = 1e5+5;
const int mxm = 450;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n;
ll g;

ll prefix[mxn];
ll dp[mxn][mxm];
int memo[mxn][mxm];

ll solve(int i, int qnt){
    if(i > n){
        return qnt * g;
    }

    ll &ans = dp[i][qnt];
    if(memo[i][qnt]) return ans;
    memo[i][qnt]=1;

    ll pega = -INFL;
    if(i+qnt<=n) pega = solve(i+qnt+1, qnt+1) - (prefix[i+qnt] - prefix[i-1]);
    ll nao = solve(i+1, qnt);

    return ans = max(pega, nao);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> g;
    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
    }
    cout << solve(1, 0) << endl;
    return 0;
}