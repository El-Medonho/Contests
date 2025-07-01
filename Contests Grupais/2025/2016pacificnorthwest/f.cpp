#include "bits/stdc++.h"

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int m,r,n; cin >> m >> r >> n; r*=2;

    vector<vector<int>> graph(n);

    vector<vector<int>> grid(m, vector<int>(m, -1));

    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;

        for(int j = max(0, a-r); j < min(m, a+r); j++){
            if(grid[j][b] != -1) {
                graph[i].push_back(grid[j][b]);
                graph[grid[j][b]].push_back(i);
            }
        }

        for(int j = max(0, b-r); j < min(m, b+r); j++){
            if(grid[a][j] != -1) {
                graph[i].push_back(grid[a][j]);
                graph[grid[a][j]].push_back(i);
            }
        }

        grid[a][b] = i;
    }

    queue<int> qw;
    vector<int> cor(n, -1);

    for(int i = 0; i < n; i++){

        cout << i << ": ";
        for(int j: graph[i]) cout << j << ' ';
        cout << '\n';

        if(cor[i] == -1){
            qw.push(i); cor[i] = 0;
        }

        while(!qw.empty()){
            int cc = qw.front(); qw.pop();

            for(int j: graph[cc]){
                if(cor[j] != -1){
                    if(cor[j] == cor[cc]){
                        cout << "NO\n";
                        return 0;
                    }
                    continue;
                }
                cor[j] = (cor[cc]+1)%2;
                qw.push(j);
            }
        }
    }

    cout << "YES\n";

    return 0;
}