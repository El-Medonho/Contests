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
vii vmaxdepth(0);
vii ans(0);

int dfs1(int curr, int last, int depth){
    dp[curr] = {0,0};
    int maxdepth = 0;

    for(int j: graph[curr]){
        if(j == last) continue;

        int next = dfs1(j,curr,depth+1);
        maxdepth = max(maxdepth, next);
        next-=depth;
        if(next > dp[curr].s){
            dp[curr].s = min(dp[curr].f, next);
            dp[curr].f = max(dp[curr].f, next);
        }
    }
    vmaxdepth[curr] = max(maxdepth-depth, 0);
    return max(maxdepth, depth);
}

void dfs2(int curr, int last, int depth){
    ans[curr] = max(vmaxdepth[curr], depth);

    for(int j: graph[curr]){
        if(j == last) continue;
        if(vmaxdepth[j] == dp[curr].f-1){
            if(dp[curr].s == dp[curr].f) dfs2(j,curr, max(depth, dp[curr].f)+1);
            else dfs2(j,curr, max(depth, dp[curr].s)+1);
        }else{
            dfs2(j,curr, max(depth, dp[curr].f)+1);
        }
    }

    return;
}

int main(){
    fastio;

    cin >> n;
    graph.resize(n); dp.resize(n); vmaxdepth.resize(n,0); ans.resize(n,0);

    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs1(0,-1,0);

    dfs2(0,-1,0);

    for(int x: ans) cout << x << esp;
    cout << endl;

    return 0;
}