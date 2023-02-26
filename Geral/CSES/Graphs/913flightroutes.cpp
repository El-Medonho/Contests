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
 
    int n,m,k; cin >> n >> m >> k;
    vector<vector<pii>> graph(n);
 
    while(m--){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].pb(make_pair(c,b));
    }
    for(int i = 0; i < n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
 
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,0});
    vii visited(n,0);

    int ogk = k;
 
    while(!pq.empty() && k > 0){
        pll curr = pq.top();
        if(curr.s == n-1){
            cout << curr.f << esp;
            k--;
            //continue
        }
        pq.pop();
        if(visited[curr.s] == ogk) continue;
        visited[curr.s]++;
        for(pii j: graph[curr.s]){
            pq.push(make_pair(curr.f+j.f, j.s));
        }
    }
 
 
    return 0;
}