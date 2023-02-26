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

    ll n,a,b; cin >> n >> a >> b;
    vll arr(n);
    ll sum = 0;
    for(ll &x: arr) {cin >> x; sum += x; x = sum;}

    multiset<ll> range;
    range.insert(0);
    // for(ll i = 0; i < b-a-1; i++) {range.insert(arr[i]);}
    
    ll best = -INFL;

    for(ll pnt1 = -1-(b-a), pnt2 = -1, pnt3 = a-1; pnt3 < n; pnt3++, pnt2++, pnt1++){
        if(pnt2 != -1)range.insert(arr[pnt2]);

        best = max(best, arr[pnt3] - *range.begin());   

        
        if(pnt1 == -1) range.erase(range.lower_bound(0));
        else if(pnt1 < -1) continue;
        else range.erase(range.lower_bound(arr[pnt1]));
    }   

    cout << best << endl;

    return 0;
}