#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int inf = 1e9+5;

int solve(){

    int n,m,m2; cin >> n >> m >> m2;

    // vector<vector<int>> graph(n);

    vector<int> pai(n, 0), peso(n, 1);

    function<int(int)> ff;

    ff = [&](int x){
        if(pai[x] == x) return x;
        return pai[x] = ff(pai[x]);
    };

    function<void(int,int)> uu;

    uu = [&](int x, int y){
        x = ff(x);
        y = ff(y);

        if(x == y) return;

        if(peso[x] < peso[y]) swap(x,y);

        pai[y] = x;
        peso[x] += peso[y];

        return;
    };

    for(int i = 0; i < n; i++){
        pai[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;

        uu(a,b);
    }

    for(int i = 0; i < n; i++) ff(i);

    vector<int> pai2 = pai;

    for(int i = 0; i < n; i++){
        pai[i] = i;
    }

    m = m2;

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;

        uu(a,b);
    }

    map<pair<int,int>, int> mp;

    for(int i = 0; i < n; i++){
        ff(i);
        mp[{pai2[i], pai[i]}]++;
    }

    for(int i = 0; i < n; i++){
        cout << mp[{pai2[i], pai[i]}] << ' ';
    }
    cout << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}