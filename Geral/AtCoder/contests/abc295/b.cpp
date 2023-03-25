//MEDONHO APENAS

#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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

int main(){
    fastio;

    int r,c; cin >> r >> c;

    vector<string> grid(r), newgrid;

    for(string &s: grid) cin >> s;

    newgrid = grid;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] - '0' > -1 && grid[i][j] - '0' < 10){
                int power = grid[i][j] - '0';
                
                queue<pair<int,pii>> qw;
                qw.push({0,make_pair(i,j)});
                vector<vii> visited(r, vii(c,0));

                while(!qw.empty()){
                    int x = qw.front().s.f, y = qw.front().s.s, pw = qw.front().f;
                    qw.pop();

                    newgrid[x][y] = '.';

                    if(pw+1 > power) continue;

                    if(x > 0 && !visited[x-1][y]) {
                        qw.push({pw+1, make_pair(x-1, y)});
                        visited[x-1][y] = 1;
                    }
                    if(y < c-1 && !visited[x][y+1]) {
                        qw.push({pw+1, make_pair(x, y+1)});
                        visited[x][y+1] = 1;
                    }
                    if(y > 0 && !visited[x][y-1]) {
                        qw.push({pw+1, make_pair(x, y-1)});
                        visited[x][y-1] = 1;
                    }
                    if(x < r-1 && !visited[x+1][y]) {
                        qw.push({pw+1, make_pair(x+1, y)});
                        visited[x+1][y] = 1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << newgrid[i][j];
        }
        cout << endl;
    }

    return 0;
}