#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using tlll = tuple<ll,ll,ll>;

tlll pos_egcd(ll a, ll b) {
    if(b == 0) {
        return {a, 1, 0};
    }else {
        auto [gcd, x, y] = pos_egcd(b, a%b);
        return {gcd, y, x-(a/b)*y};
    }
}

template <ll p, ll m>
class Hash {
    int n;
    vector<ll> h;
    inline static vector<ll> pPow = {1};
    inline static vector<ll> invPow = {1};
    inline static ll invMod = get<1>(pos_egcd(p, m));

    Hash(const string& s) : n{ints.size()}, h(s.size()+1, 0) {
        while(pPow.size() < n) pPow.push_back(pPow.back()*p);
        while(invPow.size() < n) invPow.push_back(invPow.back()*invMod);
        
        for(int i = 0; i < n; i++) {
            h[i+1] = h[i] + (s[i] - 'a' + 1) * pPow[i];
        }
    }
    
    ll substr(int l, int r) {
        return (h[r+1] - h[l]) * invPow[l];
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}