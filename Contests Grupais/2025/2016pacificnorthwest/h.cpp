#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

void upd(int x, ll val, vector<ll> &bit){
    for(; x < bit.size(); x += x&-x) bit[x] = max(bit[x], val);
    return;
}

ll sum(int x, vector<ll> &bit){
    ll resp = 0;
    for(; x; x -= x&-x) resp = max(resp, bit[x]);
    return resp;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll k,n; cin >> k >> n;

    vector<pair<ll,ll>> arr(n);

    set<ll> st;
    map<ll,ll> mp;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        st.insert(arr[i].first); st.insert(arr[i].second);
    }

    st.insert(k);

    int cnt = 1;

    for(ll i: st) mp[i] = cnt++;

    vector<ll> bit(cnt+5, 0);

    sort(arr.begin(), arr.end());

    ll ans = 0;

    for(auto[a,b]: arr){
        ll cc = sum(mp[a], bit);
        cc += b-a+1;
        ans = max(ans, cc);
        upd(mp[b]+1, cc, bit);
    }

    cout << k-ans << '\n';




    return 0;
}