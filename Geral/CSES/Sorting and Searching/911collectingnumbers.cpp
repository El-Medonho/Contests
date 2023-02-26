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
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        arr[i] = {k,i};
    }
    sort(arr.begin(), arr.end());

    int ans = 1, last = -1;

    for(pii x: arr){
        if(x.s < last) ans++;
        last = x.s;
    }

    cout << ans << endl;

    return 0;
}