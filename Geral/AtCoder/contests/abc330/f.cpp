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

    int n,k; cin >> n >> k;
    set<int> xs,ys;
    map<int,int> mpx, mpy;

    
    pair<int,int> lx = {0,0}, ly = {0,0}, rx = {0,0}, ry = {0,0};
    
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        // a--; b--;
        xs.insert(a); mpx[a]++;
        ys.insert(b); mpy[b]++;
    }

    int gh = *xs.begin();
    lx = {0, gh};
    gh = *xs.rbegin();
    rx = {0, gh};
    gh = *ys.rbegin();
    ry = {0, gh};
    gh = *ys.begin();
    ly = {0, gh};

    // xs.erase(xs.begin());
    // if(!xs.empty()) xs.erase(*xs.rbegin());
    // ys.erase(ys.begin());
    // if(!ys.empty()) ys.erase(*ys.rbegin());

    int ans = 0;

    while(rx.second - lx.second > ry.second - ly.second && k){
        if(xs.empty()) break;
        if( mpx[(*xs.begin())] + lx.first <=  mpx[(*xs.rbegin())] + rx.first){
            gh = (*xs.begin());

            bool ok = true;
            if( abs(rx.second - gh) < ry.second - ly.second ){
                gh = rx.second - (ry.second - ly.second);
                ok = false;
            }
            else xs.erase(gh);

            if( k - lx.first*abs(gh - lx.second) <= 0){
                gh = lx.second + k / lx.first;
                ans = abs(rx.second - gh);
                k = 0;
                lx.first = gh;
                break;
            }
            else{
                k -= lx.first*abs(gh - lx.second);
                lx.first = gh;
                if(ok) lx.second += mpx[gh];
                else break;
            }
        }

        else{
            gh = (*xs.rbegin());

            bool ok = true;
            if( abs(lx.second - gh) < ry.second - ly.second ){
                gh = lx.second + (ry.second - ly.second);
                ok = false;
            }
            else xs.erase(gh);

            if( k - rx.first*abs(gh - rx.second) <= 0){
                gh = rx.second - k / rx.first;
                ans = abs(lx.second - gh);
                k = 0;
                rx.first = gh;
                break;
            }
            else{
                k -= rx.first*abs(gh - rx.second);
                rx.first = gh;
                if(ok) rx.second += mpx[gh];
                else break;
            }
        }
    }


    while(rx.second - lx.second < ry.second - ly.second && k){
        if(ys.empty()) break;
        if( mpy[(*ys.begin())] + ly.first <=  mpy[(*ys.rbegin())] + ry.first){
            gh = (*ys.begin());

            bool ok = true;
            if( abs(ry.second - gh) < rx.second - lx.second ){
                gh = ry.second - (rx.second - lx.second);
                ok = false;
            }
            else ys.erase(gh);

            if( k - ly.first*abs(gh - ly.second) <= 0){
                gh = ly.second + k / ly.first;
                ans = abs(ry.second - gh);
                k = 0;
                ly.first = gh;
                break;
            }
            else{
                k -= ly.first*abs(gh - ly.second);
                ly.first = gh;
                if(ok) ly.second += mpy[gh];
                else break;
            }
        }

        else{
            gh = (*ys.rbegin());

            bool ok = true;
            if( abs(ly.second - gh) < rx.second - lx.second ){
                gh = ly.second + (rx.second - lx.second);
                ok = false;
            }
            else ys.erase(gh);

            if( k - ry.first*abs(gh - ry.second) <= 0){
                gh = ry.second - k / ry.first;
                ans = abs(ly.second - gh);
                k = 0;
                ry.first = gh;
                break;
            }
            else{
                k -= ry.first*abs(gh - ry.second);
                ry.first = gh;
                if(ok) ry.second += mpy[gh];
                else break;
            }
        }
    }

    ans = max(rx.second - lx.second, ry.second - ly.second);

    cout << ans << endl;
    

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}