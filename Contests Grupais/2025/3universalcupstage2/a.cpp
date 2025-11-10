#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const int mxn = 1e6+5;
const int INF = 0x3f3f3f3f;

int n, m, dp[mxn];
vector<int> vec[mxn];

int solve(int x){
    if(x == n) return dp[x] = 1;
    if(dp[x]!=-1) {
        if(dp[x]>=1) return 1;
        return 0;
    }
    dp[x] = 0;
    for(int i:vec[x]){
        dp[x] += solve(i);
    }

    return dp[x];
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
    }
    for(int i=1; i<=n; i++) dp[i]=-1;
    int resp = solve(1);
    cout << resp << endl;
    return 0;
}