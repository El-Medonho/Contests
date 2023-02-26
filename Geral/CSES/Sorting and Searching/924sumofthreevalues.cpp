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
    vii arr(n);
    for(int &x:arr) cin >> x;
    if(n < 3){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vii arrs = arr;
    sort(arrs.begin(), arrs.end());

    for(int g = 0; g < n; g++){
        vii arraux(n-1); int ggg = 0;
        int aux = arrs[g];
        for(int &x: arraux){
            if(ggg == g) ggg++;
            x = arrs[ggg];
            ggg++;
        }

        int pnt1 = 0, pnt2 = n-2, target = x-aux;
        while(pnt1 < pnt2){
            int sum = arraux[pnt1] + arraux[pnt2];
            if(sum == target){
                for(int i = 0; i < n; i++) {if(arr[i] == arraux[pnt1]) {pnt1 = i; break;}}
                for(int i = 0; i < n; i++) {if(arr[i] == arraux[pnt2] && i != pnt1) {pnt2 = i; break;}}
                for(int i = 0; i < n; i++) {if(arr[i] == arrs[g] && i != pnt1 && i != pnt2) {g = i; break;}}
                cout << g+1 << esp << ++pnt1 << esp << ++pnt2 << endl;
                return 0;
            }
            if(sum < target) pnt1++;
            else pnt2--;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}