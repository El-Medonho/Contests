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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<int> masks;
vector<int> yes; // cara que tem yes ao menos nesses pontos, Guardar ordenado por (mais caras ligados, menor i)

bool generate(int i, int subset, int im) {
    if(i == m) {
        if(!yes[subset] || __popcount(masks[yes[subset]]) < __popcount(masks[im])) {
            yes[subset] = im;
        }
        return true;
    }
    int upd = generate(i+1, subset, im);
    if(subset&(1<<i) && upd) generate(i+1, subset^(1<<i), im);
    return upd;
}

int nt(int mask) {
    return mask ^ ((1<<m)-1);
}

int main() {
    fastio;

    cin >> n >> m;
    
    masks.resize(n+1);
    vector<pair<int,int>> ord(n);
    for(int i = 1; i <= n; i++) {
        string mask;
        cin >> mask;
        for(char& c : mask) c = (c == 'Y' ? '1' : '0');
        masks[i] = stoi(mask, nullptr, 2);
        ord[i-1] = {-(__popcount(masks[i])), i};
    }
    
    sort(ord.begin(), ord.end());
    vector<int> masks2 = masks;
    vector<int> rel(n+1, -1);

    for(int i = 1; i <= n; i++){
        masks[i] = masks2[ord[i-1].second];
        rel[i] = ord[i-1].second;
    }

    yes.resize(1<<m);
    
    int cnt = -1;
    int i0 = -1, i1 = -1;
    
    for(int i = 1; i <= n; i++) {
        int h = __popcount(masks[yes[nt(masks[i])]] & masks[i]);
        if(yes[nt(masks[i])] && h >= cnt) {
            int ni0 = rel[yes[nt(masks[i])]];
            int ni1 = rel[i];

            if(ni1 < ni0) swap(ni1, ni0);
            
            if(h > cnt || make_pair(ni0, ni1) < make_pair(i0, i1)){
                i0 = ni0; i1 = ni1;
            }
            cnt = __popcount(masks[yes[nt(masks[i])]] & masks[i]);
        }
        generate(0, masks[i], i);
    }

    if(i0 == -1) cout << "No\n";
    else cout << i0 << ' ' << i1 << '\n';
}