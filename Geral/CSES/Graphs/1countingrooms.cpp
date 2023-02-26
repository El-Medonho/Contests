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
    vector<string> grid(n, "");


    queue<pii> q;
    for(string &s: grid) cin >> s;
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#') continue;
            q.push({i,j});
            ans++;
            while(!q.empty()){
                int a = q.front().f, b = q.front().s;
                q.pop();
                if(grid[a][b] == '#') continue;
                grid[a][b] = '#';
                if(a != 0 && grid[a-1][b] == '.') q.push({a-1,b});
                if(a != n-1 && grid[a+1][b] == '.') q.push({a+1,b});
                if(b != 0 && grid[a][b-1] == '.') q.push({a,b-1});
                if(b != m-1 && grid[a][b+1] == '.') q.push({a,b+1});
            }
        }
    }

    cout << ans << endl;


    return 0;
}