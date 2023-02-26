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
    vector<vii> graph(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
    }
    vii visited(n,0);

    queue<int> qw;
    qw.push(0);

    while(!qw.empty()){
        int curr = qw.front(); qw.pop();

        for(int j: graph[curr]){
            if(visited[j] == 0) qw.push(j);
            visited[j]++;
        }
    }

    if(visited[n-1] == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vii last (n, -1);
    qw.push(0);

    while(!qw.empty()){
        int curr = qw.front(); qw.pop();

        for(int j: graph[curr]){
            visited[j]--;
            if(visited[j] == 0){
                qw.push(j);
                last[j] = curr;
            }
        }
    }

    vii ans(0);

    int curr = n-1;
    while(curr != -1){
        ans.pb(curr);
        curr = last[curr];
    }
    reverse(ans.rbegin(), ans.rend());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size()-1; i++)cout << ans[i]+1 << esp;
    cout << (*ans.rbegin())+1 << endl;

    return 0;
}