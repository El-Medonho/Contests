// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄


#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int wpp = 998244353;

ll expo(ll b, ll e, ll m){
    ll ans = 1;
    while(e){
        if(e&1)ans=(ans*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return ans;
}

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    ind++;
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}
ll sum(int ind, vector<ll> &bit){         //O(logn)
    ind++;
    ll ans=0;
    while(ind){
        ans+=bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

signed solve(){

    ll n,m; cin >> n >> m;
    vector<int> arr(n), pot(m);
    for(int &i: arr) cin >> i;
    for(int &i: pot) cin >> i;

    vector<ll> bit(2*n+5, 0);

    ll ans = 0;
    ordered_set st;

    for(int i: pot){
        st.insert(i);
        ans += st.size()-st.order_of_key(i)-1;
        ans %= wpp;
    }

    ans *= n;
    ans %= wpp;

    ll resp = 0;

    for(int ii = n-1; ii > -1; ii--){
        ll cc = arr[ii];
        int last = 2*n-1;

        for(ll i = min(m-1, 30LL); i > -1; i--){
            ll xn = cc * (1LL<<i);
            if(xn > 2*n-1) continue;

            last = min(2LL*n-1, (xn<<1)-1);

            ll qtt = sum(last, bit) - sum(xn-1, bit);

            if(last > 2*n || xn-1 > 2*n-1){
                bit[200000000] = 5;
            }

            ll soma = ((m-i)*max((m-i-1LL),0LL));  //pode ser que seja m-1
            soma %= wpp;
            soma *= expo(2, wpp-2, wpp);
            soma %= wpp;


            soma *= qtt;
            soma %= wpp;

            resp += soma;
            resp %= wpp;

            // last = xn-1;
        }

        for(ll i = 1; i < 30; i++){
            ll xn = cc / (1LL<<i);
            if(cc % (1LL<<i) != 0) xn++;

            // if(xn < 1) xn = 1;

            last = cc / (1LL<<(i-1));
            if(cc % (1LL<<(i-1)) == 0) last--;

            if(last < 1) break; 

            ll qtt = sum(last, bit) - sum(xn-1, bit);

            if(last > 2*n || xn-1 > 2*n-1){
                bit[20000000] = 5;
            }

            qtt = max(qtt, 0LL);

            ll soma = ((m+i)*max(m-i+1,0LL));
            soma %= wpp;
            soma *= expo(2, wpp-2, wpp);
            soma %= wpp;
            ll soma2 = min(i-1LL, m)*m;
            soma2 %= wpp;

            soma += soma2; soma %= wpp;

            soma *= qtt;
            soma %= wpp;

            resp += soma;
            resp %= wpp;

            last = xn-1;
            // if(last < 1) break;
        }

        upd(cc, 1, bit);
        if(cc > 2*n-1){
            bit[500000000] = 8;
        }
    }

    ans = (ans+resp)%wpp;
    cout << ans << endl;

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}