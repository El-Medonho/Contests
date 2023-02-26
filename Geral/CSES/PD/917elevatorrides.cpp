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

int n, x;

pll calc(pll a, pll b){
    int rides = a.f+b.f;
    int weight = a.s+b.s;
    if(weight > x){
        rides++;
        weight = min(a.s,b.s);
    }
    return make_pair(rides, weight);
}

int main(){
    fastio;

    cin >> n >> x;
    vll arr(n);
    for(ll &i: arr) cin >> i;
    sort(arr.begin(), arr.end());
    int size = 1;
    set<int> potencias; potencias.insert(1);
    for(int i = 0; i < n; i++) {size*=2; potencias.insert(size);}
    vector<pll> dp(size, make_pair(INFL,INFL));
    dp[0] = {0,0};

    for(int i = 1; i < size; i++){
        auto jj = potencias.find(i); 
        if(jj != potencias.end()){
            int ggg = 0;
            while(i != (1<<ggg)) ggg++;
            dp[i] = {0, arr[ggg]};
            continue;
        }
        for(int j = 0; j < n; j++){
            int curr = (i&(1<<j));
            dp[i] = min(dp[i], calc(dp[i ^ curr], dp[curr]));
        }
    }

    cout << dp[size-1].f+1 << endl;

    return 0;
}