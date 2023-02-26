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
    vector<vii> dp(n);
    for(int i = 0; i < n; i++) dp[i].resize(n,0);
    // for(int i = 0; i < n; i++) {dp[0][i] = 1; dp[i][0] = 1;}

    vector<string> campo(n);
    for(int i = 0; i < n; i++) cin >> campo[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) if(campo[i][j] == '*') dp[i][j] = -1;
    } 
    
    if(dp[0][0] == -1){cout << 0 << endl; return 0;}
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] != -1){
                if(i != 0 && dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
                if(j != 0 && dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
                dp[i][j] = mod(dp[i][j], MOD);
            }
        }
    }

    cout << max(0,dp[n-1][n-1]) << endl;


    return 0;
}