#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n; cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++){
        int c, s; cin >> c >> s;
        if(c > s) swap(c,s);
        int r1 = s-c;
        int r2 = 10 - r1;
        ans += min(r1,r2);
    }
    
    cout << ans << "\n";
}