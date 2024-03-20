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
 
    vector<ll> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ori[i][j];
 
            if(i==j) continue;
 
            ori[i][j]+=v[j];
            dist[i][j] = ori[i][j];
 
        }
    }
 
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
 
    vector<pair<ll, pair<ll, ll> > > planes(m);
    for(int i=0; i<m; i++){
        cin >> planes[i].s.f >> planes[i].s.s >> planes[i].f;
    }
 
    //sort(planes.begin(), planes.end());
    
    for(int i=0; i<m; i++){
        ll tf = planes[i].f+ori[planes[i].s.f][planes[i].s.s];
 
        for(int j=0; j<m; j++){
            if(i==j) continue;
            if(tf + dist[planes[i].s.s][planes[j].s.f]<=planes[j].f){
                vec[i+1].push_back(j+1);
            }
        }
    }
 
    int resp=0;
 
    for(int i=1; i<=m; i++){
        for(int j:vec[i]){
            if(!par[j]){
                par[j]=i;
                temp[i]=1;
                resp++;
                break;
            }
        }
    }
 
    for(int i=1; i<=m; i++){
        if(temp[i]) continue;
        memset(memo, 0, sizeof(memo));
        if(dfs(i)){
            resp++;
        }
    }
    
    cout << m-resp << endl;
    return 0;
}