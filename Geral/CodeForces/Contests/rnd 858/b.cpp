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

    vii arr(n);
    for(int &i: arr) cin >> i;

    set<int> res;
    sort(arr.begin(), arr.end());

    int ind = 0;

    if(arr[0] != 0) {cout << 0 << endl; return 0;}
    if(n%2 == 1 && arr[n/2+1] != 0) {cout << 0 << endl; return 0;}
    if(n%2 == 0 && arr[n/2] != 0) {cout << 0 << endl; return 0;}

    if(arr[n-1] == 0) {cout << 1 << endl; return 0;}

    for(int i = 0; i < n; i++){
        if(arr[i] != 0) {
            if(arr[i] != 1){
                cout << 1 << endl;
                return 0;
            }
            if(arr[n-1] != arr[i]){
                cout << 1 << endl;
                return 0;
            }

            cout << 2 << endl;
            return 0;
        }
    }

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