#include <bits/stdc++.h>

#define mxn 100005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define es " "
#define endl "\n"
#define pii pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;

int main(){
    fastio;
    
    int t; cin >> t;
    while(t--){
        ll x1,x2,k; cin >> x1 >> x2 >> k;

        ll a1,a2; a1 = max(x1,x2); a2 = min(x1,x2);

        if(k > a1) {cout << "NO" << endl; continue;}
        bool done = false;
        while(k < a1 && k < a2){
            ll c;
            c = a1; a1 = a2; a2 = c%a2;
            if(a2 == 0 or a1 == 0) break;
        }
        if(k == a1 || k == a2) done = true;
        if(a1 != 0 && a2 != 0 && k<=a1 && k%a2 == a1%a2) done = true;
        if(done) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}