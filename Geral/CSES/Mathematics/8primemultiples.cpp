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

    ll n; cin >> n; int k; cin >> k;
    vll arr(k);

    for(ll &i: arr) cin >> i;

    sort(arr.begin(), arr.end());

    ll ans = 0;

    int sz = 1;
    int hjk = k;

    while(hjk){
        hjk--;
        sz<<=1;
    }

    for(int i = 1; i < sz; i++){
        int op = 0;
        ll guy = n;
        for(int j = 0; j < k; j++){
            if(i & (1<<j)) {
                op++;
                guy /= arr[j];
            }
        }
        if(op%2 == 0) ans -= guy;
        else ans += guy;
    }

    cout << ans << endl;

    return 0;
}