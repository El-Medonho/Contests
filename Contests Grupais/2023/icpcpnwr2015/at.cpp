#include "bits/stdc++.h"
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
 
const int mxn = 5e2+5;
 
int n, m, memo[mxn], par[mxn], temp[mxn], ori[mxn][mxn];
ll dist[mxn][mxn];
vector<int> vec[mxn];
 
bool dfs(int x){
    if(memo[x]) return 0;
    memo[x]=1;
    for(int i:vec[x]){
        if(!par[i] || dfs(par[i])){
            par[i]=x;
            return 1;
        }
    }
    return 0;
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
 
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
    }
 
    int resp=0;
 
    for(int i=1; i<=n; i++){
        for(int j:vec[i]){
            if(!par[j]){
                par[j]=i;
                temp[i]=1;
                resp++;
                break;
            }
        }
    }
 
    for(int i=1; i<=n; i++){
        if(temp[i]) continue;
        memset(memo, 0, sizeof(memo));
        if(dfs(i)){
            resp++;
        }
    }
    
    cout << n-resp << endl;
    return 0;
}