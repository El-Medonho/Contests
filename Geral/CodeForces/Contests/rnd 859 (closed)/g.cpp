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

    vll arr(n), sum(n,0);
    ll sun = 0;
    for(ll &i: arr) {cin >> i;}

    sort(arr.begin(), arr.end());

    if(arr[0] != 1) {cout << "no" << endl; return 0;}

    for(int i = 0; i < n; i++) {
        sun += arr[i];
        sum[i] = sun;
    }

    for(int i = n-1; i > 0; i--){
        ll curr = arr[i];

        int pnt1 = 0, pnt2 = lower_bound(sum.begin(), sum.end(),curr) - sum.begin();
        ll ter = sum[pnt2];

        while(pnt2 < i){
            if(ter == curr) break;
            if(ter > curr) {
                ter -= arr[pnt1];
                pnt1++;
            }else{
                pnt2++; 
                if(pnt2 >= i){
                    cout << "no" << endl;
                    return 0;
                }
                ter += arr[pnt2];
            }
        }

        if(pnt2 >= i){
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

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