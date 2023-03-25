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
    vll arr(n);
    vii aba(0);

    for(ll &i: arr) cin >> i;

    int op = 2*n;
    // for(int i = 1; i < n; i++){
    //     if(arr[i]%arr[i-1] != 0) continue;
    //     else{
    //         while(op > 0){
    //             if(mod(arr[i],arr[i-1]) != 0 && (i == 1 || mod(arr[i-1],arr[i-2] != 0))) break;
    //             op--;
    //             arr[i-1]++;
    //             if(op == 0) aba[1000] = 4;
    //         }
    //     }
    // }

    for(int i = 0; i < n; i++){
        bool change = false;;
        for(int j = 1; j < n; j++){

            if(mod(arr[j], arr[j-1]) == 0) {
                if(arr[j-1] != 1) arr[j]++;
                else arr[j-1]++;
                op--;
                change = true;
                if(op < 0) aba[1000] = 4;
            }

        }
        if(!change) break;
    }

    for(int i = 0; i < n-1; i++) cout << arr[i] << esp;
    cout << arr[n-1] << endl;
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