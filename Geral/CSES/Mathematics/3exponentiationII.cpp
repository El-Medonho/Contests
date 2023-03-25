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

ll exp(ll b, ll e, ll m){
    ll res=1;
    while(e){
        if(e&1) res*=b;
        b*=b;
        res = mod(res,m);
        b = mod(b,m);
        e >>= 1;
    }
    return res;
}

int main(){
    fastio;

    int n; cin >> n;
    while(n--){
        ll a,b,c; cin >> a >> b >> c; a = mod(a,MOD);
        ll k = exp(b,c, MOD-1);
        cout << exp(a,k, MOD) << endl;
    }

    return 0;
}