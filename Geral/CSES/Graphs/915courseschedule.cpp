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

    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> req(n,0);
    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        req[b]++;
    }
    queue<int> qw;
    for(int i = 0; i < n; i++){
        if(req[i] == 0) qw.push(i);
    }
    vii ans(n); int curr = 0;
    while(!qw.empty()){
        int g = qw.front();
        qw.pop();
        ans[curr] = g;
        curr++;

        for(int j: graph[g]){
            req[j]--;
            if(req[j] == 0) qw.push(j);
        }
    }

    if(curr < n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i = 0; i < n-1; i++){
        cout << ans[i]+1 << esp;
    }
    cout << (*ans.rbegin())+1 << endl;

    return 0;
}