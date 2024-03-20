// ░░░░░░░░░░░░▄▄▄█████████▄▄▄░░░░░░░░░░░░
// ░░░░░░░░▄▄██████▀▀▀▀▀▀▀██████▄▄░░░░░░░░
// ░░░░░░▄████▀▀░░░░░░░░░░░░░▀▀████▄░░░░░░
// ░░░░▄███▀░░░░░░░░░░░░░░░░░░░░▀▀███▄░░░░
// ░░▄███▀░░░░░░░░░░░░░░░░░░░░░░░░░████░░░
// ░▄███▀░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░▀███░░
// ░███░░░░░░█████▄░░░░░░░░░░░░░░░░░░▀███░
// ███▀░░░░░░██████░░░░░░░░░░░░░░░░░░░███▄
// ███░░░░░░░█████▀░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░████▄░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░▀███▄░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░░░█████▄░░░▄███▄▄░░░░░░▄███
// ▀███░░░░░░░░░░░░▀████████████░░░░░░███░
// ░███▄░░░░░░░░░░░░░▀▀████████▀░░░░░███▀░
// ░░████░░░░░░░░░░░░░░░░░▀▀▀░░░░░░▄███▀░░
// ░░███▀░░░░░░░░░░░░░░░░░░░░░░░░░▄███▀░░░
// ░▄███░░░░▄▄░░░░░░░░░░░░░░░░░▄████▀░░░░░
// ▄███▄▄███████▄▄▄░░░░░░░▄▄▄█████▀░░░░░░░
// ███████▀▀▀▀▀███████████████▀▀░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ▒█░░▒█ █░░█ █▀▀█ ▀▀█▀▀ █▀▀ ░█▀▀█ █▀▀█ █▀▀█░
// ▒█▒█▒█ █▀▀█ █▄▄█ ░░█░░ ▀▀█ ▒█▄▄█ █░░█ █░░█░
// ▒█▄▀▄█ ▀░░▀ ▀░░▀ ░░▀░░ ▀▀▀ ▒█░▒█ █▀▀▀ █▀▀▀░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

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

    string gg;
    cin >> gg;
    
    bitset<100> nut; nut.reset();
    for(int j = 0; j < c; j++){
        if(gg[j] == '1') nut.set(j);
    }

    vector<bitset<100>> grid(r);
    for(int i = 0; i < r; i++){
        string hh; cin >> hh;
        grid[i].reset();
        for(int j = 0; j < c; j++){
            if(hh[j] == '1') grid[i].set(j);
        }
    }

    function<int(pii)> bfs;
    bfs = [&](pii in){
        queue<pii> qw; qw.push(in);

        vector<pii> dir(4);
        dir[0] = {-1,0}; dir[1] = {1,0}; dir[2] = {0,1}; dir[3] = {0,-1};

        vector<vector<int>> visited(r, vector<int> (c,0));
        visited[in.f][in.s] = 1;

        while(!qw.empty()){
            pii curr = qw.front(); qw.pop();
            // cout << curr.f << esp << curr.s << endl;

            if(curr.f == r-1){
                cout << "Y" << endl;
                return 1;
            }
            for(pii h: dir){
                pii next = curr;
                next.f += h.f; next.s = mod(next.s+h.s, c);

                if(next.f < 0 || next.f > r-1) continue;

                if(visited[next.f][next.s]) continue;

                bool pass = true;

                bitset<100> jj = nut;

                for(int i = 0; i < next.s; i++){
                    if(jj[c-1]){
                        jj <<= 1;
                        jj[0] = 1;
                    }else jj<<=1;
                }

                if(((grid[next.f])&jj).any()) {
                    pass = false;
                }
                if(pass){
                    qw.push(next);
                    visited[next.f][next.s] = 1;
                }
            }
        }
        return 0;
    };

    bitset<100> kk = nut;
    for(int i = 0; i < c; i++){
        bool pass = true;

        if((grid[0] & kk).any()){
            pass = false;
        }
        if(pass) if(bfs({0,i})) return 0;

        if(kk[c-1]){
            kk <<= 1;
            kk[0] = 1;
        }else kk<<=1;
    }

    reverse(gg.begin(), gg.end());

    nut.reset();
    for(int j = 0; j < c; j++){
        if(gg[j] == '1') nut.set(j);
    }
    kk = nut;

    for(int i = 0; i < c; i++){
        bool pass = true;

        if(((grid[0]) & kk).any()){
            pass = false;
        }
        if(pass) if(bfs({0,i})) return 0;

        if(kk[c-1]){
            kk <<= 1;
            kk[0] = 1;
        }else kk<<=1;
    }

    cout << "N" << endl;

    return 0;
}