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

    int n = 0; cin >> n;
    vector<vii> up(32, vii(n,0)), ups(n, vii(32,0)); vii depth(n,0);
    vii graph(n,0); vector<vii> retrograph(n);

    int pw = 0; cin >> pw;

    for(int i = 0; i < n; i++) {int a; cin >> a; a--; graph[i] = a; retrograph[a].pb(i);}


    for(int i = 0; i < n; i++) {up[0][i] = graph[i]; ups[i][0] = graph[i];}

    for(int i = 1; i < 32; i++){
        for(int j = 0; j < n; j++){
            up[i][j] = up[i-1][up[i-1][j]];
            ups[j][i] = up[i][j];
        }
    }

    queue<int> qw;
    for(int i = 0; i < n; i++) if(graph[i] == i) {qw.push(i); depth[i] = 1;}

    while(!qw.empty()){
        int curr = qw.front(); qw.pop();
        for(int j: retrograph[curr]){
            if(j == curr) continue;
            depth[j] = depth[curr]+1;
            qw.push(j);
        }
    } 

    for(int i = 0; i < n; i++){
        if(depth[i] == 0){
            int j = i;
            vii visited(n,0);
            while(true){
                if(visited[j] == 1){
                    bool inicio = true;
                    qw.push(j);
                    depth[j] = 1;
                    while(!qw.empty()){
                        int curr = qw.front(); qw.pop();
                        for(int gg: retrograph[curr]){
                            if(depth[gg] != 0 && !inicio) continue;
                            inicio = false;
                            depth[gg] = depth[curr]+1;
                            qw.push(gg);
                        }
                    } 
                    break;
                }
                visited[j] = 1;
                j = graph[j];
            }
        }
    }

    int fgh = pw;

    while(fgh--){
        int a,b; cin >> a >> b; a--; b--;

        // if(depth[b] < depth[a]) {cout << -1 << endl; continue;}
        int k = abs(depth[a]-depth[b]);
        int curr = (depth[a] > depth[b]) ? a : b, target = (curr == a) ? b : a; 

        for(int i = 23; i >= 0; i--){
            if(k & (1<<i)){
                curr = up[i][curr];
            }
        }
        if(depth[b] <= depth[a] && curr == target){cout << k << endl; continue;}

        bool late = false; 
        int distk = 0; curr = a;

        for(bool first = false; !late && !first;){      //log
            late = true;
            // curr = a;
            for(int h = 1, cnt = 0; h < 1e5+10; h*=2, cnt++){          //log
                int lastcurr = curr;
                // for(int i = 17; i >= 0; i--){           //32
                //     if((k) & (1<<i)){
                //         curr = up[i][curr];
                //     }
                // }
                curr = ups[curr][cnt];
                if(depth[lastcurr] - depth[curr] != h-(h/2)){
                    if(h == 1) {first = true; distk++;}
                    else {distk += h>>1; curr = lastcurr;}
                    late = false;
                    break;
                }
            }
        }
        
        if(late || depth[curr] < depth[b]) {cout << -1 << endl; continue;}

        k = abs(depth[b] - depth[curr]);
        
        for(int i = 31; i >= 0; i--){
            if(k & (1<<i)){
                curr = up[i][curr];
            }
        }
        if(curr != b) {cout << -1 << endl; continue;}
        cout << distk + k << endl;
        
    }

    return 0;
}