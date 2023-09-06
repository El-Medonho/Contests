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

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
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

    int n,m; cin >> n >> m;
    string s; cin >> s;

    vector<int> arr(n,0);
    int cnt = 0;
    char l = '2';

    for(int i = 0; i < n; i++){
        char c = s[i];

        if(c == l) arr[i] = arr[i-1];
        else arr[i] = ++cnt;

        l = c;
    }

    set<pair<int,int>> st, stgeral;
    vector<set<int>> arr2(n);
    int ans = 0;

    bool base = false;

    while(m--){
        int l,r; cin >> l >> r; l--; r--;

        bool cont = false;

        if(arr[l] == arr[r] || (arr[r]-arr[l] == 1 && s[l] == '0')){
            if(base) cont = true;
            base = true;
        }

        if(stgeral.find(make_pair(l,r)) != stgeral.end()) cont = true;

        stgeral.insert(make_pair(l,r));

        if(s[l] == '0' && s[r] == '1'){
            if(st.find(make_pair(arr[l], arr[r])) != st.end()) cont = true;
        }

        st.insert(make_pair(arr[l], arr[r]));

        if(s[l] == '0' && s[r] == '0'){
            if( arr2[r].find(arr[l]) != arr2[r].end() ) cont = true;

            if(r != n-1 && s[r+1] == '1'){
                if(st.find(make_pair(arr[l], arr[r+1])) != st.end()) cont = true;
                st.insert(make_pair(arr[l], arr[r+1]));
            }
        }

        arr2[r].insert(arr[l]);

        if(s[l] == '1' && s[r] == '1'){
            if( arr2[l].find(arr[r]) != arr2[l].end() ) cont = true;
            if(l != 0 && s[l-1] == '0'){
                if(st.find(make_pair(arr[l-1], arr[r])) != st.end()) cont = true;
                st.insert(make_pair(arr[l-1], arr[r]));
            }
        }

        if(s[l] == '1' && s[r] == '0'){
            if(l != 0 && s[l-1] == '0'){
                if(arr2[r].find((arr[l-1])) != arr2[r].end()) cont = true;
                arr2[r].insert((arr[l-1]));
            }
            if(r != n-1 && s[r+1] == '1'){
                if(arr2[l].find((arr[r+1])) != arr2[l].end()) cont = true;
                arr2[l].insert((arr[r+1]));
            }
            if(r != n-1 && s[r+1] == '1' && l != 0 && s[l-1] == '0'){
                if(st.find(make_pair(arr[l-1], arr[r+1])) != st.end()) cont = true;
                st.insert(make_pair(arr[l-1], arr[r+1]));
            }
        }

        arr2[l].insert(arr[r]);

        if(cont) continue;

        ans++;
    }

    cout << ans << endl;

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