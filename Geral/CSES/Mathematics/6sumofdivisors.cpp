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

int main(){
    fastio;

    ll n; cin >> n;
    ll ans = 0;

    long double comp = (sqrt(double(n)));
    ll gg = int(comp);

    for(int i = 1; i <= comp; i++){
        ans += ((n/i)-(i-1)) * i;
        ans = mod(ans,MOD);
        ll a1 = (i+1), a2 = (n/i), n1 = (((n/i) - (i+1) + 1));
        a1 = mod(a1,MOD); a2 = mod(a2,MOD); n1 = mod(n1,MOD);
        ans += ll(((a1+a2)*n1)/2); 
        ans = mod(ans,MOD);
    }

    cout << mod(ans, MOD) << endl;

    return 0;
}