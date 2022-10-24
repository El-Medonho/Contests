#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n,x; vector<int> best; vector<int> coins; bool possible;

int cover(int casa){
    if (casa > x) return INF;
    if (casa == x) {possible = true; return 1;}
    if (best[casa] != 0) return best[casa];
    int sum = INF;
    for(int i = 0; i < n; i++) sum = min(sum,cover(casa+coins[i]));
    best[casa] = sum+1;
    if (casa == 0) return sum;
    return sum+1;
}

int main(){
    fastio;
    cin >> n >> x;
    best.resize(x,0);
    coins.resize(n,0);
    possible = false;
    for(int i = 0; i < n; i++) cin >> coins[i];
    int nb = cover(0);
    if (possible == true) cout << nb << endl;
    else cout << -1 << endl;
    return 0;
}