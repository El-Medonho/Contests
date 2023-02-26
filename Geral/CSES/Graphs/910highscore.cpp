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
    vector<vii> graph(m), graphc(n, vii(0)); 

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;a--; b--; c = -c;
        graph[i] = {a,b,c};
        graphc[a].pb(b);
    }

    vll dist(n, INFL);
    dist[0] = 0;

    vii reachable(n,0);
    queue<int> q;
    q.push(0); reachable[0] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int j: graphc[curr]){
            if(!reachable[j]){
                reachable[j] = 1;
                q.push(j);
            }
        }
    }

    set<int> endreaching; endreaching.insert(0);

    for(int i = 1; i < n; i++){
        if(reachable[i]){
            q.push(i);
            vii visited(n,0);
            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int j: graphc[curr]){
                    if(!visited[j]){
                        visited[j] = 1;
                        q.push(j);
                    }
                    if(j == n-1){
                        while(!q.empty()) q.pop();
                        endreaching.insert(i);
                    }
                }
            }
        }
    }
    

    for(int i = 0; i < 2*n; i++){
        bool any = false;

        for(int j = 0; j < m; j++){
            int a = graph[j][0], b = graph[j][1], c = graph[j][2];
            if(dist[a] < INFL){
                if(dist[b] > dist[a] + c){
                    dist[b] = dist[a] + c;
                    if(endreaching.find(b) != endreaching.end()) any = true;
                }
            }
        }
        if(i >= n-1 && any){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << - dist[n-1] << endl;

    return 0;
}