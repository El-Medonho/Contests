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

    int n; cin >> n;
    
    vii graph(n); vector<vii> retrograph(n);
    for(int i = 0; i < n; i++){
        cin >> graph[i]; graph[i]--;
        retrograph[graph[i]].pb(i);
    }

    // vector<vii> up(20, vii(n,0));
    // for(int i = 0; i < n; i++) up[0][i] = graph[i];
    // for(int i = 1; i < 20; i++){
    //     for(int j = 0; j < n; j++){
    //         up[i][j] = up[i-1][up[i-1][j]];
    //     }
    // }

    queue<int> qw;

    vii depth(n,0);
    for(int i = 0; i < n; i++){
        if(graph[i] == i){
            depth[i] = 1;
            qw.push(i);
            
            while(!qw.empty()){
                int curr = qw.front(); qw.pop();
                for(int g: retrograph[curr]){
                    if(g == curr) continue;
                    depth[g] = depth[curr]+1;
                    qw.push(g);
                }
            }
        }
    }

    stack<int> stk;
    for(int i = 0; i < n; i++){
        if(depth[i] == 0){
            vii visited(n,0);
            int curr = i;

            while(true){
                bool tobreak = false;
                if(visited[curr] == 1){
                    int inloop = curr;

                    while(true){
                        if(visited[inloop] == 2){
                            int cnt = stk.size(); int first = stk.top();
                            while(!stk.empty()){
                                depth[stk.top()] = cnt;
                                qw.push(stk.top()); stk.pop();
                                
                                while(!qw.empty()){
                                    int gg = qw.front(); qw.pop();

                                    for(int jk: retrograph[gg]){
                                        if(jk == first || (stk.size() != 0 && jk == stk.top())) continue;
                                        depth[jk] = depth[gg]+1;
                                        qw.push(jk);
                                    }
                                }
                            }
                            tobreak = true;
                            break;
                        }

                        stk.push(inloop);
                        visited[inloop]++;
                        inloop = graph[inloop];
                    }
                }
                if(tobreak) break;
                
                visited[curr]++;
                curr = graph[curr];
            }
        }
    }

    for(int i = 0; i < n-1; i++) cout << depth[i] << esp;
    cout << depth[n-1] << endl;

    return 0;
}