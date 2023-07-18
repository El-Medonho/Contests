#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define mxn (int) 1e5+5
#define mxm (int) 1e5+5
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;

ll n, k, sla;

int main(){
    fastio;
    cin >> n;

    for(ll i=1; i<=2*n; i++){
        if(i*i==k){
            sla = i;
        }
    }

    ll ans = 0;

    for(sla = 1; sla <= 2*n; sla++){
        ll x = 0;
        k = sla*sla;
        for(ll i=2*n; i>=1; i--){
            if(i == sla) continue;
            ll atual = i*i;
            
            if((abs(atual-k))%(2*n+1)==0){
                x++;
                // return 0;
            }
        }
        if(x != 1){
            cout << -1 << endl;
            // return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}