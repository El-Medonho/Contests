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

ll n,k;
ll fact[21];

vector<int> bit(0);

void upd(int x, int val){   //O(logn)
    while(x<=n){
        bit[x]+=val;
        x+=x&-x;
    }
}
int sum(int x){         //O(logn)
    int ans=0;
    while(x){
        ans+=bit[x];    
        x-=x&-x;    
    }
    return ans;
}

ll calc(ll x){
    int u = min(k, x-k);
    ll curr = 1;
    for(ll i = x; i > x-u; i--){
        curr*=i;
    }
    return curr/fact[u];
}

int main(){
    fastio;

    cin >> n >> k;
    ll ans = 0;
    bit.resize(n+1,0);


    fact[0] = 1;
    ll curri = 1;
    for(int i = 1; i < 21; i++) {curri *= i; fact[i] = curri;}

    // ll given[400];
    // // given[0] = 1;
    // unsigned long long facts = 1;
    // for(int i = 0; i-k < 21; i++){
    //     if(i < k) {given[i] = 0; continue;}
    //     if(k > i-k){
    //     given[i] = facts/fact[i-k];
    //     facts*=(i+1);
    //     }
    // }


    for(int i = 0; i < n; i++){
        int c = 0; cin >> c;
        upd(c, 1);

        int curr = sum(c); curr--;
        if(curr < k) continue;

        ans += calc(curr);
    }

    cout << ans << endl;

    return 0;
}