// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

struct Seg {
    int n,m;
    vector<int> tree, cnt;
    vector<map<int, int>> rel;

    Seg(int _n, vector<int> ini) : n(_n) {
        m = 1;
        while(m < n) m *= 2;
        m*=2;
        tree.resize(m, 0);
        cnt.resize(m, 0);
        rel.resize(m);
        for(int i = 0; i < n; i++){
            tree[m/2+i] = ini[i];
            rel[m/2+i][ini[i]] = 1;
            cnt[m/2+i] = 1;
        }
        for(int i = m/2-1; i > 0; i--) {
            tree[i] = max(tree[2*i], tree[2*i+1]);
            auto it = rel[2*i+1].upper_bound(tree[2*i]);
            int to_cnt = -1;
            if(it == rel[2*i+1].end()) to_cnt = 0;
            else if(it == rel[2*i+1].begin()) to_cnt = cnt[2*i+1];
            else{
                it--;
                to_cnt = cnt[2*i+1] - (*it).second;
                it++;
            }
            
            cnt[i] = cnt[2*i]+to_cnt;
            rel[i] = rel[2*i];
            int sum = cnt[2*i];
            while(it != rel[2*i+1].end()) {
                sum++;
                rel[i][(*it).first] = sum;
                it++;
            }
        }
    }

    pair<int,int> query(int node, int a, int b, int l, int r, int carry) {
        if(a > r || b < l) return {0, 0};
        if(a >= l && b <= r) {
            auto it = rel[node].upper_bound(carry);
            int qtt = cnt[node];
            if(it != rel[node].begin()){
                it--;
                qtt -= (*it).second;
            }

            return {qtt, tree[node]};
        }
        int md = (a+b)/2;
        auto[x1, c] = query(2*node, a, md, l, r, carry);
        auto[x2, c2] = query(2*node+1, md+1, b, l, r, max(carry, c));
        return {x1+x2, max(c, c2)};
    }
};

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    int q; cin >> q;

    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    Seg seg(n, arr);

    while(q--){
        int a,b; cin >> a >> b;
        auto[x, c] = seg.query(1, 1, seg.m/2, a, b, 0);
        cout << x << endl;
    }

    return 0;
}