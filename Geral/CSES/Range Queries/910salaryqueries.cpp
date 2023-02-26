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
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value)

int main(){
    fastio;

    int n,q; cin >> n >> q;
    multiordered_set ost;
    vii arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ost.insert(arr[i]);
    }

    while(q--){
        char c; cin >> c;
        if(c == '!'){
            int k,x; cin >> k >> x; k--;
            ost.erase(--ost.lower_bound(arr[k]));
            ost.insert(x);
            // for(int x: ost) cout << x << esp;
            // cout << endl;
            arr[k] = x;
        }else{
            int a,b; cin >> a >> b;
            int p = ost.order_of_key(b+1), z = ost.order_of_key(a);
            cout << p - z << endl;
        }
    }

    return 0;
}