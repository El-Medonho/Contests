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

int n;
vector<vii> graph(0);
vector<pii> dp(0);

void dfs(int curr, int last){
    int base = 0, mx = 0;
    
    for(int j: graph[curr]){
        if(j == last) continue;
        dfs(j, curr);
        mx = max(mx + dp[j].f, base + dp[j].s + 1);
        base += dp[j].f;
    }
    dp[curr] = {mx, base};
}

int main(){
    fastio;

    cin >> n;

    graph.resize(n);
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dp.resize(n, {0,0});

    dfs(0,-1);

    cout << max(dp[0].f, dp[0].s) << endl;

    return 0;
}