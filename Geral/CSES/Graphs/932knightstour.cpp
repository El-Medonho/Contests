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

vector<vii> grid(0);
int cnt = 0;

int movescheck(int x, int y){
    int moves = 0;

    if(x > 1 && y > 0 && grid[x-2][y-1] == 0) moves++;
    if(x > 0 && y > 1 && grid[x-1][y-2] == 0) moves++;
    if(x > 1 && y < 7 && grid[x-2][y+1] == 0) moves++;
    if(x > 0 && y < 6 && grid[x-1][y+2] == 0) moves++;
    if(x < 7 && y > 1 && grid[x+1][y-2] == 0) moves++;
    if(x < 6 && y > 0 && grid[x+2][y-1] == 0) moves++;
    if(x < 7 && y < 6 && grid[x+1][y+2] == 0) moves++;
    if(x < 6 && y < 7 && grid[x+2][y+1] == 0) moves++;
    
    return moves;
}

bool dfs(int x, int y){
    cnt++;
    grid[x][y] = cnt;
    bool near = false;

    if(cnt == 63){
        near = true;
    }

    if(cnt == 64){
        return true;
    }

    vii best = {9,-1,-1};
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;

    if(x > 1 && y > 0 && grid[x-2][y-1] == 0) {int h = movescheck(x-2,y-1); if(h!=0 || near)pq.push({h, {x-2,y-1}});}
    if(x > 0 && y > 1 && grid[x-1][y-2] == 0) {int h = movescheck(x-1,y-2); if(h!=0 || near)pq.push({h, {x-1,y-2}});}
    if(x > 1 && y < 7 && grid[x-2][y+1] == 0) {int h = movescheck(x-2,y+1); if(h!=0 || near)pq.push({h, {x-2,y+1}});}
    if(x > 0 && y < 6 && grid[x-1][y+2] == 0) {int h = movescheck(x-1,y+2); if(h!=0 || near)pq.push({h, {x-1,y+2}});}
    if(x < 7 && y > 1 && grid[x+1][y-2] == 0) {int h = movescheck(x+1,y-2); if(h!=0 || near)pq.push({h, {x+1,y-2}});}
    if(x < 6 && y > 0 && grid[x+2][y-1] == 0) {int h = movescheck(x+2,y-1); if(h!=0 || near)pq.push({h, {x+2,y-1}});}
    if(x < 7 && y < 6 && grid[x+1][y+2] == 0) {int h = movescheck(x+1,y+2); if(h!=0 || near)pq.push({h, {x+1,y+2}});}
    if(x < 6 && y < 7 && grid[x+2][y+1] == 0) {int h = movescheck(x+2,y+1); if(h!=0 || near)pq.push({h, {x+2,y+1}});}

    while(!pq.empty()){
        int h = pq.top().f, xp = pq.top().s.f, yp = pq.top().s.s;
        pq.pop();

        if(dfs(xp,yp)) return true;
    }

    grid[x][y] = 0;
    cnt--;

    return false;
}

int main(){
    fastio;

    int x,y; cin >> x >> y;
    swap(x,y); x--; y--;

    grid.resize(8, vii(8,0));

    dfs(x,y);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << grid[i][j] << esp;
        }
        cout << endl;
    }

    return 0;
}