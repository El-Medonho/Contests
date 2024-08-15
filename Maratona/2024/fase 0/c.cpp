#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1004669333, mod2 = 2147483647;
const int cs = 20;

vector<array<int,cs>> vals(0);


void init(int n){
    vals.resize(n+50);

    uniform_int_distribution<int> uid(70, mod-5);

    for(int i = 0; i < n+10; i++) {
        for(int j = 0; j < cs; j++){
            vals[i][j] = uid(rng);
        }
    } 

    return;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    init(m);

    map<array<int,cs>, int> ans;
    map<int,vector<pii>> ends;
    map<int, vector<int>> finish;

    int id = 0;

    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ends[l].emplace_back(r,id++);
    }

    set<int> colors;

    array<int,cs> hs;

    for(int l = 0; l <= n; l++) {
        if(l != 0) ans[hs]++;

        for(auto [r,c] : ends[l]) {
            finish[r].push_back(c);
            for(int i = 0; i < cs; i++){

                hs[i] = ((hs[i] ^ vals[c][i]));
            }
        }
        for(auto c : finish[l]) {
            for(int i = 0; i < cs; i++){

                hs[i] = ((hs[i] ^ vals[c][i]));
            }
        }

        if(!finish[l].empty() && ends[l].empty()) ans[hs]++;
        bool ok = true;
        for(int i = 0; i < cs; i++){
            if(hs[i] != 0) ok = false;
        }
        if((!ends[l].empty() || !finish[l].empty()) && ok) ans[hs]++;
    }

    int best = 0;

    for(const auto& [s,currAns] : ans) {
        best = max(best, currAns);
    }

    cout << best << '\n';
}