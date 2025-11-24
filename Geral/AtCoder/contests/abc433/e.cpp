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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int mod = 1e9+7;
const ll inf = 1e18+5;

typedef tuple<int,int,int> pii;

signed solve(){
    
    int n, m; cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> x(n), y(m), xc(n, 0), yc(m, 0);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < m; i++) cin >> y[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = min(x[i], y[j]);
        }
    }
    
    vector<int> vis(n*m+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[arr[i][j]]++;
            if(x[i] == arr[i][j] && y[j] == arr[i][j]) pq.emplace(2*arr[i][j]+1, i, j);
            else pq.emplace(2*arr[i][j], i, j);

            if(arr[i][j] == x[i]) xc[i]++;
        }
        if(xc[i] == 0){
            cout << "No\n";
            return 0;
        }
    }

    for(int j = 0; j < m; j++){
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i][j] == y[j]) yc[j]++;
        } 
        if(yc[j] == 0){
            cout << "No\n";
            return 0;
        }
    }

    for(int a = 1; a <= n*m; a++){
        if(vis[a] == 0){
            while(!pq.empty()){
                auto[cc, i, j] = pq.top(); pq.pop();
                cc = arr[i][j];
                if(arr[i][j] < a || (x[i] == cc && xc[i] == 1) || (y[j] == cc && yc[j] == 1)) continue;
                
                if(x[i] == cc) xc[i]--;
                if(y[j] == cc) yc[j]--;
                vis[a]++;
                vis[arr[i][j]]--;
                arr[i][j] = a;
                break;
            }
        }
        if(vis[a] != 1) {
            cout << "No\n";
            return 0;
        }
    }


    cout << "Yes\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }




    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}