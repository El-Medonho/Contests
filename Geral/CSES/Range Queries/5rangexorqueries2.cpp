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

void upd(int ind, int val, vii &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]= bit[ind] ^ val;
        ind+=ind&-ind;
    }
}
int sum(int ind, vii &bit){         //O(logn)
    int ans=0;
    while(ind){
        ans = ans ^ bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

int main(){
    fastio;

    int n,q; cin >> n >> q;
    vii bit(n+1, 0);
    for(int i = 1; i < n+1; i++) {
        int a; cin >> a;
        upd(i, a, bit);
    }

    while(q--){
        int a,b; cin >> a >> b;
        if(a == 1){
            cout << sum(b,bit) << endl;
        }
        else cout << (sum(b, bit) ^ sum(a-1, bit)) << endl;
    }

    return 0;
}