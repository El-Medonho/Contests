#include "bits/stdc++.h"
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

int main(){
    fastio;

    ll n,x; cin >> n >> x;
    vector<pll> arr(n);
    for(ll i = 0; i < n ; i++) {int a; cin >> a; arr[i] = {a,i};};
    sort(arr.begin(), arr.end());

    int pnt2 = 1, pnt1 = 0;

    // while(pnt2 != n && pnt1 != pnt2){
    //     if(arr[pnt1].f + arr[pnt2].f == x) { cout << arr[pnt1].s+1 << esp << arr[pnt2].s+1 << endl; return 0;}
    //     if(arr[pnt1].f + arr[pnt2].f < x) pnt2++;
    //     else if(arr[pnt1].f + arr[pnt2].f > x) pnt1++;
    // }

    while(pnt1 < n && pnt2 < n && pnt2 > pnt1){
        while(arr[pnt1].f + arr[pnt2].f > x && pnt2 > pnt1) pnt2--;

        if(pnt2 <= pnt1) break;

        while(arr[pnt1].f + arr[pnt2].f < x && pnt2 < n-1) pnt2++;

        if(arr[pnt1].f + arr[pnt2].f == x){cout << arr[pnt1].s + 1 << esp << arr[pnt2].s + 1 << endl; return 0;}

        pnt1++;
    }
    cout << "IMPOSSIBLE" << endl;


    return 0;
}