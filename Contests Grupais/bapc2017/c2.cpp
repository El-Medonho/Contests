#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 5e5+5;
const int mxm = 1e5+5;
const int MOD = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<ll> v(n);

    set<ll> st;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<ll> h(0); h.push_back(v[0]); st.insert(v[0]);
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]) continue;
        h.push_back(v[i]);
        st.insert(v[i]);
    }
    while(h.size() > 1){
        vector<ll> aux(0);
        for(int i = 1; i < h.size(); i++){
            aux.push_back(__gcd(h[i-1], h[i]));
        } h.resize(0);
        h.push_back(aux[0]);
        st.insert(aux[0]);
        for(int i = 1; i < aux.size(); i++){
            if(aux[i] == aux[i-1]) continue;
            h.push_back(aux[i]);
            st.insert(aux[i]);
        }
    }

    cout << st.size() << endl;
    
    return 0;
}