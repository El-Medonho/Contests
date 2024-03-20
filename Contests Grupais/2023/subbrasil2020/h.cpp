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
#define pii pair<long long,long long>
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
typedef tree<long long,null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_setd;
typedef tree<long long,null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value)
using namespace std;

vll arr;
ordered_set arrc;
ordered_setd arrd;
long long limit; long long n;
vector<vll> pascal;

ll calc(long long b, long long lvl){
    ll half = b/2;
    ll first = *arrd.lower_bound(half);
    ll k = (n-1) - arrd.order_of_key(first); 
    if(limit-lvl < 0) return 0;
    // cout << k+1 << endl;
    ll val = pascal[k+1][limit-lvl];
    // for(long long i = 0; i <= limit-lvl; i++) {
    //     val += pascal[k+1][i];
    //     // cout << pascal[k+1][i] << esp;
    // }
    // cout << endl;
    // cout << val << endl;
    if(arrc.upper_bound(half) == arrc.end() || *arrc.upper_bound(half) > b) return val;
    return val + calc(b - *arrc.upper_bound(half), lvl+1);
}

int main(){

    cin >> n >> limit;
    arr.resize(n);
    pascal.resize(51);
    for(long long i = 0; i < 51; i++) pascal[i].resize(51,0);

    pascal[0][0] = 1;
    for(long long i = 1; i <=50; i++){
        pascal[i][0] = pascal[i][i] = 1;
        for(long long j=1; j<i; j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

    for(ll &i: arr) {cin >> i; arrd.insert(i); arrc.insert(i);}
    long long a,b;
    cin >> a >> b;
    
    ll ans2 = calc(b,0), ans1 = calc(a-1,0);
    cout << ans2-ans1 << endl;

}