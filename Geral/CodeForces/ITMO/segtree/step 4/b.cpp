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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#include "bits/stdc++.h"

using namespace std;

int r;
vector<vector<int>> global = { {1,0}, {0,1} };
void join( vector<vector<int>> &a, vector<vector<int>> &b){
    a = { { (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % r,
            (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % r  },
            { (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % r,
            (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % r } };
}

vector<vector<int>> join2( const vector<vector<int>> &a, const vector<vector<int>> &b){
    return { { (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % r,
            (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % r  },
            { (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % r,
            (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % r } };
}


template <class T> struct Seg{
    int n;
    int m = 1;
    vector<vector<int>> neutral = { {1,0}, {0,1} };
    // vector<T> first;
    vector<T> tree;
    Seg(int n) : n(n) {
        while(m < n) m<<=1;
        tree.resize(2*m, { {1,0}, {0,1} });
    }

    void build(){
        for(int i = m-1; i > 0; i--){
            tree[i] = join2(tree[2*i], tree[2*i+1]);
        }
    }
    void query(int node, int l, int r, int a, int b){
        if(a>r || b<l) return; //remember to change
        if(a<=l && b>=r) {join(global, tree[node]); return;}
        int mid=(l+r)>>1;
        query(2*node,l,mid,a,b);
        query(2*node+1,mid+1,r,a,b);
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,q; cin >> r >> n >> q;
    // vector<vector<vector<int>>> arr(n, vector<vector<int>>(2, vector<int>(2)));
    Seg<vector<vector<int>>> seg(n);
    
    for(int g = 0; g < n; g++){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                int x;
                cin >> x;
                seg.tree[g+seg.m][i][j] = x%r;
            }
        }
        // seg.upd(g+1, arr);
    }
    seg.build();

    while(q--){
        int l,r; cin >> l >> r;
        seg.query(1, 1, seg.m, l, r);

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout << global[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        global = { {1,0}, {0,1} };
    }

    return 0;


    return 0;
}