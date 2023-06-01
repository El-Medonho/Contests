//MEDONHO APENAS

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
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int fnd(vii &a, int n){
    int best = -1;
    for(int i = 0; i < n; i++){
        best = max(best, a[i]);
    }
    return best;
}

int solve(){

    int n; cin >> n;

    vii a(n),b(n);

    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;

    if(fnd(a,n) == a[n-1] && fnd(b,n) == b[n-1]){
        cout << "yes" << endl;
        return 0;
    }

    if(fnd(a,n) != a[n-1] && fnd(b,n) != b[n-1]){
        cout << "no" << endl;
        return 0;
    }

    if(fnd(a,n) != a[n-1]) swap(a,b);

    swap(a[n-1],b[n-1]);
    if(fnd(a,n) == a[n-1] && fnd(b,n) == b[n-1]){
        cout << "yes" << endl;
        return 0;
    }
    swap(a[n-1],b[n-1]);

    for(int i = 0; i < n; i++){
        if(b[i] > b[n-1]) swap(b[i],a[i]);
    }

    if(fnd(a,n) != a[n-1] || fnd(b,n) != b[n-1]){
        cout << "no" << endl;
    }else cout << "yes" << endl;

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