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

int n,m;
vector<vii> graph(0);
vll dist(0); vii visited(0);

int solve(int beg){
    for(int i = 0; i < n; i++){
        bool any = false;
        for(int j = 0; j < m; j++){
            int a = graph[j][0], b = graph[j][1], c = graph[j][2];
            if(dist[a] < INFL){
                if(dist[b] > dist[a] + c){
                    dist[b] = dist[a] + c;
                    any = true;
                    beg = b;
                    visited[b] = a;
                }
            }
        }
        if(!any){
            // cout << "NO" << endl;
            return -1;
        }
    }
    return beg;
}

int main(){
    fastio;

    cin >> n >> m; graph.resize(m);

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[i] = {a,b,c};
    }
    sort(graph.begin(), graph.end());

    dist.resize(n, INFL); dist[0] = 0;

    visited.resize(n,-1); 

    int beg = -1;

    for(int i = 0; i < n; i++){
        if(visited[i] == -1){
            dist[i] = 0;
            beg = solve(i);
            if(beg != -1) break;
        }
    }

    if(beg == -1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    for(int i = 0; i < n; i++) beg = visited[beg];

    vii ans(0);
    ans.pb(beg);
    int curr = visited[beg];
    while(curr != beg){
        ans.pb(curr);
        curr = visited[curr];
    }
    ans.pb(curr);

    reverse(ans.rbegin(), ans.rend());

    for(int x: ans) cout << x+1 << esp;
    cout << endl;

    return 0;
}