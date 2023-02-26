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

    int n,target; cin >> n >> target;
    vll dp(target+1,0);
    vii coins(n);

    for(int &x: coins) cin >> x;

    sort(coins.begin(), coins.end());

    // for(int x: coins) if(coins[x] <= target) dp[x] = 1;

    for(int j: coins){
        if(j <= target) dp[j] += 1;
        for(int i = 0; i < target+1; i++){
            if(i-j <= 0) continue;
            dp[i] += dp[i-j];
            dp[i] = mod(dp[i], MOD);
        }
    }

    cout << dp[target] << endl;

    return 0;
}