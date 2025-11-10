#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

bool clean(int i0, int j0, int div, vector<string>& grid) {
    if(!(i0+div <= grid.size() && j0+div <= grid[0].size())) {
        return false;
    }

    for(int i = i0; i < i0+div; i++) {
        for(int j = j0; j < j0+div; j++) {
            if(grid[i][j] == '#') grid[i][j] = '.';
            else return false;
        }
    }

    return true;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(string& line : grid) cin >> line;

    int some_line = 0;

    for(string& line : grid) {
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            if(line[i] == '#') cnt++;
            else if(cnt > 0) break;
        }
        some_line = cnt;
        if(some_line > 0) break;
    }

    vector<int> div;

    for(int i = 1; i <= some_line; i++) {
        if(some_line % i == 0) div.push_back(i);
    }

    int ans = -1;

    for(int d : div) {
        vector<string> curr_grid = grid;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(curr_grid[i][j] == '#') {
                    ok = ok && clean(i, j, d, curr_grid);
                }
            }
        }
        if(ok) ans = d;
    }

    cout << ans << '\n';

    return 0;
}