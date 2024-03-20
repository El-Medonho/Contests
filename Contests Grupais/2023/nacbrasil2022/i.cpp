#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define f first
#define s second

int main(){
    fastio;

    int r,c; cin >> r >> c;

    vector<vector<int>> grid(r, vector<int> (c));

    for(int i = 0; i < r; i++){
        for(int &j: grid[i]) cin >> j;
    }

    function<void(int, pair<int,int>)> dfs;

    int ans = 0;

    vector<vector<int>> viss(r, vector<int>(c, 0));

    dfs = [&](int in, pair<int,int> pii){
        vector<pair<int,int>> coords(r*c+1, {-1,-1});

        vector<vector<int>> visited(r, vector<int> (c,0));

        int lans = 0, curr = in;
        coords[in] = pii;

        visited[pii.f][pii.s] = 1;

        for(int i = in; i <= r*c; i++){
            pair<int, pair<int,int>> hh = {i, coords[i]};
            if(hh.s.f == -1) continue;

            curr = hh.first;
            lans++;

            pair<int,int> gg = hh.second;

            viss[gg.f][gg.s] = 1;

            vector<pair<int,int>> vii(4);

            for(int i = 0; i < 4; i++){
                vii[i] = {((i & 2) >> 1) * ((i & 1) ? -1 : 1), (!(i & 2)) * ((i & 1) ? -1 : 1)};
            }

            for(pair<int,int> h: vii){
                h.f += gg.first; h.s += gg.s;

                if(h.f > -1 && h.f < r && h.s > -1 && h.s < c){}
                else continue;

                if(visited[h.f][h.s]) continue;
                visited[h.f][h.s] = 1;

                coords[grid[h.f][h.s]] = h;
            }
        }

        ans = max(ans, lans);
    };

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!viss[i][j])dfs(grid[i][j], {i,j});
        }
    }

    cout << ans << endl;

    return 0;
}