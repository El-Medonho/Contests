#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

const ll mx = 2e18;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<string> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int N = 0;

    pair<int,int> ini;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != '.' && arr[i][j] != '#') N++;
            if(arr[i][j] == 'P') ini = {i,j};
        }
    }

    vector<vector<int>> graph(N), vis(n, vector<int>(m, 0));

    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    int cnt = 0;

    function<ll(int,int)> dfs = [&](int i, int j){
        vis[i][j] = 1;
        int cc = -1;
        if(arr[i][j] != '.' && arr[i][j] != '#') cc = cnt++;

        ll val = -1;

        if(arr[i][j] - '0' >= 0 && arr[i][j] - '0' < 10){
            val = arr[i][j] - '0';
        }

        if(val >= 0) return val;

        ll val2 = -1;

        for(auto[xn, yn]: dir){
            int x = i+xn, y = j+yn;
            if(x < 0 || x == n || y < 0 || y == m || vis[x][y] || arr[x][y] == '.') continue;

            if(val == -1) {
                val = dfs(x,y);

                if(arr[i][j] == '#') return val;
            }
            else{
                val2 = dfs(x,y);
                if(val < val2) swap(val, val2);

                if(arr[i][j] == '+') val = val + val2;
                if(arr[i][j] == '-') val = val - val2;
                if(arr[i][j] == '*') val = val * val2;
                if(arr[i][j] == '/') val = val / val2;
            }
        }

        return val;
    };

    cout << dfs(ini.first, ini.second) << endl;

    return 0;
}