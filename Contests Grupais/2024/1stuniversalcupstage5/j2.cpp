#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

using pii = pair<int,int>;
vector<pii> d = {{3,1}, {3,-1}, {-3,1}, {-3,-1}, {1,3}, {1,-3}, {-1,3}, {-1,-3}};

void dfs(int i, int j, vector<int>& row, vector<int>& col , int& ok, int count) {
    row[i] = true;
    col[j] = true;

    if(count == row.size()) {
        ok = true;
        cout << i << ' ' << j << '\n';
        return;
    }

    for(auto [di,dj] : d) {
        int ni = i + di;
        int nj = j + dj;

        if(0 <= ni && ni < row.size() && 0 <= nj && nj < col.size() &&
           !row[ni] && !col[nj]) {
            dfs(ni, nj, row, col, ok, count+1);
            if(ok) {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
    }

    row[i] = false;
    col[j] = false;
}

bool check(int n) {
    vector<int> row(n), col(n);

    int ok = false;
    dfs(0,0, row, col, ok, 1);

    return ok;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    for(int i = 7; i < 8; i++) {
        if(check(i)) cout << i << endl;
    }

    return 0;
}