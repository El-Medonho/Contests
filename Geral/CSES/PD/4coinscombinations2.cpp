#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

vector<vector<int>> best; int n; int x; vector<int> coins;

ll cover(int casa, int coin){
    if (casa > x) return 0;
    if (casa == x) return 1;
    if(best[casa][coin]!=0) return best[casa][coin];
    ll sum = 0;
    
    for(int i = coin; i < n; i++){
        sum += cover(casa+coins[i], i);
    }
    sum = mod(sum, MOD);
    best[casa][coin] = sum;
    return sum;
}
int main(){
    fastio;
    cin >> n >> x;
    coins.resize(n,0);
    best.resize(x);
    for(int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());
    for(int i = 0; i < x; i++) best[i].resize(n,0);
    cout << cover(0,0) << endl;
    return 0;
}