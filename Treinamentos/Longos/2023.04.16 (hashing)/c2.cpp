#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define mod(x,v) (((x%v)+v)%v)

typedef long long ll;

int n; string str;

ll expo(ll b, ll e, ll m){
    ll res = 1;
    while(e){
        if(e&1){
            res = mod(b*res,m);
        }
        b = mod(b*b,m);
        e>>=1;
    }
    return res;
}

struct Hashing{
    int n;
    string str;
    ll m = 1e9+7;
    ll p = 31;
    ll invp = 129032259;

    vector<ll> pow, invpow, hh;

    Hashing(string s){
        str = s;
        n = str.length();

        invpow.resize(n+1,1); pow.resize(n+1,1); hh.resize(n+1,0);

        for(int i = 1; i <= n; i++){
            pow[i] = mod(pow[i-1] * p, m);
            invpow[i] = mod(invpow[i-1] * invp, m);
        }

        for(int i = 1; i <= n; i++){
            hh[i] = mod(mod(hh[i-1] * p, m) + (str[i-1] - 'a' + 1), m);
        }
    }

    ll range(int l, int r){
        ll res = 0; r++;
        res = mod(hh[r] - mod(hh[l] * pow[r-l], m), m);
        return res;
    }
};

int main(){
    fastio;

    cin >> n;

    function<bool(int)> calc;

    cin >> str;
    Hashing hashing(str);

    int g = hashing.range(1,1), gg = hashing.range(2,2);

    calc = [&](int sz){
        sz--;
        queue<int> qw;
        set<int> st;
        for(int i = sz; i < n; i++){
            if(i-2*sz-1 > -1){
                st.insert(qw.front());
                qw.pop();
            }

            int hh = hashing.range(i-sz,i);
            if(st.find(hh) != st.end()) return 1;
            qw.push(hh);
        }
        return 0;
    };

    int l = 1,r = n/2;
    int ans = 0;
    while(l <= r){
        int md = (l+r)>>1;
        bool res = calc(md);

        if(res){
            l = md+1;
            ans = max(ans, md);
        }else{
            r = md-1;
        }
    }

    cout << ans << endl;
    // cout << hashing.range(0,0) << " " << hashing.range(2,2);


    return 0;
}