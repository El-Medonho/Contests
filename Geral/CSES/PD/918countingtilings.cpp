#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

int main(){
    fastio;

    int n,m; cin >> n >> m;
    vector<vector<vll>> dp(m, vector<vll> (4,0));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ll rt = (j == 0) ? 0: dp[i][j-1][3];
            ll dn = (i == 0) ? 0: dp[i-1][j][0];
            ll base = (j != 0) ? dp[i][j-1][3] + 

            if(i != m-1){
                dp[i+1][j] += rt+dn+1;
                dp[i+1][j] = mod(dp[i+1][j], MOD);    
            }
            if(j != n-1){
                dp[i][j+1] += rt+dn+1;
                dp[i][j+1] = mod(dp[i][j+1], MOD);
            }
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        ans += dp[m-1][i];
        ans = mod(ans,MOD);
    }

    cout << dp[m-1][n-1] << endl;

    return 0;
}