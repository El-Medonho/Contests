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

    int n,k; cin >> n >> k;

    string s; cin >> s;

    vector<pii> arr(26, {0,0});

    for(char c: s){
        if(islower(c)) arr[c-'a'].f++;
        else arr[c-'A'].s++;
    }

    ll ans = 0;

    for(int i = 0; i < 26; i++){
        int low = min(arr[i].f, arr[i].s), up = max(arr[i].f, arr[i].s);
        if(k >= (up+low)/2 - low){
            ans += (up+low)/2;
            k -= (up+low)/2 - low;
        }else{
            ans+= low+k;
            k = 0;
        }
    }
    cout << ans << endl;

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