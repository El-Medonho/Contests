// ░░░░░░░░░░░░▄▄▄█████████▄▄▄░░░░░░░░░░░░
// ░░░░░░░░▄▄██████▀▀▀▀▀▀▀██████▄▄░░░░░░░░
// ░░░░░░▄████▀▀░░░░░░░░░░░░░▀▀████▄░░░░░░
// ░░░░▄███▀░░░░░░░░░░░░░░░░░░░░▀▀███▄░░░░
// ░░▄███▀░░░░░░░░░░░░░░░░░░░░░░░░░████░░░
// ░▄███▀░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░▀███░░
// ░███░░░░░░█████▄░░░░░░░░░░░░░░░░░░▀███░
// ███▀░░░░░░██████░░░░░░░░░░░░░░░░░░░███▄
// ███░░░░░░░█████▀░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░████▄░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░▀███▄░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░░░█████▄░░░▄███▄▄░░░░░░▄███
// ▀███░░░░░░░░░░░░▀████████████░░░░░░███░
// ░███▄░░░░░░░░░░░░░▀▀████████▀░░░░░███▀░
// ░░████░░░░░░░░░░░░░░░░░▀▀▀░░░░░░▄███▀░░
// ░░███▀░░░░░░░░░░░░░░░░░░░░░░░░░▄███▀░░░
// ░▄███░░░░▄▄░░░░░░░░░░░░░░░░░▄████▀░░░░░
// ▄███▄▄███████▄▄▄░░░░░░░▄▄▄█████▀░░░░░░░
// ███████▀▀▀▀▀███████████████▀▀░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ▒█░░▒█ █░░█ █▀▀█ ▀▀█▀▀ █▀▀ ░█▀▀█ █▀▀█ █▀▀█░
// ▒█▒█▒█ █▀▀█ █▄▄█ ░░█░░ ▀▀█ ▒█▄▄█ █░░█ █░░█░
// ▒█▄▀▄█ ▀░░▀ ▀░░▀ ░░▀░░ ▀▀▀ ▒█░▒█ █▀▀▀ █▀▀▀░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

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

    int n,k,e,d; cin >> n >> k >> e;
    d = n-k-e;
    vector<vector<bool>> dp(n+1, vector<bool> (n+1,0));

    dp[e][d] = 1;
    int ans = n-k;

    for(int g = 1; g <= max(e,d); g++) { 
        if(g == k) continue;
        for(int i = 0; i <= e; i++){
            for(int j = 0; i+j <= n-k-g; j++){
                
                if(i+g <= e && dp[i+g][j]) dp[i][j] = 1;
                if(j+g <= d && dp[i][j+g]) dp[i][j] = 1;
            }
        }
    }

    for(int i = 0; i <= e; i++){
        for(int j = 0; j <= d; j++){
            if(dp[i][j]) ans = min(ans,i+j);
        }
    }

    cout << ans << endl;
    

    return 0;
}