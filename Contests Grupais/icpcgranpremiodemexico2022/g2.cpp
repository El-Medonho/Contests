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

    ull n,q; cin >> n >> q;

    bool swaped = false, x = false, y = false, xk = false, yk = false;
    while(q--){
        char h; cin >> h;
        if(h == 'r'){
            cin >> h;
            if(h == 'a') {
                swaped = !swaped; 
                if(swaped) {xk = false; yk = false;}
                else {x = (xk != x); y = (y != yk);}
            }
            if(h == 'b') {
                if(swaped) xk = !xk;
                else y = !y;
            }
            if(h == 'c') {
                swaped = !swaped;
                x = !x;
                y = !y;
                if(swaped) {xk = false; yk = false; continue;}
                else {x = (xk != x); y = (y != yk);}
            }
            if(h == 'd') {
                if(swaped) yk = !yk;
                else x = !x;
            }
        }else{
            ull xp,yp; cin >> xp >> yp;

            if(swaped) {
                swap(xp,yp);

                if(yk != y) xp = n+1-xp;
                if(xk != x) yp = n+1-yp;
            }else{
    
                if(x) xp = n+1-xp;
                if(y) yp = n+1-yp;

            }

            cout << n*(xp-1) + yp << endl;
        }
    }

    return 0;
}