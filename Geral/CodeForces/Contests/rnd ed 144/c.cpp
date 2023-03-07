#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
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
    int l,r; cin >> l >> r;

    ll cnt = 1, term = 1, ggg = l;
    while(ggg <= r){
        cnt++;
        term *= 2;
        ggg*=2;
    }

    term/=2;
    cout << --cnt << esp;

    ll a = r/term;

    ll tem = (term/2)*3;
    ll b = (r/tem);

    ll ans = 0;

    ans += mod((b-l) * (cnt-1), MOD);

    ans += a-l;

    // for(int i = l; i*term <= r; i++){
    //     ans++;
    //     ll tem = (term/2)*i;
        
    //     if(tem * 3 <= r) ans += cnt-1; 
    //     ans = mod(ans, MOD);
    // }

    cout << mod(ans,MOD) << endl;

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