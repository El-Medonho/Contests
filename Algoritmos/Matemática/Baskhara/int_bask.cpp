#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll sq(ll x){
    ll s = sqrtl(x);
    for(auto sq: vector<ll>{s-1,s,s+1}){
        if(sq*sq == x) return sq;
    }
    return -1;
}

vector<ll> int_bask(ll a, ll b, ll c){
    ll delta = (b*b)-4*a*c;

    if(delta < 0 || a == 0){
        return {};
    }

    ll s = sq(delta);

    if(s == -1) return {};

    vector<ll> ans(0);

    ll cc = -b + s;
    if(cc % (2*a) == 0) ans.push_back(cc / (2*a));

    cc = -b + s;
    if(cc % (2*a) == 0) ans.push_back(cc / (2*a));

    return ans;
}