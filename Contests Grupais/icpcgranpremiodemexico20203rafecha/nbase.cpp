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

int main(){
    fastio;

    int d,b,m; cin >> d >> b >> m;
    
    vii arr(m);
    for(int &i: arr) cin >> i;
    sort(arr.begin(), arr.end());

    vector<vii> dp(m, vii(d+1, 1e8));


    int f = 0;
    int ans = 1e8;

    int l,r;
    for(l = 1, r = d; l <= r;){
        dp.resize(0); dp.resize(m, vii(d+1, 1e8));

        int mid = (l+r)>>1;
        f = mid;

        for(int i = 0; i <= f; i++){
            int pos = arr[0];
            dp[0][i] = abs(i-pos);
        }

        for(int i = 1; i < m; i++){
            for(int j = 0; j <= d; j++){
                int lb = max(0,j-f);
                int pos = arr[i];
                for(int k = lb; k <= j; k++){
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(pos-j));
                }
            }
        }

        int best = 1e8;
        for(int i = d; i >= d-f; i--){
            best = min(best, dp[m-1][i]);
        }

        if(best <= b) {
            ans = min(ans, f);
        }

        // if(l > r)  dp[100000][10000] = 1;
        if(l == r) break;

        if(best <= b) {
            ans = min(ans, f);
            r = mid;
        }else{
            l = mid+1;
        } 
    }

    // if(ans == 1e8) dp[100000][10000] = 1;
    cout << l << endl;

    return 0;
}