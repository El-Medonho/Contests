#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

signed solve(){
    int n,q; cin >> n >> q;

    vector<set<int>> pos(26);
    set<int> st;
    vector<int> eq(n, 1e9);
    int l = 0;

    string s; cin >> s;

    for(int i = 0; i < n-1; i++){
        int c = s[i]-'a', cc = s[i+1]-'a';
        if(c < cc) st.insert(i);
        eq[i] = l;
        if(c != cc) l = i+1;
    }
    eq[n-1] = l;

    while(q--){
        int l,r; cin >> l >> r; l--; r--;

        if(st.lower_bound(l) == st.end() || (*st.lower_bound(l)) > r) {
            cout << max(eq[r]+1, l+1)  << endl;
            continue;
        }
        int x = *st.lower_bound(l);
        
        cout << max(eq[x]+1, l+1) << '\n';
    }


    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}