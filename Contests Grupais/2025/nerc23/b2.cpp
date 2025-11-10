#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int MM = 40000;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t; 
    while(t--){

        ll x; cin >> x;
        vector<ll> ans(0); int mx = 0;
        vector<ll> div(0);
        for(int i = 2; i <= MM; i++){
            int cnt = 0;
            ll s = x;
            if(x%i == 0) div.push_back(i);
            while(x){
                if(x%i == 0) cnt++;
                x /= i;
            }
            x = s;
            if(mx == cnt){
                ans.push_back(i);
            }
            else if(cnt > mx){
                mx = cnt; ans.clear();
                ans.push_back(i);
            }
        }


        if(x > MM){
            if(mx == 1){
                for(ll h: div){
                    ll i = x/h;
                    int cnt = 0;
                    ll s = x;
                    while(x){
                        if(x%i == 0) cnt++;
                        x /= i;
                    }
                    x = s;
                    if(mx == cnt){
                        ans.push_back(i);
                    }
                    else if(cnt > mx){
                        mx = cnt; ans.clear();
                        ans.push_back(i);
                    }
                }
                if(mx == 1) ans.push_back(x);
            } else if( mx == 2 ){
                ll hh = pow(x,  double(1)/mx)-2;
                ll cc = 2e18;
                for(int i = 5; i > -1; i--){
                    ll d = hh+i;
                    for(int j = 0; j < mx-1; j++) d *= d;
                    if(d >= x) cc = hh+i; 
                }
                for(ll h: div){
                    ll i = cc/h;
                    if(i <= MM) continue;
                    int cnt = 0;
                    ll s = x;
                    while(x){
                        if(x%i == 0) cnt++;
                        x /= i;
                    }
                    x = s;
                    if(mx == cnt){
                        ans.push_back(i);
                    }
                    else if(cnt > mx){
                        mx = cnt; 
                        ans.clear();
                        ans.push_back(i);
                    }
                }
                if(cc * cc == x) ans.push_back(cc);
            }
        }

        sort(ans.begin(), ans.end());
        ll l = -1;

        cout << mx << ' ' << ans.size() << '\n';
        for(ll i: ans) {if(i != l) cout << i << ' '; l = i;}
        cout << '\n';
    }

    return 0;
}