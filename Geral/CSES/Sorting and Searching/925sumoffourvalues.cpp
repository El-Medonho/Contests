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

    int n,x; cin >> n >> x;
    vii arr(n), arrs(n);
    for(int &x: arr) cin >> x;

    if(n < 4) {cout << "IMPOSSIBLE" << endl; return 0;}

    arrs = arr;
    sort(arrs.begin(), arrs.end());
    

    
    for(int pnt1 = 0; pnt1 < n; pnt1++){
        for(int pnt2 = n-1; pnt2 > pnt1; pnt2--){
            int pnt3 = pnt1+1, pnt4 = pnt2-1;
            int target = x - (arrs[pnt1] + arrs[pnt2]);
            if(target < 0) continue;
            while(pnt3 < pnt4){
                int sum = arrs[pnt3] + arrs[pnt4];
                if(sum == target){
                for(int i = 0; i < n; i++) {if(arr[i] == arrs[pnt1]) {pnt1 = i; break;}}
                for(int i = 0; i < n; i++) {if(arr[i] == arrs[pnt2] && i != pnt1) {pnt2 = i; break;}}
                for(int i = 0; i < n; i++) {if(arr[i] == arrs[pnt3] && i != pnt1 && i != pnt2) {pnt3 = i; break;}}
                for(int i = 0; i < n; i++) {if(arr[i] == arrs[pnt4] && i != pnt1 && i != pnt2 && i != pnt3) {pnt4 = i; break;}}
                cout << pnt1+1 << esp << pnt2+1 << esp << pnt3+1 << esp << pnt4+1 << endl;
                return 0;
                }

                if(sum < target) pnt3++;
                else pnt4--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}