#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

vector<string> grid(0);
vector<vii> layer(0);
stack<char> stk;
int n,m,k; 
int curr = -1;

int bfs(pii begin){
    queue<pii> q;
    q.push(begin);

    layer.resize(n, vii(m, -1));
    layer[begin.f][begin.s] = 0;

    while(!q.empty()){
        int i = q.front().f, j = q.front().s;
        q.pop();
        if(grid[i][j] == 'B'){
            return layer[i][j];
        }
        // grid[i][j] = '#';

        if(i != 0 && layer[i-1][j] == -1 && grid[i-1][j] != '#') {layer[i-1][j] = layer[i][j]+1; q.push({i-1,j});}
        if(i != n-1 && layer[i+1][j] == -1 && grid[i+1][j] != '#') {layer[i+1][j] = layer[i][j]+1; q.push({i+1,j});}
        if(j != 0 && layer[i][j-1] == -1 && grid[i][j-1] != '#') {layer[i][j-1] = layer[i][j]+1; q.push({i,j-1});}
        if(j != m-1 && layer[i][j+1] == -1 && grid[i][j+1] != '#') {layer[i][j+1] = layer[i][j]+1; q.push({i,j+1});}
    }
    return -1;

}

bool dfs(int i, int j){
    curr++;
    if(layer[i][j] < curr){
        curr--;
        stk.pop();
        return false;
    }
    if(grid[i][j] == 'B'){
        return true;
    }

    grid[i][j] = '#';

    if(i != 0 && grid[i-1][j] != '#'){stk.push('U'); if(dfs(i-1,j)) return true;}
    if(i != n-1 && grid[i+1][j] != '#'){stk.push('D'); if(dfs(i+1,j)) return true;}
    if(j != 0 && grid[i][j-1] != '#'){stk.push('L'); if(dfs(i,j-1)) return true;}
    if(j != m-1 && grid[i][j+1] != '#'){stk.push('R'); if(dfs(i,j+1)) return true;}

    curr--;
    stk.pop();
    return false;
}

int main(){
    fastio;

    cin >> n >> m;
    grid.resize(n,"");
    for(string &s: grid) cin >> s;

    pii begin, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A') begin = {i,j};
            if(grid[i][j] == 'B') end = {i,j};
        }
    }

    k = bfs(begin);

    if(k == -1) {cout << "NO" << endl;}

    if(dfs(begin.f, begin.s)){
        cout << "YES" << endl;
        cout << stk.size() << endl;
        vector<char> arr(stk.size(), 0);
        for(int i = arr.size()-1; i >= 0; i--){
            arr[i] = stk.top();
            stk.pop();
        }
        for(int i = 0; i < arr.size()-1; i++){
            cout << arr[i];
        }
        cout << arr[arr.size()-1] << endl;
    }
    else cout << "NO" << endl;
    return 0;
}