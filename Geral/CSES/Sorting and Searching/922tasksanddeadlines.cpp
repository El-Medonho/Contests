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

    int n; cin >> n;
    vector<pii> arr(n);

    for(pii &x: arr) {int a,b; cin >> a >> b; x = {a,b};}

    sort(arr.begin(), arr.end());
    
    ll time = 0, ans = 0;

    for(pii x: arr){
        time += x.f;
        ans += x.s-time;
    }

    cout << ans << endl;

    return 0;
}