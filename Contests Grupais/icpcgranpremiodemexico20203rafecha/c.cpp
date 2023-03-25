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

    int t; cin >> t;

    while(t--){
        ll n,k; cin >> n >> k;

        ll ans = 0;

        ans = ((n+2)*(n+1))/2;

        ans = mod(ans,MOD);

        ans *= (k+1);

        ans = mod(ans,MOD);

        cout << ans << endl;
    }

    return 0;
}