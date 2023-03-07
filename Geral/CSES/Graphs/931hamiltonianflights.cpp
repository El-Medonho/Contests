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

int n,m;
int sz = 1;
vector<vii> graph(0);
vector<vll> dp(0);

void dfs(int curr, int mask){
    if( (mask & (1 << (n-1))) && mask != sz-1) return;

    for(int i: graph[curr]){
        if(mask & (1<<i)) continue;
        
        int next = mask ^ (1<<i);
        
        if(dp[i][next] == -1) continue;
        if(dp[i][next] == 0) dfs(i, next);
        if(dp[i][next] == -1) continue;

        dp[curr][mask] += dp[i][next];
        dp[curr][mask] = mod(dp[curr][mask], MOD);
    }

    if(dp[curr][mask] == 0) dp[curr][mask] = -1;

    return;
}

int main(){
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        sz*=2;
    }

    dp.resize(n, vll(sz, 0));
    dp[n-1][sz-1] = 1;

    graph.resize(n);
    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
    }

    dfs(0,1);

    cout << max(dp[0][1], ll(0)) << endl;

    return 0;
}