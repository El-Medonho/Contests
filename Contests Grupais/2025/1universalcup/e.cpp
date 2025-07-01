#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int n;
vector<vector<ll>> v;
const ll m = 998244353;
ll ans = 0;
vector<int> perm(5, -1);

void solve() {
    if(count(perm.begin(), perm.end(), 1) != 2 ||
       count(perm.begin(), perm.end(), -1) != 2 ||
       count(perm.begin(), perm.end(), 0) != 1
    ) {
        return;
    }

    int fixed = find(perm.begin(), perm.end(), 0) - perm.begin();

    for(ll& val : v[fixed]) {
        ll curr = 1;
        for(int i = 0; i < 5; i++) {
            if(i == fixed) continue;
            if(perm[i] == 1) {
                int count;
                if(i < fixed) count = n - (upper_bound(v[i].begin(), v[i].end(), val) - v[i].begin());
                else count = n - (lower_bound(v[i].begin(), v[i].end(), val) - v[i].begin());
                curr = curr * count % m;
            }else {
                int count;
                if(i < fixed) count = upper_bound(v[i].begin(), v[i].end(), val) - v[i].begin();
                else count = lower_bound(v[i].begin(), v[i].end(), val) - v[i].begin();
                curr = curr * count % m;
            }
        }

        ans = (ans + curr*val) % m;
    }
}

void backtracking(int i, int fixed) {
    if(i == 5) {
        if(fixed) {
            solve();
        }
        return;
    }

    perm[i] = 1;
    backtracking(i+1, fixed);
    perm[i] = -1;
    backtracking(i+1, fixed);
    if(!fixed) {
        perm[i] = 0;
        backtracking(i+1, 1);
    }
    perm[i] = -1;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    v.resize(5, vector<ll>(n));

    for(vector<ll>& vi : v) {
        for(ll& li : vi) cin >> li;
        sort(vi.begin(), vi.end());
    }

    backtracking(0, 0);

    cout << ans << '\n';

    return 0;
}