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
    vii arr(n);
    for(int &i: arr) cin >> i;

    vector<vector<pair<ll, pii>>> dp(n, vector<pair<ll,pii>> (n, make_pair(0,make_pair(0,0))));

    for(int k = 0; k < n; k++){
        for(int i = 0; i+k < n; i++){
            if(k == 0) {dp[i][i] = {arr[i], {0,0}}; continue;}
            if(k == 1) {
                if(arr[i] > arr[i+1]) dp[i][i+k] = {arr[i], {1,0}};
                else dp[i][i+k] = {arr[i+1], {0,-1}};
                continue;
            }
            ll ind1 = dp[i+1+dp[i+1][i+k].s.f][i+k+dp[i+1][i+k].s.s].f;   // se o escolhido for o primeiro
            ll ind2 = dp[i+dp[i][i+k-1].s.f][i+k-1+dp[i][i+k-1].s.s].f;   //se o escolhido for o ultimo
            if(ind1 + arr[i] > ind2 + arr[i+k]) dp[i][i+k] = {ind1 + arr[i], {1,0}};
            else dp[i][i+k] = {ind2 + arr[i+k], {0,-1}};
        }
    }

    cout << dp[0][n-1].f << endl;

    return 0;
}