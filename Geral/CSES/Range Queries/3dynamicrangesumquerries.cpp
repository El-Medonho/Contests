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

vll bit(0);

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
    bit.resize(n+1,0); vii arr(n);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a;
        upd(i+1, a, bit);
    }

    while(q--){
        int t, a, b; cin >> t >> a >> b;
        if(t == 1){
            upd(a, b - arr[a-1], bit);
            arr[a-1] = b;
        }else{
            cout << sum(b, bit) - sum(a-1, bit) << endl;
        }
    }

    return 0;
}