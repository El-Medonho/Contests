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
    int cup = n;
    n = min(n,m); m = max(m,cup);
    if(n == 1 && m == 1) {cout << 0 << endl; return 0;}

    int size = 1;
    for(int i = 0; i < n; i++) size *= 2;
    vector<vll> dp(m, vll(size, 0));
    for(int i = 0; i < size; i++) dp[0][i] = 1;

    vector<vii> corr(size, vii(0));
    for(int i = 0; i < size; i++){      //fzr a correlacao
        int ggg = 0;
        bool end = false;
        // for(int j = 0; j < n; j++){
        //     if((i & (1<<j)) == 0) ggg++;
        //     else if(ggg % 2 == 1) end = true;
        // }
        // if(end || ggg % 2 == 1) continue;
        
        for(int j = 0; j < size; j++){
            if((i & j) != 0) continue;

            int test = i|j;

            int gg = 0;
            for(int g = 0; g < n; g++){
            if((test & (1<<g)) == 0) gg++;
            else if(gg % 2 == 1) end = true;
            }
            if(end || gg % 2 == 1) {end  = false; continue;}
            corr[i].pb(j);
        }
    }

    for(int j = 0; j < size; j++){

        int ggg = 0;
        bool end = false;
        for(int g = 0; g < n; g++){
            if((j & (1<<g)) == 0) ggg++;
            else if(ggg % 2 == 1) end = true;
        }
        if(end || ggg % 2 == 1) continue;

        for(int k: corr[j]){
            dp[0+1][k] += dp[0][j];
            dp[0][j] = mod(dp[0][j], MOD);
        }
    }

    for(int i = 1; i < m-1; i++){
        for(int j = 0; j < size; j++){
            for(int k: corr[j]){
                dp[i+1][k] += dp[i][j];
                dp[i][j] = mod(dp[i][j], MOD);
            }
        }
    }

    cout << mod(dp[m-1][0], MOD) << endl;

    return 0;
}