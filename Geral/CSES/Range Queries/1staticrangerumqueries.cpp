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

int main(){         //com soma de prefixo
    fastio;

    int n,q; cin >> n >> q;
    vll arr(n);
    for(ll &i: arr) cin >> i;

    vll sum(n,0); ll sums = 0;
    for(int i = 0; i < n; i++){
        sums += arr[i];
        sum[i] = sums;
    }

    while(q--){
        int a,b; cin >> a >> b; a--; b--;
        if(a == 0) cout << sum[b] << endl;
        else cout << sum[b] - sum[a-1] << endl;
    }

    return 0;
}