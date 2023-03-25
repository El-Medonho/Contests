#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<ll,ll>
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

int main(){
    fastio;

    ll n; cin >> n;
    vll arr(n);
    for(ll &i: arr) cin >> i;

    vll bit(n+1);
    vii changed(n+1,0);
    for(ll i = 0; i < n; i++) bit[i+1] = arr[i];

    ll q; cin >> q;

    int changeit = 0;
    int currx = -1;
    while(q--){
        ll op; cin >> op;
        ll x,i = 0;
        if(op == 2) {cin >> i >> x;}
        if(op == 3) {cin >> i;bit[i] = (changed[i] == changeit) ? bit[i] : currx; cout << bit[i] << endl; continue;} 
        if(op == 1) {cin >> x; currx = x; changeit++; continue;}

        if(changed[i] != changeit){
            changed[i] = changeit;
            bit[i] = currx;
        }

        bit[i] += x;

        
    }


    return 0;
}