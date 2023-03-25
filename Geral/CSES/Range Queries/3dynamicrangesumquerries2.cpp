//MEDONHO APENAS

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

    int n,q; cin >> n >> q;
    
    vll arr(n);
    for(ll &i: arr) cin >> i;

    int term = int(sqrt(n));
    vll decomp((n/term)+1,0);
    for(int i = 0; i < n; i++){
        decomp[i/term] += arr[i];
    }

    while(q--){
        int op; cin >> op; op--;
        if(op){
            int a,b; cin >> a >> b; a--; b--;

            ll ans = arr[a++];
            while(a <= b){
                if(a%term == 0){
                    a = a/term;
                    break;
                }
                ans += arr[a++];
            }
            if(a >= b){
                cout << ans <<endl;
                continue;
            }
            for(; a < (b/term); a++){
                ans += decomp[a];
            }
            a *= term;
            for(; a <= b; a++){
                ans += arr[a];
            }
            cout << ans << endl;
        }else{
            ll k,x; cin >> k >> x; 
            ll diff = x - arr[--k];
            arr[k] = x;
            decomp[k/term] += diff;
        }
    }

    return 0;
}