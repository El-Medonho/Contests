#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mxn = 1e2+5;
const int INF = 0x3f3f3f3f;

int n, x, v[mxn], dp[mxn][10005];

int solve(int i, int din){
    if(din<0) return -INF;
    if(i>n) return 0;

    int &ans = dp[i][din];
    if(ans!=-1) return ans;

    string agr = to_string(din);
    sort(agr.begin(), agr.end());

    ans = 0;
    
    do{
        int num = stoi(agr);
        ans = max({ans, 1 + solve(i+1, num - v[i]), solve(i+1, num)});
    }while(next_permutation(agr.begin(), agr.end()));

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> x;

    for(int i=1; i<=n; i++) cin >> v[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(1, x) << endl;

    return 0;
}