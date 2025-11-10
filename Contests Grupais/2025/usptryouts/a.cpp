#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int mxn = 2e5+5;

int n, v[mxn];
pair<int, int> dp[mxn];
vector<int> vec[mxn];

pair<int, int> solve(int i){
    if(i>n){
        return {0, 0};
    }
    auto &ans = dp[i];
    if(ans.first !=-1 && ans.second != -1) return ans;
    pair<int, int> pega = {-1, INF};
    
    auto it = upper_bound(vec[v[i]].begin(), vec[v[i]].end(), i);
    if(it != vec[v[i]].end()){
        auto agr = solve(*it + 1);
        pega.first = 1 + agr.first;
        pega.second = agr.second + *it - i;
    }
    auto nao = solve(i+1);

    if(pega.first > nao.first || (pega.first == nao.first && pega.second < nao.second)){
        return ans = pega;
    }
    return ans = nao;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    n*=2;

    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        v[i] = x;
        vec[x].push_back(i);
    }

    for(int i=1; i<=n; i++) dp[i] = {-1, -1};

    auto resp = solve(1);

    cout << resp.first << ' ' << resp.second << endl;
    return 0;
}