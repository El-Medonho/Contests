#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;
const int mxn = 2e5+5;
const int MOD = 998244353;

vector<int> vec[mxn];

int children[mxn];

ll fact[mxn], dp[mxn];

ll exp(ll b, ll e, int m = MOD){
    ll resp = 1;
    while(e){
        if (e & 1){
            resp = (resp * b)%m;
        }
        b = (b * b)%m;
        e>>=1;
    }
    return resp;
}

ll c(int a, int b){
    ll baixo = (fact[a-b] * fact[b])%MOD;
    return (fact[a] * exp(baixo, MOD-2))%MOD;
}

void dfs(int x, int p){
    if(x != 1 && (int)vec[x].size() == 1) children[x] = 1;
    dp[x] = 1;
    for(int i:vec[x]){
        if(i == p) continue;
        dfs(i, x);
        children[x]+=children[i];
        dp[x] = (dp[x] * dp[i])%MOD;
    }
    if(x != 1){
        for(int i=1; i<=children[x]; i++){
            dp[x] = (dp[x] + ((ll)i * c((int)children[x], i))%MOD)%MOD;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    fact[0]=1;
    for(int i=1; i<=n; i++){
        fact[i] = (i * fact[i-1])%MOD;
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, 0);
    cout << dp[1] << endl;
    return 0;
}