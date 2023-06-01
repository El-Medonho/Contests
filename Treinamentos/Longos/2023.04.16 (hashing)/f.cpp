#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

struct Hashing
{
    ll n;
    ll p = 31;
    ll m = 1e9+7;
    string str;
    vector<ll> pow, hh;

    Hashing(string s){
        str = s;
        n = s.size();
        pow.resize(n+1,1); hh.resize(n+1,0);

        for(int i = 1; i <= n; i++) pow[i] = (pow[i-1] * p)%m;

        for(int i = 1; i <= n; i++) hh[i] = ((hh[i-1] * p) % m + (str[i-1] - 'a' + 1)) % m;
    }

    ll range(int l, int r){
        r++;
        return ((hh[r] - (hh[l] * pow[r-l]) % m) + m) % m;
    }
};


int main(){
    fastio;

    string str; cin >> str;
    int n = str.size();

    vector<vector<ll>> rel(n, vector<ll> (n,0));
    vector<ll> ans(n,0);

    Hashing h1(str);
    reverse(str.begin(), str.end());
    Hashing invh1(str);
    reverse(str.begin(), str.end());

    for(int i = 0; i < n; i++) rel[i][i] = 1;
    ans[0] += n;

    for(int i = 1; i <= n/2; i++){
        for(int j = 0; j + 2*i - 1 < n; j++){
            if(h1.range(j, j+i-1) == invh1.range(n-1-(j+2*i-1) , n-1-(j+i))){
                ll deg = rel[j][j+i-1] + 1;
                rel[j][j+2*i-1] = deg;
                ans[deg-1]++;
            }
        }

        for(int j = 0; j + 2*i < n; j++){
            if(h1.range(j, j+i-1) == invh1.range(n-1-(j+2*i) , n-1-(j+i+1))){
                ll deg = rel[j][j+i-1] + 1;
                rel[j][j+2*i] = deg;
                ans[deg-1]++;
            }
        }
    }

    ll sum = 0;
    for(int i = n-1; i > -1; i--){
        ll dif = sum;
        sum += ans[i];
        ans[i] += dif;
    }

    for(ll i: ans) cout << i << " ";
    cout << "\n";

    return 0;
}