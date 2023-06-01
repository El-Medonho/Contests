//MEDONHO APENAS

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

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]= val = (val*bit[ind])/gcd(val,bit[ind]);
        ind+=ind&-ind;
    }
}
ll sum(int ind, vector<ll> &bit){         //O(logn)
    ll ans=1;
    while(ind){
        ans = (ans*bit[ind])/gcd(ans,bit[ind]);    
        ind-=ind&-ind;    
    }
    return ans;
}

int solve(){

    int n; cin >> n;
    vector<pii> arr(n);

    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        arr[i] = {a,b};
    }

    int mmc = 1, ans = 1;

    vll bit(n+1,1);

    for(int i = 0; i < n; i++) upd(i+1, arr[i].s, bit);

    int pnt1 = 0, pnt2 = n;
    for(int i = 1; i <= n; i++){
        int l = i, r = pnt2;
        while(l < r){
            int mid = (l+r+1)>>1;
            if(arr[i-1].f % ((sum(mid,bit) * gcd(sum(pnt1,bit), arr[i-1].s)/sum(pnt1,bit))/arr[i-1].s) == 0){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        pnt2 = l;
        int h = (sum(l,bit)/sum(pnt1,bit));
        if(l == i && arr[i-1].f % ((sum(l,bit) * gcd(sum(pnt1,bit), arr[i-1].s)/sum(pnt1,bit))/arr[i-1].s) != 0 || pnt2 < i){
            ans++; pnt1 = i-1; pnt2 = n; i--;
        }
    }

    cout << ans << endl;

    return 0;
}

int main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}