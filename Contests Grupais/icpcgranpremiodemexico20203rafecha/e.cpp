#include "bits/stdc++.h"
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

int main(){
    fastio;

    ll n,b; cin >> n >> b;
    vll arr(n,0);
    vll answ(n,0);
    map<ll,vll> mp;

    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        arr[i] = a;
        mp[a].pb(i);
    }

    for(auto &x: mp){
        for(ll h: x.s){
            ll left = mod(h-1,n), right = mod(h+1,n);
            ll ans = 1;
            if(arr[left] < arr[h]) ans = max(ans, answ[left]+1);
            // if(arr[left] == arr[h]) ans = max(ans, answ[left]);
            if(arr[right] < arr[h]) ans = max(ans, answ[right]+1);
            // if(arr[right] == arr[h]) ans = max(ans, answ[right]);

            if(arr[h] == 0) ans = 0;

            answ[h] = ans;
        }
    }

    for(int i = 0; i < n-1; i++) cout << answ[i]*b << esp;
    cout << ll(ll(answ[n-1])*b) << endl;

    return 0;
}