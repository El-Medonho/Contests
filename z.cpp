#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;

int main(){
    fastio;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N,D1,D2,M; cin >> M >> D1 >> N;
    ll n = N, d1 = D1, d2 = D2, m = M;
    d2 = m-d1;
    multiset<ll> taxis;
 
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        taxis.insert(x);
    }
 
    auto base = lower_bound(taxis.begin(),taxis.end(),(m+d1));
    int resp = 0;
    if(base != taxis.end()) cout << 1 << '\n';
    else{
        auto ver = lower_bound(taxis.begin(),taxis.end(),d2);
        ll h = *ver;
        h -= d2;
        h/=2;
        if(ver == taxis.end() || taxis.size() == 1) {cout << 0 << '\n'; return 0;}
        else{
            resp++;
            taxis.erase(ver);
 
            while(!(taxis.empty())){
                auto f = taxis.end(); f--;
                ll hh = *f;

                if(d1 <= h){
                    cout << resp << '\n';
                    return 0;
                }
                
                hh -= d1;
                if(hh < 0){
                    cout << 0 << '\n';
                    return 0;
                }
                d1 -= hh;
                resp++;
        
                if(d1 <= h){
                    cout << resp << '\n';
                    return 0;
                }
                taxis.erase(f);
            }
            cout << 0 << '\n';
        }
    }
 
    return 0;
}