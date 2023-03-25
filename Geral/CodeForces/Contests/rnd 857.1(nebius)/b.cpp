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

    int n,k,d,w; cin >> n >> k >> d >> w;
    
    vii arr(n);
    for(int &i: arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans++;
        int curr = arr[i];
        int j = i;
        int toskip = i;
        for(j = i+1; j < n && j < i+k; j++){
            int gg = arr[j];
            if(gg > curr + w + d){
                toskip = j-1;
                break;
            }
            toskip = j;
        }
        i = toskip;
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