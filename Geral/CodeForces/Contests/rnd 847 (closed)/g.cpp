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

    int p,b; cin >> p >> b;
    vector<int> token(n,0);
    for(int i = 0; i < p; i++){
        int a; cin >> a; a--;
        token[a] = 1;
    }

    vector<int> bonus(n,0);
    for(int i = 0; i < b; i++){
        int a; cin >> a; a--;
        bonus[a] = 1;
    }

    vector<vector<int>> bgraph(n);

    while(m--){
        int a,b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if(bonus[a]) bgraph[b].push_back(a);
        if(bonus[b]) bgraph[a].push_back(b);
    }

    for(int i: graph[0]){
        if(token[i]){
            cout << "Yes" << '\n';
            return 0;
        }
    }
    if(token[0]){
        cout << "Yes" << '\n';
        return 0;
    }

    if(b == 0){
        cout << "No" << '\n';
        return 0;
    }

    queue<pair<int,int>> qw;
    qw.push({0,0});

    int chosen = -1, len = -1;
    vector<int> vis(n,0);

    while(!qw.empty()){
        pair<int,int> curr = qw.front();
        qw.pop();
        vis[curr.first] = 1;

        for(int i: graph[curr.first]){
            if(!vis[i] && token[i]){
                chosen = i;
                len = curr.second;
                break;
            }

            if(!vis[i] && bonus[i]) qw.push({i,curr.second+1});

        }
        if(len != -1) break;
    }

    if(chosen == -1){
        cout << "No" << '\n';
        return 0;
    }

    vector<int> loopable(n,-1);
    int qtt = 0;

    for(int i = 0; i < n; i++){
        if(token[i] && i != chosen){

            if(bgraph[i].size() > 0) {
                qtt++;
                for(int j: bgraph[i]){
                    if(bgraph[j].size() > 0){
                        cout << "Yes" << '\n';
                        return 0;
                    }
                }
            }

        }
        if(qtt >= len){
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';

    return 0;
}

int main(){
    fastio;

    int t = 1;
    cin >> t;
    string s;
    while(t--){
        solve();
        // if(t > 1) cin >> s; 
    }    

    return 0;
}