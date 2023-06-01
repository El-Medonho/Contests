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

#define MOD 998244353
#define mod(x,mvvm) ((x+mvvm)%mvvm)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<ll,null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

vector<ll> fact(5*1e5+30, 1);
vector<ll> dois(5*1e5+50,1);

ll expo(ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1) res = (res*b)%MOD;
        b = (b*b)%MOD;
        e>>=1;
    }
    return res;
}

ll solve(){

    ll n,k; cin >> n >> k;
    map<ll, ll> mp;

    ll st = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> qw;
    vector<ll> vis(k,0);
    vector<ll> saida(k,-1);

    while(k--){
        ll a,b; cin >> a >> b;
        qw.push({a,k});
        saida[k] = b;
    }
    ll last = 1;
    while(!qw.empty()){
        ll h = qw.top().first, ind = qw.top().second; qw.pop();
        if(!vis[ind]){
            if(h-last > 0) mp[st]+=h-last;
            // st.insert(ind);
            st = st^(dois[ind]);
            qw.push({saida[ind]+1,ind});
            vis[ind] = 1;
        }else{
            // h++;
            if(h-last > 0) mp[st]+=h-last;
            // st.erase(ind);
            st = st^(dois[ind]);
        }

        last = h;
    }
    mp[st]+=n+1-last;

    ll tt = 1;

    for(auto x: mp){
        ll h = x.second; 
        if(h&1){
            cout << 0 << endl;
            return 0;
        }
        h>>=1;
        if(h == 0) continue;
        ll ans = 1;
 
        ll div = mod(fact[h] * fact[h+1], MOD);
    
        div = expo(div, MOD-2);
    
        ans = mod(fact[2*h] * div, MOD);
        tt = (tt*ans)%MOD;
    }

    cout << tt << endl;

    return 0;
}

int main(){
    fastio;

    for(ll i = 1; i < 5*1e5; i++) fact[i] = mod(fact[i-1]*i, MOD);
    for(ll i = 1; i < 5*1e5; i++) dois[i] = mod(dois[i-1]*2, (ll) 1e16);

    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}