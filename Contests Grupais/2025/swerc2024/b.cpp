#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,k; cin >> n >> k;

    vector<ll> arr(n);

    for(ll &i: arr) cin >> i;

    vector<ll> og = arr; arr.push_back(0);

    vector<vector<pair<ll,ll>>> dp(n+1, vector<pair<ll,ll>>(k+1, make_pair((ll) 1e18, 0LL)));

    dp[0][0] = {0,0};

    sort(arr.begin(), arr.end());

    for(int i = 1; i <= n; i++){
        ll cc = arr[i], sum = 0;

        for(int j = i; j > 0; j--){
            sum += (cc-arr[j]) * (cc-arr[j]);
            for(int h = k; h > 0; h--){
                dp[i][h] = min(dp[i][h], make_pair(dp[j-1][h-1].first + sum, (ll) j-1));
            }
        }
    }

    pair<ll,ll> cans = {3e18, -1};

    for(int i = 1; i <= k; i++){
        cans = min(cans, make_pair(dp[n][i].first, (ll) i));
    }

    set<ll> st;

    int x = n, ind = cans.second;

    while(x > 0){
        st.insert(arr[x]);
        x = dp[x][ind].second;
        ind--;
    }

    for(int i: og){
        cout << (*st.lower_bound(i)) << ' ';
    }
    cout << '\n';

    return 0;
}