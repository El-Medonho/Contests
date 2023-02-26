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

void upd(int ind, ll val, vll &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}
ll sum(int ind, vll &bit){         //O(logn)
    ll ans=0;
    while(ind){
        ans+=bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

int main(){
    fastio;

    int n,q; cin >> n >> q;
    vll bit(n+1,0);
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        upd(i, a, bit);
    }

    vll ogbit = bit;

    while(q--){
        int t; cin >> t; 
        if(t == 1){
            ll a,b,u; cin >> a >> b >> u;
            upd(a,u,bit);
            // cout << sum(4, bit) - sum(3, bit) << endl;
            if(b != n) upd(b+1, -u, bit);
        }else{
            int k; cin >> k;
            if(k == 1) cout << sum(k, bit) << endl;
            else cout << sum(k, bit) - sum(k-1, ogbit) << endl;
        }
    }

    return 0;
}