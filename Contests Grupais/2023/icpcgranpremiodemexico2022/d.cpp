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
typedef tree<ll,null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find


int main(){
    fastio;

    int m; cin >> m;
    multiordered_set mtset;
    vll arr(m);
    int cnt = -1;

    while(m--){
        cnt++;
        int op; cin >> op;
        if(op == 1){
            ll a; cin >> a;
            mtset.insert(a);
            arr[cnt] = a;
        }else if(op == 2){
            ll b; cin >> b; b--;
            ll h = arr[b];
            mtset.erase(--mtset.lower_bound(h));
        }else if(op == 3){
            ll b,a; cin >> b >> a; b--;
            ll h = arr[b];
            mtset.erase(--mtset.lower_bound(h));
            h += a;
            arr[b] = h;     //?
            mtset.insert(h);
        }else if(op == 4){
            ll b; cin >> b; b--;
            ll h = arr[b];
            cout << mtset.order_of_key(h) << endl;
        }
    }

    return 0;
}