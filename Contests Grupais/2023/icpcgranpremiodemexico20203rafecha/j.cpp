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

int n,m,k;
vector<vii> graph(0);
int o,t;
vii normal(0); vector<pii> special(0);

int main(){
    fastio;

    cin >> n >> m >> k;

    graph.resize(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    cin >> o >> t;

    normal.resize(o);
    for(int &i: normal) {cin >> i; i--;}
    normal.pb(0);

    special.resize(o);
    for(int i = 0; i < o; i++){
        int a,b; cin >> a >> b; a--;
        special[i] = {a,b};
    }

    vector<vii> dp(o+1, vii(t+1, -1e9));
    vii depth(n, 1e9);

    for(int i = 0; i <= o; i++){
        int beg = (i == 0) ? 0 : normal[i-1];

        queue<int> qw;
        qw.push(beg);

        fill(depth.begin(), depth.end(), 1e9);
        depth[beg] = 0;

        while(!qw.empty()){
            int hj = qw.front(); qw.pop();

            for(int j: graph[hj]){
                if(depth[j] != 1e9) continue;
                depth[j] = depth[hj]+1;
                qw.push(j);
            }
        }

        int tempo = depth[normal[i]]*k;
        if(i == 0){
            dp[0][t-tempo] = 0;
        }else{
            for(int j = tempo; j <= t; j++){
                if(dp[i-1][j] == 1e9) continue;
                else dp[i][j-tempo] = dp[i-1][j];
            }
        }

        if(i > 0){  //entrega especial
            tempo = depth[special[i-1].f] * k;

            beg = special[i-1].f;
            qw.push(beg);

            fill(depth.begin(), depth.end(), 1e9);
            depth[beg] = 0;

            while(!qw.empty()){
                int hj = qw.front(); qw.pop();

                for(int j: graph[hj]){
                    if(depth[j] != 1e9) continue;
                    depth[j] = depth[hj]+1;
                    qw.push(j);
                }
            }

            tempo += depth[normal[i]]*k;

            if(i == 0){
                dp[0][t-tempo] = special[i-1].s;
            }else{
                for(int j = tempo; j <= t; j++){
                    if(dp[i-1][j] == 1e9) continue;
                    else dp[i][j-tempo] = max(dp[i-1][j] + special[i-1].s, dp[i][j-tempo]);
                }
            }
        }
    }

    int ans = -1;
    for(int i = 0; i <= t; i++){
        if(dp[o][i] == 1e9) continue;
        ans = max(ans, dp[o][i]);
    }

    if(ans == -1)cout << "Impossible" << endl;
    else cout << ans << endl;

    return 0;
}