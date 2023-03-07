#include "bits/stdc++.h"
using namespace std;

using lint = int64_t;

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

    lint n,q; cin >> n >> q;

    bool swaped = false, x = false, y = false;
    while(q--){
        char op; cin >> op;
        if(op == 'r'){
            char h;
            cin >> h;
            if(h == 'a') {
                swaped = !swaped; 
            }
            else if(h == 'b') {
                if(swaped) x = !x;
                else y = !y;
            }
            else if(h == 'c') {
                swaped = !swaped;
                x = !x;
                y = !y;
            }
            else {
                if(swaped) y = !y;
                else x = !x;
            }
        }else{
            lint xp,yp; cin >> xp >> yp;

            if(x) xp = n+1-xp;
            if(y) yp = n+1-yp;

            if(swaped) swap(xp,yp);
            xp--;
            lint res = n*(xp);
            cout << (lint) (res + yp) << endl;
        }
    }

    return 0;
}