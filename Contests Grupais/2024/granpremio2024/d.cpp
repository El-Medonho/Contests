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

typedef long long ll;

signed solve(){

    int n,q; cin >> n >> q;

    string ans = "";

    // map<pair<int,int>, int> key;     //{comp[a], comp[b]}

    map<pair<int,int>, set<int>> pos_rel;       //map[{key[a], key[b]}] = pair<set<int>, set<int>>  {moda, modb}

    map<int, set<int>> single_diff_rel;

    vector<int> p(n);

    for(int &i: p) {cin >> i; i--;}

    vector<int> id(n, 0), pai(n, -1), sz(n, 0);

    for(int i = 0; i < n; i++){
        int cc = i;
        if(pai[i] > -1) continue;

        int u = i, cnt = 0;
        while(pai[u] == -1){
            pai[u] = i;
            sz[i]++; id[u] = cnt++;
            u = p[u];
        }
    }

    int rel = 0;

    for(int i = 0; i < n; i++){
        int a = (i-1+n)%n, b = i;
        int A = pai[a], B = pai[b];
        
        if(A > B){
            swap(A,B); swap(a,b);
        }

        if(A == B){
            single_diff_rel[A].insert((id[a] - id[b] + sz[A]) % sz[A]);
            single_diff_rel[A].insert((id[b] - id[a] + sz[A]) % sz[A]);
        }

        else{
            int d = abs(sz[A] - sz[B]);
            if(d == 0) d = sz[A];
            else d = __gcd(d, sz[A]);

            pos_rel[{A,B}].insert(((id[a] - id[b]) % d + d) % d);
            pos_rel[{A,B}].insert(((id[b] - id[a]) % d + d) % d);
        }
    }

    while(q--){
        int a,b; cin >> a >> b; a--; b--;

        int A = pai[a], B = pai[b];
        
        if(A > B){
            swap(A,B); swap(a,b);
        }

        if(A == B){
            int d = abs(id[a]-id[b]);
            if(single_diff_rel.find(A) == single_diff_rel.end() || single_diff_rel[A].find(d) == single_diff_rel[A].end()) ans.push_back('0');
            else ans.push_back('1');
        }

        else{
            int d = abs(sz[A] - sz[B]);
            if(d == 0) d = sz[A];
            else d = __gcd(d, sz[A]);

            if(pos_rel.find({A,B}) == pos_rel.end()) ans.push_back('0');
            else if(pos_rel[{A,B}].find(abs(id[a] - id[b]) % d) != pos_rel[{A,B}].end()) ans.push_back('1');
            else ans.push_back('0'); 
        }
    }

    cout << ans << endl;


    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;

    while(t--) solve();

    return 0;
}