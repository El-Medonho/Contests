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

// vii ans(0);

    vector<pll> pd(1e6+1,{0,0});

int solve(){
    fastio;

    int n; cin >> n;


    cout << mod(pd[n].f+pd[n].s, MOD) << endl;

    return 0;
}

int main(){
    fastio;

    pd[1] = {1,1};

    for(int i = 2; i <= 1e6; i++){
        pii curr = {0,0};
        curr.f = mod(2*pd[i-1].f + pd[i-1].s, MOD);
        curr.s = mod(pd[i-1].f + 4*pd[i-1].s, MOD);
        pd[i] = curr;
    }


    int t; cin >> t;
    // ans.resize(t);
    while(t--) solve();

    return 0;
}