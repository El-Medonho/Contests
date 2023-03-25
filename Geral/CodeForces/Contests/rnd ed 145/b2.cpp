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
typedef long double ld;
typedef unsigned long long ull;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    ll n; cin >> n;
    ll ans = INFL;

    ll k = n-1;

    ll l = 1, r = 1e16;

    for(l = 0, r = 1e9; l < r; ){
        ll mid = (l+r)>>1;
        if(((8+8*mid)*(mid))/2 >= k){
            r = mid;
            continue;
        }else{
            l = mid+1;
        }
    }

    ans = l*2;

    for(l =1, r = 1e9; l<r;){
        ll mid = (l+r)>>1;

        if(((8*mid)*(mid))/2 >= n){
            r = mid;
            continue;
        }else{
            l = mid+1;
        }
    }
    
    ans = min(ans, l*2-1);

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