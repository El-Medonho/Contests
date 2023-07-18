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

int n,t;
vii machine(0);

bool calc(ll time){
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        curr += time/machine[i];
        if(curr >= t) return true;
    }
    return curr >= t;
}


int main(){
    fastio;

    cin >> n >> t;
    machine.resize(n);
    for(int i = 0; i < n; i++) cin >> machine[i];

    ll l = 0, r = 1e18;

    while(r > l){
        ll mid = (l+r)/2;
        bool pass = calc(mid);
        if(calc(mid)) r =mid;
        else l = mid+1;
    }

    if(calc((l+r)/2)) cout << (l+r)/2 << endl;
    else cout << (l+1+r)/2 << endl;

    return 0;
}