#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
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

    int a,b; cin >> a >> b;
    int big = max(a,b), low = min(a,b);

    ll ans = 0;
    while(big % low != 0){
        ans += big/low;

        int cup = low;
        low = big%low;
        big = cup;
    }

    ans += (big/low)-1;

    cout << ans << endl;

    return 0;
}