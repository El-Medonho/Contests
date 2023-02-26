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

vii arr(0);
vector<vll> dp(0);
int n,m; 

ll calc(int ind, int begin, int end){
    int blb = (begin == 0) ? 1 : max(1, arr[begin-1]-(ind-begin+1)), bup = (begin == 0 ? m: min(m, arr[begin-1]+(ind-begin+1)));
    int elb = (end == n-1) ? 1 : max(1, arr[end+1]-(end-ind+1)), eup = (end == n-1) ? m : min(m, arr[end+1]+(end-ind+1));
    
    int lb = max(blb, elb), up = min(bup, eup);
    
    for(int i = lb; i <= up; i++){
        if(ind == 0) {dp[ind][i] = 1; continue;}

        dp[ind][i] = dp[ind-1][i] + dp[ind-1][i+1] + dp[ind-1][i-1];
        dp[ind][i] = mod(dp[ind][i], MOD);
    }   
    
    return dp[ind][2];
    
}

int main(){
    fastio;

    cin >> n >> m;
    arr.resize(n);
    for(int &i: arr) cin >> i;

    if(n == 1){
        if(arr[0] == 0) cout << m << endl;
        else cout << 1 << endl;
        return 0;
    }


    ll ans = 1;
    dp.resize(n, vll(m+5,0));

    bool haszero = false;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0){ haszero = true;
            int beg = i, end = 0;
            for(int j = i; arr[j] == 0 && j < n; j++){
                end = j;
            }
            if(beg != 0 && end != n-1 && abs(arr[beg-1] - arr[end+1]) > end-beg+2){cout << 0 << endl; return 0;}
            for(int k = beg; k < end; k++){
                calc(k, beg, end);
            }
            calc(end, beg, end);
            ll now = 0;
            for(int i = 1; i <= m; i++) now += dp[end][i];
            ans = mod(ans*now, MOD);
            i = end;
        }
        else {
            dp[i][arr[i]] = 1;
            if(i != 0 && arr[i-1] != 0 && abs(arr[i]-arr[i-1]) > 1){cout << 0 << endl; return 0;}
        }
    }

    cout << ans << endl;


    return 0;
}