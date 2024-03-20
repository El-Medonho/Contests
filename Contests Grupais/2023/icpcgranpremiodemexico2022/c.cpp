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

    ll n,m; cin >> n >> m;

    vll arr(n);
    for(ll &x: arr) cin >> x;

    sort(arr.begin(), arr.end());
    reverse(arr.rbegin(), arr.rend());

    vll fxsum(n); ll sum = 0;
    for(ll i = 0; i < n; i++){
        sum += arr[i];
        fxsum[i] = sum;
    }
    ll ogsum = sum;

    reverse(arr.rbegin(), arr.rend());

    ll menor = *arr.rbegin();
    while(m--){
        ll k; cin >> k;
        
        if(k < menor){
            menor = k;
            ll ind = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
            ind = (n-1)-ind;
            sum = ogsum;
            sum -= fxsum[ind]; sum += (ind+1)*k;

            cout << sum << endl;
        }else{
            cout << sum << endl;
        }
    }

    return 0;
}