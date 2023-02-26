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

    if(arr[0].f > x){cout << 0 << endl; return 0;}

    vector<vector<pii>> dp(n);  //{custo, numero de paginas}
    vector<vector<pii>> booksinhand(n);

    for(int i = n, j = 0; j < n; i--, j++){
        booksinhand[j].resize(i);
    }

    for(int i = 0; i < n; i++){
        dp[i].resize(i+2);
        for(int j = 1; j < i+2; j++){
            if(arr[i].f > x) {dp[i][j] = dp[i-1][j]; booksinhand[j][i] = dp[i-1][j];}
            if(i == 0){
                dp[0][1] = arr[0];
                booksinhand[1][0] = arr[0];
                continue;
            }
            if(j == 1){
                if(arr[i].f > x || dp[i-1][j].s > arr[i].s) {dp[i][j] = dp[i-1][j]; booksinhand[j][i] = dp[i-1][j];}
                else {dp[i][j] = arr[i]; booksinhand[j][i] = arr[i];}
                continue;
            }

            

            auto best = lower_bound(booksinhand[j-1].begin(), booksinhand[j-1].end(), make_pair(x - arr[i].f, 0));
            if(best == booksinhand[j-1].end() ||(*best).s > x - arr[i].s) best--;

            if(best == --booksinhand[j-1].begin()){
                dp[i][j] = dp[i-1][j]; booksinhand[j][i] = dp[i-1][j];
                continue;
            }

            pii curr = *best;

            if(curr.s + arr[i].s <= dp[i-1][j].s) {dp[i][j] = dp[i-1][j]; booksinhand[j][i] = dp[i-1][j];}
            else {dp[i][j] = {curr.f + arr[i].f, curr.s + arr[i].s}; booksinhand[j][i] = {curr.f + arr[i].f, curr.s + arr[i].s};}
        }
    }


    int ans = 0;
    for(int i = 1; i < dp[n-1].size(); i++){
        ans = max(ans, dp[n-1][i].f);
    }

    cout << ans << endl;

    return 0;
}