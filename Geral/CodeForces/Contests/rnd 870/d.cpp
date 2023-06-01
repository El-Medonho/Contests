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

int solve(){

    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll &i : arr) cin >> i;

    stack<ll> stk, stk2;
    vector<ll> nextl(n,-1), nextll(n, -1), nextr(n,-1), nextrr(n, -1);
    for(ll i = n-1; i > -1; i--){
        while(!stk2.empty() && arr[i] >= arr[stk2.top()]){
            nextll[stk2.top()] = i;
            stk2.pop();
        }
        while(!stk.empty() && arr[i] >= arr[stk.top()]){
            nextl[stk.top()] = i;
            stk2.push(stk.top());
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()) stk.pop();
    while(!stk2.empty()) stk2.pop();

    for(ll i = 0; i < n; i++){
        while(!stk2.empty() && arr[i] >= arr[stk2.top()]){
            nextrr[stk2.top()] = i;
            stk2.pop();
        }

        while(!stk.empty() && arr[i] >= arr[stk.top()]){
            nextr[stk.top()] = i;
            stk2.push(stk.top());
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()) stk.pop();
    while(!stk2.empty()) stk2.pop();

    ll ans = 0;

    for(ll i = 0; i < n; i++){
        if(nextl[i] != -1 && nextl[nextl[i]] != -1){
            ans = max(ans, arr[i] + arr[nextl[i]] + arr[nextl[nextl[i]]] - abs(nextl[nextl[i]] - i));
        }
        if(nextr[i] != -1 && nextr[nextr[i]] != -1){
            ans = max(ans, arr[i] + arr[nextr[i]] + arr[nextr[nextr[i]]] - abs(nextr[nextr[i]] - i));
        }
        if(nextr[i] != -1 && nextl[i] != -1){
            ans = max(ans, arr[i] + arr[nextr[i]] + arr[nextl[i]] - abs(nextr[i] - nextl[i]));
        }
        if(nextll[i] != -1 && nextl[i] != -1){
            ans = max(ans, arr[i] + arr[nextll[i]] + arr[nextl[i]] - abs(nextll[i] - i));
        }
        if(nextrr[i] != -1 && nextr[i] != -1){
            ans = max(ans, arr[i] + arr[nextrr[i]] + arr[nextr[i]] - abs(nextrr[i] - i));
        }
        ll bestl = nextl[i], bestr = nextr[i];
        for(ll j = nextll[i]; j != -1 && arr[j] < arr[nextl[nextl[j]]]; j = nextll[j]){
            ans = max(ans, arr[i] + arr[bestl] + arr[j] - abs(j - i));
            bestl = (arr[j] > arr[bestl]) ? j : bestl;
            if(nextl[j] != -1) ans = max(ans, arr[i] + arr[bestl] + arr[nextl[j]] - abs(nextl[j] - i));
        }
        for(ll j = nextrr[i]; j != -1 && arr[j] < arr[nextr[nextr[j]]]; j = nextrr[j]){
            ans = max(ans, arr[i] + arr[bestr] + arr[j] - abs(j - i));
            bestr = (arr[j] > arr[bestr]) ? j : bestr;
            if(nextr[j] != -1) ans = max(ans, arr[i] + arr[bestr] + arr[nextr[j]] - abs(nextr[j] - i));
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