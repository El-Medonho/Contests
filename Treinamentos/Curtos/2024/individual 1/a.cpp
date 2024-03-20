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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// struct edge {
//     int a, int b;
//     edge(int _a = 0, int _b = 0) : a(_a), b(_b) {}

//     bool operator<(const edge &y) {

//     }
// }

signed solve(){

    int n; cin >> n;

    vector<ll> a(n, 0), b(n, 0);

    for(int i = 1; i < n; i++){
        int x,y; cin >> x >> y;
        a[i] = x; b[i] = y;
    }    

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int x,y; cin >> x >> y; x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    function<void(int,int)> dfs;

    int hp = 0;

    vector<int> pai(n, 0);

    dfs = [&](int cc, int last){

        pai[cc] = last;

        for(int j: graph[cc]){
            if(j == last) continue;
            dfs(j,cc);
        }

        return;
    };

    dfs(0,0);

    vector<int> repr(n, 0);

    for(int i = 0; i < n; i++) repr[i] = i;

    function<int(int)> ff;
    
    ff = [&](int i){
        if(repr[i] == i) return i;
        return repr[i] = ff(repr[i]);
    };

    function<bool(int,int)> cmp;

    cmp = [&](int x, int y){
        ll dx = b[x] - a[x], dy = b[y] - a[y];
        if(dx >= 0 && dy < 0) return true;
        else if(dy >= 0 && dx < 0) return false;
        else if(dx >= 0){
            if(a[x] != a[y]) return a[x] < a[y];
            return x < y;
        }
        if(b[x] != b[y]) return b[x] > b[y];
        return x < y; 
    };

    set<int, decltype(cmp)> st(cmp);

    for(int i = 1; i < n; i++){
        st.insert(i);
    }

    while(!st.empty()){
        int x = *st.begin();
        st.erase(st.begin());

        x = ff(x);

        int y = ff(pai[x]);

        if(y != 0) st.erase(st.find(y));

        swap(x,y);

        repr[y] = x;
        a[x] = max(a[x], a[x] - b[x] + a[y]); 
        b[x] = max(b[y], b[y] + b[x] - a[y]);

        if(x != 0) st.insert(x);
    }

    cout << a[0] << endl;

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}