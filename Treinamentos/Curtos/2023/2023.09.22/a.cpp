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

typedef long long ll;

const ll md = 1e9+7;

vector<int> repr(0), w(0);

int ff(int x){
    if(repr[x] == x) return x;
    return repr[x] = ff(repr[x]);
}

void uu(int x, int y){
    x = ff(x);
    y = ff(y);
    
    if(w[y] > w[x]) swap(x,y);

    repr[y] = x;
    w[x] += w[y];
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m,h; cin >> n >> m >> h;

    int N = n*m;

    vector<pair<ll, pair<int,int>>> edges(0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            ll x; cin >> x;
            edges.push_back(make_pair( x, make_pair(i*m + j, i*m + j + 1 ) ));
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            ll x; cin >> x;
            edges.push_back(make_pair( x, make_pair(i*m + j, i*m + j + m ) ));
        }
    }
    repr.resize(N); w.resize(N, 1);
    vector<ll> lvl(N, -1), res(N, 0);
    for(int i = 0; i < n*m; i++) repr[i] = i; 

    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++){
        ll cc = edges[i].first;
        auto [x,y] = edges[i].second;

        x = ff(x); y = ff(y);

        if(x == y) continue;

        if(w[x] < w[y]) swap(x,y);

        uu(x, y);

        res[x] += cc - lvl[x]; res[x] %= md; lvl[x] = cc;
        res[y] += cc - lvl[y]; res[y] %= md; lvl[y] = cc;

        res[x] = (res[x]*res[y]) % md;
    }

    ll ans = 0;

    int z = ff(0);

    res[z] += h - lvl[z]; res[z] %= md;
    ans = res[z];

    cout << ans << '\n';


    return 0;
}