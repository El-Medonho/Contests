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

    int n,q; cin >> n >> q;
    map<int,set<int>> graph;

    while(q--){
        int t,a,b; cin >> t >> a >> b;
        if(t == 1) graph[a].insert(b);
        if(t == 2) graph[a].erase(b);
        if(t == 3){
            if(graph[a].find(b) != graph[a].end() && graph[b].find(a) != graph[b].end()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}