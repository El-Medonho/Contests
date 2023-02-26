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

    int n,q; cin >> n >> q;

    bool a = false, b = false, c = false, d = false;
    int aq = -1, bq = -1, cq = -1 , dq = -1;
    while(q--){
        char h; cin >> h;
        if(h == 'r'){
            cin >> h;
            if(h == 'a') {
                if(a && d && b) {b = !b; bq = (b) ? q : -1; d = !d; dq = (d) ? q : -1; continue;}
                if(a && b) {a = 0; b = 0; d = !d; dq = (d) ? q : -1; continue;}
                if(a && d) {b = !b; bq = (b) ? q : -1; continue;}
                a = !a; aq = (a) ? q : -1;
            }
            if(h == 'b') b = !b; bq = (b) ? q : -1;
            if(h == 'c') {
                if(c && b) {c = !c; bq = (b) ? q : -1; continue;}
                if(c && b) {b = !b; bq = (b) ? q : -1; continue;}
                if(c && d) {d = !d; dq = (d) ? q : -1; continue;}
                c = !c; cq = (c) ? q : -1;
            }
            if(h == 'd') {d = !d; dq = (d) ? q : -1;}
        }else{
            int x,y; cin >> x >> y;

            vii arr = {aq,bq,cq,dq};
            sort(arr.begin(), arr.end());

            for(int g: arr){
                if(g == -1) continue;
                if(g == aq) swap(x,y);
                if(g == bq) y = (n+1)-y;
                if(g == cq) {swap(x,y); y = (n+1)-y; x = (n+1)-x;}
                if(d == dq) x = (n+1)-x;
            }

            cout << n*(x-1) + y << endl;
        }
    }

    return 0;
}