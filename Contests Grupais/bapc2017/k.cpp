#include <bits/stdc++.h>
 
using namespace std;

#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 1e3+5;
const int mxm = 1e5+5;
const int MOD = 998244353;

int n, memo[mxn], par[mxn], par2[mxn];
vector<int> vec[mxn];

int dfs(int x){
    if(memo[x]) return 0;
    memo[x]=1;
    for(int i:vec[x]){
        int k = 0;
        if(par[i]) k = dfs(par[i]);
        if(!par[i] || k){
            par[i]=x;
            par2[x]=i;
            return ++k;
        }
    }
    return 0;
}

void kunh(){
    int resp=0;
    for(int i=1; i<=n; i++){
        memset(memo, 0, sizeof(memo));
        resp += dfs(i);
    }
    if(resp<n-1){
        cout << "impossible" << endl;
        return;
    }
    int x=1, cont=0;
    vector<int> path;
    while(cont<n){
        cont++;
        path.push_back(x);
        x = par2[x];
    }
    reverse(path.begin(), path.end());
    for(int i:path){
        cout << i-1 << es;
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char x;
            cin >> x;
            if(j==1) continue;
            if(x=='1') vec[i].push_back(j);
        }
    }
    kunh();
    return 0;
}