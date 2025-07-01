#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mxn = 1e5+5;

int arr[mxn], dp[mxn][2];
vector<int> vec[mxn];

int solve(int x, int p, int last){
    int atual = 0;
    if(last && !arr[x]) atual++;
    if(!last && arr[x]) atual++;

    dp[x][last] = 0;

    int sumLast = 0, sumNLast = 0;

    for(int i:vec[x]){
        if(i==p) continue;
        sumLast +=solve(i, x, last);
        sumNLast += solve(i, x, !last);
    }
    dp[x][last] = max(atual + sumLast, sumNLast);
    return dp[x][last];
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    for(int i=1; i<=n; i++) cin >> arr[i];


    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    cout << max(solve(1,0,  0), solve(1, 0, 1)) << endl;


    return 0;
}