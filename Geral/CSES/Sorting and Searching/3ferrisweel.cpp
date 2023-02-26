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

    int n, limit; cin >> n >> limit;
    vii arr(n); vii taken(n,0);
    for(int i = 0; i < n ; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int pnt1  = 0, pnt2 = n-1;
    int ans = 0;

    while(pnt2 > pnt1){
        if(arr[pnt1] + arr[pnt2] > limit) pnt2--;
        else{
            taken[pnt1] = taken[pnt2] = 1;
            pnt1++; pnt2--;
            ans++;
        }
    }
    for(int i = 0; i < n; i++){
        if(!taken[i] && arr[i] <= limit) ans++; 
    }

    cout << ans << endl;

    return 0;
}