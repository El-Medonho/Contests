//MEDONHO APENAS
//https://codeforces.com/contest/597/problem/C

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

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}

ll sum(int ind, vector<ll> &bit){         //O(logn)
    ll ans=0;
    while(ind){
        ans+=bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

int main(){
    fastio;

    int n,k; cin >> n >> k;

    vector<pii> arr(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = {a,i};
    }

    sort(arr.begin(), arr.end());

    vector<vll> dp(k+1, vll(n+1,0));
    for(int i = 0; i < n+1; i++){
        dp[0][i] = 1;
    }

    vll bit(n+1,0);

    for(int i = 1; i < k+1; i++){
        fill(bit.begin(), bit.end(), 0);
        for(int j = n-1; j > -1; j--){
            int gg = arr[j].s;
            dp[i][gg] = sum(n-gg, bit);
            upd(n-gg, dp[i-1][gg], bit);
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans+=dp[k][i];

    cout << ans << endl;

    return 0;
}