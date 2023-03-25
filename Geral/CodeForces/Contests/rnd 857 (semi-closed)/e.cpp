#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){


    int n; cin >> n;

    vector<vll> album(n);
    vector<ll> dp(200005, 0);

    vector<pll> pq;
    for(int i = 0; i < n; i++){
        int gg; cin >> gg;
        vector<ll> curr(0);
        ll max = 0;

        for(int j = 0; j < gg; j++){
            ll a; cin >> a;
            if(a > max){
                max = a;
                curr.pb(a);
            }
        }

        pq.pb({max,i});

        album[i] = curr;
    }

    ll ans = 0;

    sort(pq.begin(), pq.end());
    ll hh = 0;

    int tocons = 1;
    for(int i = (*pq.begin()).f; i <= (*pq.rbegin()).f && hh < pq.size(); i++){
        tocons = i;
        dp[i] = dp[i-1];
        pll curr = pq[hh];
        ll maxi = curr.f, ind = curr.s;

        if(maxi > i) continue;

        while(hh < pq.size()){
            curr = pq[hh]; 
            maxi = curr.f, ind = curr.s;

            if(maxi > i) break;
            hh++;

            for(ll j = 0; j < album[ind].size(); j++){
                ll f = album[ind][j]-1;
                ll h = dp[f];
                ll p = (album[ind].size() - j);

                dp[i] = max(dp[i], h  + p);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}

int main(){
    fastio;

    int t = 0; cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}