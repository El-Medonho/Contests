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

    int n,m; cin >> n >> m;
    vector<vii> graph(n); vii related(n,0); vll points(n,0);
    while(m--){
        int a,b; cin >> a >> b;
        graph[--a].pb(--b);
    }

    points[0] = 1;

    queue<int> qw;
    qw.push(0);

    while(!qw.empty()){
        int curr = qw.front(); qw.pop();

        for(int j: graph[curr]){
            if(related[j] == 0) qw.push(j);
            related[j]++;
        }
    }

    qw.push(0);

    while(!qw.empty()){
        int curr = qw.front(); qw.pop();

        for(int j: graph[curr]){
            related[j]--;
            points[j] += points[curr];
            points[j] = mod(points[j], MOD);
            if(related[j] == 0) qw.push(j);
        }
    }
    
    cout << points[n-1] << endl;

    return 0;
}