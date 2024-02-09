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

signed solve(){

    ll a,b; cin >> a >> b;
    ll x[2][2]; cin >> x[0][0] >> x[0][1] >> x[1][0] >> x[1][1];

    ll ans = 0;

    if(x[0][0] + a == x[1][0] + b && x[0][1] + b == x[1][1] + a) ans++;
    if(x[0][0] + a == x[1][0] + b && x[0][1] + b == x[1][1] - a) ans++;
    if(x[0][0] + a == x[1][0] + b && x[0][1] - b == x[1][1] + a) ans++;
    if(x[0][0] + a == x[1][0] + b && x[0][1] - b == x[1][1] - a) ans++;
    if(x[0][0] + a == x[1][0] - b && x[0][1] + b == x[1][1] + a) ans++;
    if(x[0][0] + a == x[1][0] - b && x[0][1] + b == x[1][1] - a) ans++;
    if(x[0][0] + a == x[1][0] - b && x[0][1] - b == x[1][1] + a) ans++;
    if(x[0][0] + a == x[1][0] - b && x[0][1] - b == x[1][1] - a) ans++;
    
    if(x[0][0] - a == x[1][0] + b && x[0][1] + b == x[1][1] + a) ans++;
    if(x[0][0] - a == x[1][0] + b && x[0][1] + b == x[1][1] - a) ans++;
    if(x[0][0] - a == x[1][0] + b && x[0][1] - b == x[1][1] + a) ans++;
    if(x[0][0] - a == x[1][0] + b && x[0][1] - b == x[1][1] - a) ans++;
    if(x[0][0] - a == x[1][0] - b && x[0][1] + b == x[1][1] + a) ans++;
    if(x[0][0] - a == x[1][0] - b && x[0][1] + b == x[1][1] - a) ans++;
    if(x[0][0] - a == x[1][0] - b && x[0][1] - b == x[1][1] + a) ans++;
    if(x[0][0] - a == x[1][0] - b && x[0][1] - b == x[1][1] - a) ans++;



    if(x[0][0] + b == x[1][0] + b && x[0][1] + a == x[1][1] + a) ans++;
    if(x[0][0] + b == x[1][0] + b && x[0][1] + a == x[1][1] - a) ans++;
    if(x[0][0] + b == x[1][0] + b && x[0][1] - a == x[1][1] + a) ans++;
    if(x[0][0] + b == x[1][0] + b && x[0][1] - a == x[1][1] - a) ans++;
    if(x[0][0] + b == x[1][0] - b && x[0][1] + a == x[1][1] + a) ans++;
    if(x[0][0] + b == x[1][0] - b && x[0][1] + a == x[1][1] - a) ans++;
    if(x[0][0] + b == x[1][0] - b && x[0][1] - a == x[1][1] + a) ans++;
    if(x[0][0] + b == x[1][0] - b && x[0][1] - a == x[1][1] - a) ans++;
    
    if(x[0][0] - b == x[1][0] + b && x[0][1] + a == x[1][1] + a) ans++;
    if(x[0][0] - b == x[1][0] + b && x[0][1] + a == x[1][1] - a) ans++;
    if(x[0][0] - b == x[1][0] + b && x[0][1] - a == x[1][1] + a) ans++;
    if(x[0][0] - b == x[1][0] + b && x[0][1] - a == x[1][1] - a) ans++;
    if(x[0][0] - b == x[1][0] - b && x[0][1] + a == x[1][1] + a) ans++;
    if(x[0][0] - b == x[1][0] - b && x[0][1] + a == x[1][1] - a) ans++;
    if(x[0][0] - b == x[1][0] - b && x[0][1] - a == x[1][1] + a) ans++;
    if(x[0][0] - b == x[1][0] - b && x[0][1] - a == x[1][1] - a) ans++;



    if(x[0][0] + b == x[1][0] + a && x[0][1] + a == x[1][1] + b) ans++;
    if(x[0][0] + b == x[1][0] + a && x[0][1] + a == x[1][1] - b) ans++;
    if(x[0][0] + b == x[1][0] + a && x[0][1] - a == x[1][1] + b) ans++;
    if(x[0][0] + b == x[1][0] + a && x[0][1] - a == x[1][1] - b) ans++;
    if(x[0][0] + b == x[1][0] - a && x[0][1] + a == x[1][1] + b) ans++;
    if(x[0][0] + b == x[1][0] - a && x[0][1] + a == x[1][1] - b) ans++;
    if(x[0][0] + b == x[1][0] - a && x[0][1] - a == x[1][1] + b) ans++;
    if(x[0][0] + b == x[1][0] - a && x[0][1] - a == x[1][1] - b) ans++;
    
    if(x[0][0] - b == x[1][0] + a && x[0][1] + a == x[1][1] + b) ans++;
    if(x[0][0] - b == x[1][0] + a && x[0][1] + a == x[1][1] - b) ans++;
    if(x[0][0] - b == x[1][0] + a && x[0][1] - a == x[1][1] + b) ans++;
    if(x[0][0] - b == x[1][0] + a && x[0][1] - a == x[1][1] - b) ans++;
    if(x[0][0] - b == x[1][0] - a && x[0][1] + a == x[1][1] + b) ans++;
    if(x[0][0] - b == x[1][0] - a && x[0][1] + a == x[1][1] - b) ans++;
    if(x[0][0] - b == x[1][0] - a && x[0][1] - a == x[1][1] + b) ans++;
    if(x[0][0] - b == x[1][0] - a && x[0][1] - a == x[1][1] - b) ans++;



    if(x[0][0] + a == x[1][0] + a && x[0][1] + b == x[1][1] + b) ans++;
    if(x[0][0] + a == x[1][0] + a && x[0][1] + b == x[1][1] - b) ans++;
    if(x[0][0] + a == x[1][0] + a && x[0][1] - b == x[1][1] + b) ans++;
    if(x[0][0] + a == x[1][0] + a && x[0][1] - b == x[1][1] - b) ans++;
    if(x[0][0] + a == x[1][0] - a && x[0][1] + b == x[1][1] + b) ans++;
    if(x[0][0] + a == x[1][0] - a && x[0][1] + b == x[1][1] - b) ans++;
    if(x[0][0] + a == x[1][0] - a && x[0][1] - b == x[1][1] + b) ans++;
    if(x[0][0] + a == x[1][0] - a && x[0][1] - b == x[1][1] - b) ans++;
    
    if(x[0][0] - a == x[1][0] + a && x[0][1] + b == x[1][1] + b) ans++;
    if(x[0][0] - a == x[1][0] + a && x[0][1] + b == x[1][1] - b) ans++;
    if(x[0][0] - a == x[1][0] + a && x[0][1] - b == x[1][1] + b) ans++;
    if(x[0][0] - a == x[1][0] + a && x[0][1] - b == x[1][1] - b) ans++;
    if(x[0][0] - a == x[1][0] - a && x[0][1] + b == x[1][1] + b) ans++;
    if(x[0][0] - a == x[1][0] - a && x[0][1] + b == x[1][1] - b) ans++;
    if(x[0][0] - a == x[1][0] - a && x[0][1] - b == x[1][1] + b) ans++;
    if(x[0][0] - a == x[1][0] - a && x[0][1] - b == x[1][1] - b) ans++;

    if(a==b) ans/=4;

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