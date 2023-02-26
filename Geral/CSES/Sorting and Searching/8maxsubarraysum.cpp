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

    vll arr(n), sum(n);
    ll sums = 0;
    ll min = 0, best = -INF;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sums += arr[i];
        sum[i] = sums;
    }

    ll record = sum[0];

    for(ll x: sum){
        if(x > best) {
            best = x;
            record = max(record, best-min);
        }
        if(x < min){
            min = x;
            best = -INFL;
        }
    }

    cout << record << endl;

    return 0;
}