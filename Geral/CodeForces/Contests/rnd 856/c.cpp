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
    vii arr(n);

    for(int &i: arr) cin >> i;

    ll curr = 1; int sz = 0;
    vll ans(n,1);
    int pnt = 0;
    vii aba(0);

    for(int i = 0; i < n; i++){
        while(arr[pnt] < (i-pnt+1) && pnt < i){
            curr*=sz;
            curr/=arr[pnt];
            sz--;
            pnt++;
        }
        curr *= arr[i];
        sz++;
        // while(sz > curr){
        //     sz--;
        //     curr*=sz;
        //     curr/=arr[pnt];
        //     pnt++;
        // }
        curr/=sz;
        if(curr == 0) {aba[1000] = 4;}
        while(arr[pnt] < (i-pnt+1) && pnt < i){
            curr*=sz;
            curr/=arr[pnt];
            sz--;
            pnt++;
        }

        ans[i] = sz;
        continue;
    }

    for(int i = 0; i < n-1; i++) cout << ans[i] << esp;
    cout << ans[n-1] << endl;

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