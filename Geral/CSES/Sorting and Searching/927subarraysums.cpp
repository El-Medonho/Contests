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

    int n,target; cin >> n >> target;
    vii arr(n); vii bit(n+1);
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        bit[i+1] = sum;
    }

    int pnt1 = 0, pnt2 = 1;

    int val = bit[pnt2], ans = 0;
    while(pnt1 != pnt2 && pnt1 != n){
        val = bit[pnt2]-bit[pnt1];
        if(val == target) ans++;
        if(val <= target){

            if(pnt2 == n) break;
            pnt2++;
        }
        if(val > target){
            if(pnt1+1 == pnt2 && pnt2 == n) break;
            if(pnt1+1 == pnt2 && pnt2 != n) pnt2++;
            else pnt1++;
        }
    }

    cout << ans << endl;


    return 0;
}