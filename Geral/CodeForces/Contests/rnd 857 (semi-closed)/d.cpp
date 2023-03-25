#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    int n; cin >> n;

    vector<pll> ai(n),bi(n);
    vector<pll> og(n);
    vii occur(n,0);
    ll ans = INFL;

    for(int i = 0; i < n; i++){
        ll a,b; cin >> a >> b;
        ai[i] = {a,i};
        bi[i] = {b,i};
        og[i] = {a,b};
    }

    

    sort(ai.begin(), ai.end(), greater<pll>());
    sort(bi.begin(), bi.end(), greater<pll>());

    int pnt1 = 0, pnt2 = 0;
    int changed = 3;

    for(;pnt1 != n && pnt2 != n;){
        pll a = ai[pnt1], b = bi[pnt2];

        if(changed == 3){
            occur[a.s]++;
            occur[b.s]++;
        }else if(changed == 2){
            occur[b.s]++;
        }else if(changed == 1){
            occur[a.s]++;
        }

        if(a.s == b.s){ 
            while(pnt1 < n-1){
                pnt1++;
                ans = min(ans, llabs(ai[pnt1].f-b.f));
                if(og[ai[pnt1].s].s > b.f) break;
            }
            while(pnt2 < n-1){
                pnt2++;
                ans = min(ans, llabs(a.f-bi[pnt2].f));
                if(og[bi[pnt2].s].f > a.f) break;
            }
            cout << ans << endl;
            return 0;
        }

        ans = min(ans, llabs(a.f-b.f));

        if(occur[a.s] == 2){
            if(og[a.s].s == b.f){
                while(pnt1 < n-1){
                    pnt1++;
                    ans = min(ans, llabs(ai[pnt1].f-b.f));
                    if(og[ai[pnt1].s].s > b.f) break;
                }
            }
            while(pnt2 < n-1){
                pnt2++;
                ans = min(ans, llabs(a.f-bi[pnt2].f));
                if(og[bi[pnt2].s].f > a.f) break;
            }
            cout << ans << endl;
            return 0;
        }

        if(occur[b.s] == 2){
            if(og[b.s].f == a.f){
                while(pnt2 < n-1){
                    pnt2++;
                    ans = min(ans, llabs(a.f-bi[pnt2].f));
                    if(og[bi[pnt2].s].f > a.f) break;
                }
            }
            while(pnt1 < n-1){
                pnt1++;
                ans = min(ans, llabs(ai[pnt1].f-b.f));
                if(og[ai[pnt1].s].s > b.f) break;
            }
            cout << ans << endl;
            return 0;
        }

        if(pnt1 != n-1 && pnt2 != n-1){
            ll k1 = llabs(ai[pnt1+1].f - bi[pnt2].f), k2 = llabs(ai[pnt1].f - bi[pnt2+1].f);
            if(k1 < k2){
                pnt1++;
                changed = 1;
                continue;
            }else{
                pnt2++; 
                changed = 2;
                continue;
            }    
        }else if(pnt1 == n-1 && pnt2 < n-1) {pnt2++; changed = 2;}
        else {pnt1++; changed = 1;}        
    }

    return 0;
}

int main(){
    fastio;

    int t = 0; cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}