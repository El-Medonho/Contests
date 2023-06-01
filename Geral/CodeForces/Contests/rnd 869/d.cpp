// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄


#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n);
    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    if(n < 5 && m < 5){
        cout << "NO\n";
        return 0;
    }

    // for(int i = 0; i < n; i++){
    //     queue<pair<int,int>> qw; qw.insert(i,0);
    //     vector<int> gg(n,0); gg[i] = 1;
    //     sort(graph[i].begin(), graph[i].end());
    //     while(!qw.empty()){
    //         pair<int,int> curr = qw.front();
    //         for(int j: graph[curr.first]){
    //             if(!gg[j]){
    //                 gg[j] = 1;
    //             }
    //         }
    //     }
    // }

    vector<int> vis(n,0), atall(n,0);
    vector<pair<int,int>> ans(0);
    stack<int> stk;

    int first = -1;

    function<bool(int,int)> dfs;

    vector<int> ant(n,-2);

    dfs = [&](int curr, int last){
        ant[curr] = last;
        vis[curr] = 1;
        atall[curr] = 1;

        for(int j: graph[curr]){
            if(vis[j] && j != last){
                int cnt = 0;
                if(ant[j] != -1){
                    cnt = 0;
                    for(int k: graph[j]){
                        if(!vis[k]) cnt++;
                        if(cnt == 1) break;
                    }
                    if(cnt >= 1){
                        for(int k: graph[j]){
                            if(!vis[k]) {
                                cnt--;
                                ans.push_back({j,k});
                            }
                            if(cnt == 0) {
                                ans.push_back({j, ant[j]});
                                ans.push_back({j,curr});
                                ans.push_back({curr,last});
                                return true;
                            }
                        }
                    }
                }
                else{
                    for(int k: graph[j]){
                        if(!vis[k]) cnt++;
                        if(cnt == 2) break;
                    }
                    if(cnt >= 2){
                        for(int k: graph[j]){
                            if(!vis[k]) {
                                cnt--;
                                ans.push_back({j,k});
                            }
                            if(cnt == 0) {
                                ans.push_back({j,curr});
                                ans.push_back({curr,last});
                                return true;
                            }
                        }
                    }
                }
            }
            if(j == last || vis[j]) continue;
            if(dfs(j,curr)){
                if(last != -1) ans.push_back({curr,last});
                return true;
            }
        }

        vis[curr] = 0;

        return false;
    };

    for(int i = 0; i < n; i++){
        first = i;
        if(!atall[i] && dfs(i,-1)){
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for(pair<int,int> hh: ans) cout << hh.first+1 << ' ' << hh.second+1 << '\n';
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}

int main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}