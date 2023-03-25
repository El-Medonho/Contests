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

    int n; cin >> n;
    vector<vii> graph(n);

    vii arr(n-1);
    for(int &i: arr) cin >> i;

    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        graph[--a].pb(--b);
        graph[b].pb(a);
    }

    vii occur(n,0);
    for(int i: arr) occur[i]++;
    if(occur[0] > 1){
        cout << 0 << endl;
        return 0;
    }

    vii ans;
    vii visited(n,0);
    for(int i = 0; i < n; i++){
        vii hh = occur;
        bool bl = occur[0] == 1;
        bool pass = true;
        hh[0] = 0;

        fill(visited.begin(), visited.end(), 0);
        visited[i] = 1;

        queue<pii> qw;
        for(int j: graph[i]) qw.push({j,1});

        while(!qw.empty()){
            pii curr = qw.front(); qw.pop();
            if(hh[curr.s-1] > 0) {pass = false; break;}

            visited[curr.f] = 1;

            hh[curr.s]--;
            if(hh[curr.s] < 0){
                if(!bl) {pass = false; break;}
                bl = false;
                hh[curr.s]++;
            }

            for(int j: graph[curr.f]){
                if(!visited[j]){
                    qw.push({j, curr.s+1});
                }
            }
        }

        if(pass) ans.pb(i);
    }

    cout << ans.size() << endl;
    if(ans.size() == 0) return 0;
    for(int i = 0; i < ans.size()-1; i++) cout << ans[i]+1 << esp;
    cout << (*ans.rbegin())+1 << endl;

    return 0;
}