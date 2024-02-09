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

signed solve(){

    int n; cin >> n;

    set<int> tipo[4];
    vector<int> mp(n, -1);

    int sz;

    {
        int x,y; cin >> x >> y;
        int h = (x&1) + 2*(y&1);
        sz = h;
    }

    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        int h = (x&1) + 2*(y&1);
        tipo[h].insert(i); 
        mp[i] = h;
    }

    if(n == 1){
        cout << "First\n";
        cout.flush();
        cout << "1\n";
        cout.flush();
        return 0;
    }

    int h[4];
    for(int i = 0; i < 4; i++) h[i] = tipo[i].size();

    int h1;
    if(sz == 1 || sz == 3)h1 = h[sz] + h[(sz+1)%4];
    else h1 = h[sz] + h[(sz+3)%4];

    if( h1 >= (n+2)/2 ){
        cout << "Second\n";
        cout.flush();
        int f; cin >> f;
        int op, ini;
        if(sz == 0 || sz == 3){
            ini = 0;
            op = -1;
        }
        else {
            ini = 1; op = 1;
        }

        int cnt = 1;
        while(cnt < n){
            if(cnt&1){
                while(tipo[ini].size() == 0) ini = ((ini+op) + 4) % 4;
                cout << (*tipo[ini].begin()) + 1 << endl;
                cout.flush();
                tipo[ini].erase(tipo[ini].begin());
            }
            else {
                int x; cin >> x; x--;
                tipo[mp[x]].erase(x);
            }
            cnt++;
        }
    }

    else{
        cout << "First\n";
        cout.flush();
        int ini = -1, op = 1, mx = -1;;
        for(int i = 0; i < 4; i++){
            int nxt = (i+1)%4;
            if(i == 0 || i == 2) nxt = (i+3)%4; 

            if(h[i] + h[nxt] > mx){
                mx = h[i] + h[nxt];
                ini = i;
            }
        }

        ini = sz;
        if(tipo[sz].empty()){
            if(sz == 0 || sz == 3) ini = (ini+3)%4;
            else ini = (ini+1)%4;
        }

        cout << (*tipo[ini].begin()) + 1 << endl;
        cout.flush();
        tipo[ini].erase(tipo[ini].begin());

        int cnt = 1;

        if(ini == 0 || ini == 3){
            ini = 1;
        }
        else ini = 3;

        while(cnt < n){
            if(!(cnt&1)){
                while(tipo[ini].size() == 0) ini = ((ini+op) + 4) % 4;
                cout << (*tipo[ini].begin()) + 1 << endl;
                cout.flush();
                tipo[ini].erase(tipo[ini].begin());
            }
            else {
                int x; cin >> x; x--;
                tipo[mp[x]].erase(x);
            }
            cnt++;
        }
    }
    

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