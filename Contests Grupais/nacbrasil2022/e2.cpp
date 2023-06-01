#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;

    int n,k,e,d; cin >> n >> k >> e;

    d = n-(k+e);

    if(e != d && d != k && k != e){
        cout << 0 << endl;
        return 0;
    }

    int ans = d+e;
    set<int> st; st.insert(k);
    for(int i = 0; i <= e; i++){
        if(st.find(i) != st.end()) continue; 
        if(i != 0) st.insert(i);
        for(int j = 0; j <= d; j++){
            if(st.find(j) != st.end()) continue;
            if(j != 0)st.insert(j);
            
            int hh = (e-i) + (d-j);
            int g = e-i, gg = d-j;
            for(; g >= 0; g--){
                if(st.find(g) != st.end()) continue;
                hh -= g;
                break;
            }
                st.insert(g);
            for(; gg >= 0; gg--){
                if(st.find(gg) != st.end()) continue;
                hh -= gg;
                break;
            }
            st.erase(g);

            ans = min(ans,hh);
            if(j != 0) st.erase(j);
        }
        if(i != 0) st.erase(i);
    }

    cout << ans << endl;

    return 0;
}