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

    int q; cin >> q;

    while(q--){
        int k,n; cin >> n >> k;  k++;
        if(n == 0 && k == 1) return 0;
        int picked = 0; ll ans = 0; int last = n+1;
        ll constr = 0;
        int savei;

        for(int i = 0;; i++){
            savei = i;
            if(picked + (last/2) >= k){
                break;
            }

            picked += last/2;
            int ind = last/2;
            last -= last/2;

            ll end = constr + (1<<(i+1)) * (ind-1);
            int adding = 0;
            if(end + (1 << (i+1)) <= n) {
                picked++; last--;
                adding = 0;
                if(picked == k) ans = end + (1 << (i+1));
            }
            else if(end + (1 << (i+1))/2 <= n){
                adding = 1;
            }
            
            constr ^= (1<<i);
            if(!adding) constr += (1 << (i+1)); 
        }
        if(ans == 0) ans = constr + ((k-picked-1) << (savei+1));
        cout << ans << endl;
    }

    return 0;
}