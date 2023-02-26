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

    int n; cin >> n;

    vll sums(501,0);
    for(int i = 1; i < 501; i++) sums[i] = sums[i-1]+i;
    if(sums[n]%2 == 1){cout << 0 << endl; return 0;}


    vector<vll> dp(n+1, vll ((sums[n]/2)+1, 0));

    dp[1][(sums[n]/2)-1] = 1;
    for(ll i = 2; i <= n; i++){
        for(ll j = 0; j <= (sums[n] - sums[i])/2; j++){
            ll curr = min(i+j, (sums[n]-sums[i-1]) - (i+j));
            if(curr > 0) dp[i][j] += mod(dp[i-1][curr], MOD);
            // dp[i][j] += mod(i+j, MOD);
            // if((sums[n] - sums[i]) % 2 != 0 || (sums[n] - sums[i])/2 != j) dp[i][j] += mod(dp[i-1][j], MOD);
            dp[i][j] += mod(dp[i-1][j], MOD);
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}