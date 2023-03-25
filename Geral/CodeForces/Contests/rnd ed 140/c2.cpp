#include "bits/stdc++.h"
using namespace std;

#define MOD 998244353
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
    vll dp(n+1, 0);
    vector<vii> res(n+1, vii(n+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            cin >> res[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        if(res[i][i] == 2){
            cout << 0 << endl;
            return 0;
        }
    }
        
    int last = 1;
    dp[0] = 2;
    for(int i = 1; i <= n; i++){

        for(int j = last; j <= n; j++){
            if(res[j][i] == 2) last = max(last, j+1);
        }

        for(int j = last; j <= i; j++){
            int ok = 1;

            for(int x = 1; x < j && ok; x++){
                for(int y = j; y <= i && ok; y++){
                    if(res[x][y] == 1) ok = 0;
                }
            }

            if(ok) dp[i] += dp[j-1];
            dp[i] = mod(dp[i], MOD);
        }
    }

    cout << dp[n] << endl;
    
    
    return 0;
}