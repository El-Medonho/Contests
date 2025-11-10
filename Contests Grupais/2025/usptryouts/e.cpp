#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

map<int,int> pos;

ll solve(int l, int r) {
    if(r <= l) return 0;
    int ans = r-l+1;
    int m = pos[]
    ans += solve(l, m)
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), sa(n);
    for(int& ai : a) cin >> ai;

    sa = a;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        pos[sa[i]] = i;
    }

    cout << solve(0, n-1) << '\n';

    return 0;
}