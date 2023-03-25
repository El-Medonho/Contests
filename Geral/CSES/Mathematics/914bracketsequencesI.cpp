//MEDONHO APENAS

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
    if(n%2 == 1){
        cout << 0 << endl; return 0;
    }

    n>>=1;

    vll dp(n+1,0); dp[0] = 1;
    ll sum = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j]*dp[i-j-1];
            dp[i] = mod(dp[i], MOD);
        }
    }

    cout << dp[n] << endl;

    return 0;
}