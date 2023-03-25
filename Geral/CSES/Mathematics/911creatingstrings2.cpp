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

ll expo(ll b, ll e, ll m){
    ll res = 1;
    while(e){
        if(e&1) res = mod(res*b, m);
        b = mod(b*b, m);
        e>>=1; 
    }
    return res;
}

int main(){
    fastio;

    string str; cin >> str;
    int n = str.size();

    vll facts(1e6+5, 1);

    for(int i = 1; i < 1e6 + 3; i++) facts[i] = mod(facts[i-1] * i, MOD);

    vll occur(26, 0);
    for(char c: str) occur[c-'a']++;

    ll ans = facts[n];

    ll den = 1;
    for(ll hh: occur){
        if(hh == 0) continue;
        den = mod(den * facts[hh], MOD);
    }
    den = expo(den, MOD-2, MOD);

    ans = mod(ans * den, MOD);

    cout << ans << endl;

    return 0;
}