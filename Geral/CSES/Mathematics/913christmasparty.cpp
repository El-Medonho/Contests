#include "bits/stdc++.h"
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

ll expo(ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1) res = mod(res*b, MOD);
        b = mod(b*b, MOD);
        e>>=1;
    }
    return res;
}

int main(){
    fastio;

    int n; cin >> n;

    vll fact(1e6+50, 1);
    for(int i = 1; i < 1e6+30; i++) fact[i] = mod(fact[i-1]*i, MOD);

    ll ans = 0, op = 1;
    for(int i = 0; i <= n; i++){
        ll h = fact[i];
        h = expo(h, MOD-2);
        
        ans += mod(h * fact[n], MOD) * op;
        ans = mod(ans, MOD);

        op *= -1;
    }

    cout << ans << endl;

    return 0;
}