//MEDONHO APENAS

#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MOD 1000000007
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

    vector<vii> album(n);
    vector<pii> pq(n);

    set<int> nums;
    map<int,int> mp;

    {
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            int best = 0;
            while(k--){
                int a; cin >> a;
                if(a > best){
                    nums.insert(a);
                    album[i].pb(a);
                    best = a;
                }
                pq[i] = {best,i};
            }
        }
    }

    int ind = 1;
    for(int x: nums) mp[x] = ind++;
    vii dp(ind, 0);

    sort(pq.begin(), pq.end());

    int kk = 0;
    for(int i = 1; i < ind; i++){
        dp[i] = dp[i-1];

        for(; kk < n; kk++){
            if(mp[pq[kk].f] > i) break;

            int sz = album[pq[kk].s].size();
            for(int x = 0; x < sz; x++){
                int curr = album[pq[kk].s][x];
                dp[i] = max(dp[i], dp[mp[curr]-1] + sz-x);
            }
        }
    }

    cout << (*dp.rbegin()) << endl;

    return 0;
}

int main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}