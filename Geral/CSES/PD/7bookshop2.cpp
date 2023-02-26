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

    int n,x; cin >> n >> x;
    vector<pii> arr(n);
    vii a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] = {a[i], b[i]};
    }

    sort(arr.begin(), arr.end());

    if(x < arr[0].f) {cout << 0 << endl; return 0;}

    vector<vector<int>> dp(n);
    for(int i = 0; i < n; i++) dp[i].resize(x+1,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < x+1; j++){
            if(arr[i].f > j) {
                if(i != 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = 0;
            }
            else {
                if(i != 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i].f] + arr[i].s);
                else dp[i][j] = arr[i].s;
            }
        }
    }

    cout << dp[n-1][x] << endl;
    return 0;
}