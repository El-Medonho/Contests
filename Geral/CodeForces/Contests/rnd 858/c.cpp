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
    vll arr(2*n,0);

    for(ll &i: arr) cin >> i;

    sort(arr.begin(), arr.end());

    if(n == 1) {
        cout << arr[1] - arr[0] << endl;
        return 0;
    }

    ll ans = 0;

    for(int i = 0; i < 2*n; i++) ans += abs(arr[i]);

    if(n == 2){
        ll gg = 0;
        for(int i = 0; i < 2*n; i++) gg += abs(2-arr[i]);
        ans = min(ans,gg);
    }

    if(n%2 == 0){
        ll gg = 0;
        for(int i = 0; i < 2*n-1; i++) gg += abs(-1-arr[i]);
        gg += abs(n-arr[2*n-1]);
        ans = min(ans,gg);
    }

    cout << ans << endl;

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