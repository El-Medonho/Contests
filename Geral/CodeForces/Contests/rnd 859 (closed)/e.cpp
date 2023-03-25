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
    int sun = 0;
    for(int &i:arr) {
        int h;
        cin >> h; sun += h;
        i = sun;
    }

    int l = 1, r = n, last = -1;
    while(l < r){
        int mid = (l+r)/2;

        cout << "? " << mid << esp;

        for(int i = 1; i < mid; i++) cout << i << esp; 
        cout << mid << endl; 

        cout.flush();

        int k; cin >> k;

        int sum = arr[mid-1];

        if(sum == k){
            l = mid+1;
            last = l;
        }else{
            r = mid;
        }
    }

    cout << "! " << l << endl; cout.flush();

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