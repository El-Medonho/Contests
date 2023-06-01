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
    int p=31; //se tiver maiúscula, 53 pode ser uma boa opção
    int m=1e9+7;
    ll inv_p=expo(p,m-2,m);
    vector<ll> p_pow, inv_pow, h;
    string s;
    
    Hashing(string s) : s(s){
        n=s.size();
        p_pow.resize(n+1);
        inv_pow.resize(n+1);
        h.resize(n+1);
    }

    void build(){
        p_pow[0]=1;
        inv_pow[0]=1;
        for(int i=1; i<n; i++){
            p_pow[i]=(p_pow[i-1]*p)%m;
            inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
        }
        h[0] = 0;
        for(int i=1; i<=n; i++){
            h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
        }
    }
    ll range(int l, int r){ //index em 0, mesmo h sendo em 1
        return (mod(h[r+1]-h[l], m)*inv_pow[l])%m;
    }
};

int main(){
    fastio;

    cin >> n;

    function<bool(int)> calc;

    cin >> str;
    Hashing hashing(str);
    hashing.build();

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
    cout << hashing.range(0,1);


    return 0;
}