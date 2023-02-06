//try

#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define pb push_back 
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int main(){
    fastio;

    ll n;

    cin >> n;

    vector<ll> x(n),y(n);

    for(ll i = 0; i < n; i++){
        ll u,v;
        cin >> x[i] >> y[i];
    }

    set<ll> penismais;
    set<ll> penismenos;

    for(ll i = 0; i < n; i++){
        penismais.insert(abs(x[i]+y[i]));
        penismenos.insert((x[i]-y[i]));
    }

    ll val1, val2, ans;
    val1 = abs(*penismais.begin() - *penismais.rbegin());
    val2 = abs(*penismenos.begin() - *penismenos.rbegin());

    ans = max(val1, val2);
    cout << ans << endl;
    return 0;
}