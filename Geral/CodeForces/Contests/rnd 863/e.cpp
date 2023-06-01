// ░░░░░░░░░░░░▄▄▄█████████▄▄▄░░░░░░░░░░░░
// ░░░░░░░░▄▄██████▀▀▀▀▀▀▀██████▄▄░░░░░░░░
// ░░░░░░▄████▀▀░░░░░░░░░░░░░▀▀████▄░░░░░░
// ░░░░▄███▀░░░░░░░░░░░░░░░░░░░░▀▀███▄░░░░
// ░░▄███▀░░░░░░░░░░░░░░░░░░░░░░░░░████░░░
// ░▄███▀░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░▀███░░
// ░███░░░░░░█████▄░░░░░░░░░░░░░░░░░░▀███░
// ███▀░░░░░░██████░░░░░░░░░░░░░░░░░░░███▄
// ███░░░░░░░█████▀░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░████▄░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░▀███▄░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░░░█████▄░░░▄███▄▄░░░░░░▄███
// ▀███░░░░░░░░░░░░▀████████████░░░░░░███░
// ░███▄░░░░░░░░░░░░░▀▀████████▀░░░░░███▀░
// ░░████░░░░░░░░░░░░░░░░░▀▀▀░░░░░░▄███▀░░
// ░░███▀░░░░░░░░░░░░░░░░░░░░░░░░░▄███▀░░░
// ░▄███░░░░▄▄░░░░░░░░░░░░░░░░░▄████▀░░░░░
// ▄███▄▄███████▄▄▄░░░░░░░▄▄▄█████▀░░░░░░░
// ███████▀▀▀▀▀███████████████▀▀░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ▒█░░▒█ █░░█ █▀▀█ ▀▀█▀▀ █▀▀ ░█▀▀█ █▀▀█ █▀▀█░
// ▒█▒█▒█ █▀▀█ █▄▄█ ░░█░░ ▀▀█ ▒█▄▄█ █░░█ █░░█░
// ▒█▄▀▄█ ▀░░▀ ▀░░▀ ░░▀░░ ▀▀▀ ▒█░▒█ █▀▀▀ █▀▀▀░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░


#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

vll arr(1);

int solve(){

    ll k; cin >> k;

    function<ll(ll)> calc;
    calc = [](ll kk){

        ll d = 1, dig = 1;

        while(d <= kk){
            d*= 10;
            dig++;
        }
        d/=10; dig--;

        ll ans = 0;
        bool passs = true;
        while(--dig){
            if(kk/d == 4){
                ans += arr[dig-1] * (kk/d); ans--;
                passs = false;
                break;
            }
            ans += arr[dig-1] * ((kk/d >= 4) ? (kk/d-1) : (kk/d));
            kk%=d;
            d/=10;
        }
        if(passs) ans += (kk >= 4) ? kk-1 : kk;

        return ans;

    };

    function<void(ll)> getans;

    getans = [](ll kk){
        ll d = 1, dig = 1;

        while(d <= kk){
            d*= 10;
            dig++;
        }
        d/=10; dig--;

        bool ak = true;
        while(d){
            if(!ak){
                cout << 9;
            }
            else if(kk/d == 4){
                ak = false;
                cout << 3;
            }
            else cout << kk/d;

            kk %= d;
            d/=10;
        }
        cout << endl;

        return 0;

    };

    ll l = 1,r = 1e13;
    while(l < r){
        ll mid = (l+r)>>1l;

        ll jj = calc(mid);
        if(jj == k){
            getans(mid);
            return 0;
        }
        if(jj < k){
            l = mid+1;
        }else{
            r = mid;
        }
    }

    getans(l);

    return 0;
}

int main(){
    fastio;

    arr[0] = 9;
    for(int i = 1; i < 19; i++){
        arr.pb(arr[i-1]*9);
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}