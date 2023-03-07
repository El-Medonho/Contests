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
vector<pll> base(0); 
vector<pii> dp(0);
vll ans(0);

pll dfs1(int curr, int last){
    
    for(int j: graph[curr]){
        if(j == last) continue;
        pll next = dfs1(j,curr);

        base[curr].s += next.s;
        base[curr].f += next.f + next.s;
    }

    return {base[curr].f, base[curr].s+1};
}

void dfs2(int curr, int last, pll next){
    base[curr].f += (next.f + next.s); base[curr].s += next.s;
    ans[curr] = base[curr].f;

    for(int j: graph[curr]){
        if(j == last) continue;
        pll send = {base[curr].f - (base[j].f + base[j].s + 1), base[curr].s - base[j].s};
        dfs2(j,curr,send);
    }

    return;
}

int main(){
    fastio;

    cin >> n;
    graph.resize(n); dp.resize(n, {0,0}); base.resize(n, {0,0}); ans.resize(n,0);

    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs1(0,-1);
    dfs2(0,-1,{0,0});

    for(ll x: ans) cout << x << esp;
    cout << endl;

    return 0;
}