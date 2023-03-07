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
    
    pii in,out;
    int a,b; 
    cin >> a >> b; in = {a-1,b-1};
    cin >> a >> b; out = {a-1,b-1};

    vector<vii> grid(n, vii(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int h; cin >> h;
            grid[i][j] = h;
        }
    }

    int fst = grid[in.f][in.s]-1, snd = grid[out.f][out.s]-1;
    int best = 40;
    for(int i = 0; i < 1024; i++){
        if(!(i & (1<<fst)) || !(i & (1<<snd))) continue;
        
        queue<pii> g;
        vector<vii> visited(n, vii(m,0));

        g.push(in);

        while(!g.empty()){
            pii curr = g.front(); g.pop();
            if(curr == out){
                int cnt = 0;
                for(int j = 0; j < 10; j++){
                    if(i & (1<<j)) cnt++;
                }
                
                best = min(best, cnt);
                break;
            }

            int p = curr.f, q = curr.s;
            if(p != 0 && !visited[p-1][q] && (i & (1 << (grid[p-1][q]-1) ))) {
                g.push(make_pair(p-1,q)); visited[p-1][q] = 1;
            }
            if(p != n-1 && !visited[p+1][q] && (i & (1 << (grid[p+1][q]-1) ))) {
                g.push(make_pair(p+1,q)); visited[p+1][q] = 1;
            }
            if(q != 0 && !visited[p][q-1] && (i & (1 << (grid[p][q-1]-1) ))) {
                g.push(make_pair(p,q-1)); visited[p][q-1] = 1;
            }
            if(q != m-1 && !visited[p][q+1] && (i & (1 << (grid[p][q+1]-1) ))) {
                g.push(make_pair(p,q+1)); visited[p][q+1] = 1;
            } 
        }
    }

    cout << best << endl;

    return 0;
}