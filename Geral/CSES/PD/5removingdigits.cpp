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

    int n; cin >> n;
    vii dp(n+1,INF); dp[0] = 0;
    if(n < 10) {cout << 1 << endl; return 0;}
    for(int i = 1; i < 10; i++)dp[i] = 1;
    for(int i = 10; i < n+1; i++){
        int num = i;
        while(num){
            if(num%10 != 0){
                dp[i] = min(dp[i-(num%10)]+1, dp[i]);
            }
            num/=10;
        }
    }
    cout << dp[n] << endl;

    return 0;
}