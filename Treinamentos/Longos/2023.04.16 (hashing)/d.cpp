#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

struct Hashing{
    int n;
    string str;
    ll m = 1e9+7;
    ll p = 31;
    ll invp = 129032259;

    vector<ll> pow, hh;

    Hashing(string s){
        str = s;
        n = str.length();

        pow.resize(n+1,1); hh.resize(n+1,0);

        for(int i = 1; i <= n; i++){
            pow[i] = (pow[i-1] * p)%m;
        }

        for(int i = 1; i <= n; i++){
            hh[i] = (((hh[i-1] * p)%m) + (str[i-1] - 'a' + 1))%m;
        }
    }

    ll range(int l, int r){
        ll res = 0; r++;
        res = (hh[r] - ((hh[l] * pow[r-l])%m))%m;
        return res;
    }
};


int main(){
    fastio;
    
    string s; cin >> s; int n = s.size();

    Hashing hs(s);
    // hs.build();

    reverse(s.begin(), s.end());

    Hashing invhs(s);
    // invhs.build();

    reverse(s.begin(), s.end());

    function<pair<int,int>(int)> check;

    check = [&](int sz){

        for(int i = 0; i + 2*sz < n; i++){
            if(hs.range(i, i+sz-1) == invhs.range(n-1-(i+2*sz), n-1-(i+sz+1))) return make_pair(i, i+2*sz);
        }

        for(int i = 0; i + 2*sz - 1 < n; i++){
            if(hs.range(i, i+sz-1) == invhs.range(n-(i+2*sz-1)-1, n-(i+sz)-1)) return make_pair(i, i+2*sz-1);
        }

        return make_pair(-1,-1);    
    };

    int l = 1, r = n/2;
    pair<int,int> ans = {-1,-1};

    while(l <= r){
        int md = (l+r)>>1;
        pair<int,int> curr = check(md);

        if(curr.second != -1){
            ans = curr;
            l = md+1;
        }else{
            r = md-1;
        }
    }

    for(int i = ans.first; i <= ans.second; i++){
        cout << s[i];
    }
    cout << "\n";

    return 0;
}