#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<INT, INT>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int main(){
    fastio;

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n), sum(n,0);
        bool haszero = false;
        ll currsum = 0; 
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 0) haszero = true;
            currsum += arr[i];
            sum[i] = currsum;
        }
        if(haszero){
            ll ans = 0;
            for(ll x: arr) ans += abs(x);
            cout << ans << endl; continue;
        }

        sort(arr.begin(), arr.end());
        ll occur = 0; ll firstpos = INF, lastneg = -1;
        for(ll i = 0; i < n; i++){
            if(arr[i] < 0) { lastneg = max(i, lastneg); occur++;}
            if(arr[i] > 0) firstpos = min(i, firstpos);
        }
        ll toexclude = -1;
        if(occur%2 == 1 && occur != n && abs(arr[lastneg]) > arr[firstpos]) {toexclude = firstpos;}
        else if(occur%2 == 1){toexclude = lastneg;}
        
        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            if(i == toexclude) {ans+= abs(arr[i])*-1; continue;}
            ans += abs(arr[i]);
        }
        cout << ans << endl; continue;

    }

    return 0;
}