#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n; vector<ll> best;

ll cover(ll casa){
    if (casa > n) return 0;
    if (casa == n) return 1;
    if (best[casa] != 0) return best[casa];
    ll sum = 0;
    for(int i = 1; i < 7; i++) sum += cover(casa+i);
    best[casa] = mod(sum,MOD);
    return sum;
}

int main(){
    fastio;
    cin >> n;

    best.resize(n,0);

    ll ans = cover(0); cout << mod(ans,MOD);

    return 0;
}