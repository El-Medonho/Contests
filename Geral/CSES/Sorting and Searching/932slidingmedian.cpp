#include "bits/stdc++.h"
#include <queue>
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
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value)

int main(){
    fastio;

    int n,k; cin >> n >> k;
    int rate;

    if(k%2 == 0) rate = (k/2)-1;
    else rate  = k/2;
    
    vii arr(n);
    for(int &x: arr) cin >> x;

    multiordered_set currnums;
    
    int pnt1 = 0, pnt2 = k;

    vii ans(n-k+1,0); int ind = 0;
    for(int i = 0; i <= k-1; i++) currnums.insert(arr[i]);
    ans[ind] = *currnums.find_by_order(rate); ind++;

    while(pnt2 != n){
        // cout << *currnums.upper_bound(arr[pnt1]) << endl;
        currnums.erase(currnums.upper_bound(arr[pnt1]));
        pnt1++;

        currnums.insert(arr[pnt2]);
        ans[ind] = *currnums.find_by_order(rate); ind++;

        pnt2++;
    }

    for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << esp;
    cout << ans[ans.size()-1] << endl;

    

    return 0;
}