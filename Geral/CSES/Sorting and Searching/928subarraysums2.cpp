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


int main(){
    fastio;

    int n, target; cin >> n >> target;
    map<ll,ordered_set> ind; set<ll> sums;
    ll ans = 0;

    ind[0].insert(-1);
    sums.insert(0);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sum += a;
        ind[sum].insert(i);
        sums.insert(sum);
    }   

    for(ll x: sums){
        if(ind.find(x-target) != ind.end()){
            for(int curr: ind[x]){
                int aa = ind[x-target].order_of_key(curr);
                ans += aa;
            }
        }
    }

    cout << ans << endl;

    return 0;
}