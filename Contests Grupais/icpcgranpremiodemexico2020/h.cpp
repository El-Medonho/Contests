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

vll fact(1e6+50,1), invfact(1e6+50,0);

void file(string name){
    freopen((name+".txt").c_str(), "r", stdin);
    freopen((name+"_out.txt").c_str(), "w", stdout);
}

ll expo(ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1) res = mod(res*b,MOD);
        b = mod(b*b,MOD);
        e>>=1;
    }
    return res;
}

int main(){
    fastio;

    // file("pen");

    for(int i = 1; i < 1e6+30; i++) fact[i] = mod(fact[i-1]*i,MOD);

    for(int i = 0; i < 1e6+30; i++) invfact[i] = expo(fact[i],MOD-2);

    int t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;

        ll ans = fact[2*n-1];

        ll den = mod(invfact[n] * invfact[n-1],MOD);

        ans = mod(ans * den,MOD);

        cout << ans << endl;
    }    

    return 0;
}