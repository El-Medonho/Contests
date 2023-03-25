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
    ll res=1;
    while(e){
        res = mod(res,MOD);
        if(e&1) res= mod(res*b,MOD);
        b = mod(b,MOD);
        b = mod(b*b,MOD);
        e >>= 1;
    }
    return res;
}

ll expi(ll b, ll e, ll m){
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

    vll base(n), exp(n);

    for(int i = 0; i < n; i++){
        ll a,b; cin >> a >> b;
        base[i] = a;
        exp[i] = b;
    }

    ll nums = 1;
    for(int x: exp){
        nums *= (x+1);
        nums = mod(nums,MOD);
    }

    ll pa = 1;
    for(int i = 0; i < n; i++){
        // pa *= (expo(base[i], exp[i]+1) - 1) / (base[i]-1);
        ll bi = expo(base[i], exp[i]+1)-1;
        ll hh = expo(base[i]-1, MOD-2);
        bi = mod(bi * hh, MOD);
        pa = mod(bi * pa, MOD);
    }

    ll k = 1;
    for(int i = 0; i < n; i++){
        k = mod(k * expi(base[i], exp[i], ll(MOD-1)), MOD);
    }

    ll nums2 = 1;
    for(int x: exp){
        nums2 *= (x+1);
        nums2 = mod(nums,MOD);
    }

    ll pg = expo(k, nums2/2);

    cout << nums << esp << pa << esp << pg << endl;


    return 0;
}