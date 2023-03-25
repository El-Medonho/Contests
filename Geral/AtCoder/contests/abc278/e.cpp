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

int main(){
    fastio;

    int h, w, n, hl, wl; cin >> h >> w >> n >> hl >> wl;
    vii occurg(n+1,0);
    vector<vii> grid(n, vii(n));
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int a; cin >> a;
            occurg[a]++;
            grid[i][j] = a;
        }
    }

    vector<vii> ans(h-hl+1, vii(w-wl+1,0));

    for(int i = 0; i < h-hl+1; i++){
        // if(i != 0){
        //     for(int a = 0; a <= wl-1; a++) occurg[grid[i-1][a]]++;
        //     for(int a = 0; a <= wl-1; a++) occurg[grid[i+hl-1][a]]--;
        // }
        vii occur = occurg;
        for(int j = 0; j < w-wl+1; j++){
            if(j == 0){
                for(int a = i; a < i+hl; a++){
                    for(int b = 0; b < wl; b++) occur[grid[a][b]]--;
                }
                int answ = 0;
                for(int a = 1; a <= n; a++) if(occur[a] != 0) answ++;
                ans[i][0] = answ;
                continue;
            }
            if(j != 0){
                for(int a = i; a <= i+hl-1; a++) occur[grid[a][j-1]]++;
                for(int a = i; a <= i+hl-1; a++) occur[grid[a][j+wl-1]]--;
            }
            for(int a = 1; a <= n; a++) if(occur[a] != 0) ans[i][j]++;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size()-1; j++) cout << ans[i][j] << esp;
        cout << ans[i][ans[0].size()-1] << endl;
    }
    

    return 0;
}