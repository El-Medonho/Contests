#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
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

    int a,b;
    cin >> a >> b;

    vector<vll> dp(501, vll(501,INFL));

    for(int i = 1; i < 501; i++){
        for(int j = i; j < 501; j++){
            if(j == i){dp[i][j] = 0; continue;}
            for(int k = 1; k < j; k++){
                int big = max(i, j-k), low = min(i, j-k), bigg = max(i,k), loww = min(i,k);
                dp[i][j] = min(dp[i][j], 1 + dp[low][big] + dp[loww][bigg]);
            }
            for(int k = 1; k < i; k++){
                int big = max(j, i-k), low = min(j, i-k), bigg = max(j,k), loww = min(j,k);
                dp[i][j] = min(dp[i][j], 1 + dp[low][big] + dp[loww][bigg]);
            }
        }
    }

    cout << dp[min(a,b)][max(a,b)] << endl;

    return 0;
}