#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

stack<vector<pair<int,int>>> stk;
vector<pair<int,int>> ck;
const int inf = 1e6;

void upd(int x, int val, vector<int> &bit){
    for(; x < bit.size(); x += x&-x){
        ck.emplace_back(x, bit[x]);
        bit[x] = min(val, bit[x]);
    }
}

int sum(int x, vector<int> &bit){
    int cc = inf;
    for(; x; x -= x&-x){
        cc = min(cc, bit[x]);
    }
    return cc;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,q; cin >> n >> q;

    vector<ll> arr(n, 0);
    set<ll> st;

    st.insert(0); st.insert(1e18+50);

    for(ll &i: arr){
        cin >> i;
        st.insert(i);
    }

    map<ll,ll> mp; int cnt = 1;

    for(ll i: st) mp[i] = cnt++;

    vector<int> bit(cnt+3, inf);

    for(int i = n-1; i > -1; i--){
        ck.clear();

        upd(mp[arr[i]], i, bit);

        stk.push(ck);
    }

    vector<vector<int>> l(n);
    vector<ll> r(q), v(q);
    
    for(int i = 0; i < q; i++){
        ll x,a,b; cin >> x >> a >> b;
        a--; b--;
        v[i] = x;
        r[i] = b;
        l[a].push_back(i);
    }

    for(int i = 0; i < n; i++){
        for(int cc: l[i]){
            v[cc] %= arr[i];

            auto it = st.upper_bound(v[cc]); it--;
            ll nxv = *it;

            int nxt = sum(mp[nxv], bit);

            if(nxt <= r[cc]) l[nxt].push_back(cc);
        }

        ck = stk.top();

        for(auto[a,b]: ck){
            bit[a] = b;
        }

        stk.pop();
    }

    for(ll x: v){
        cout << x << '\n';
    }



    return 0;
}