#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

struct Hashing{
    int n;
    int p=31; //se tiver maiúscula, 53 pode ser uma boa opção
    int m=1e9+7;
    ll inv_p=129032259;
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
        for(int i=1; i<=n; i++){
            h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
        }
    }
    ll range(int l, int r){ //index em 0, mesmo h sendo em 1
        return ((h[r+1]-h[l]+m)%m*inv_pow[l])%m;
    }
};


int main(){
    fastio;
    
    string s; cin >> s; int n = s.size();

    Hashing hs(s);
    hs.build();

    reverse(s.begin(), s.end());

    Hashing invhs(s);
    invhs.build();

    reverse(s.begin(), s.end());

    int l = 1, r = n/2;
    pair<int,int> ans = {-2,-1}, ans2 = {-2,-1};
    pair<int,int> curr;

    bool check1u = false, check2u = false;

    while(l <= r){
        int md = (l+r)>>1;

        bool check1 = false, check2 = false, check = false;

        for(int i = 0; i + 2*md < n; i++){
            if(check1u) break;
            if(hs.range(i, i+md-1) == invhs.range(n-1-(i+2*md), n-1-(i+md+1))) {
                check1 = true;
                curr = make_pair(i, i+2*md);
                break;
            }
        }

        for(int i = 0; i + 2*md - 1 < n; i++){
            // if(check) break;
            if(check2u) break;
            if(hs.range(i, i+md-1) == invhs.range(n-(i+2*md-1)-1, n-(i+md)-1)){
                check2 = true;
                curr = make_pair(i, i+2*md-1);
                break;
            }
        }

        if(check1 || check2){
            if(!check1 && check2) check1u = true;
            if(check1 && !check2) check2u = true;
            ans = curr;
            l = md+1;
        }else{
            r = md-1;
        }
    }

    if(ans.first == -1){
        cout << s[0] << "\n";
    }else{
        for(int i = ans.first; i <= ans.second; i++) cout << s[i];
        cout << "\n";
    }

    return 0;
}