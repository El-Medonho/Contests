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
    vii parent(n+1,0);
    vector<vii> up(n+1, vii(20,0));

    for(int i = 2; i <= n; i++){
        cin >> parent[i]; 
    }

    for(int i = 0; i < n+1; i++){
        up[i][0] = parent[i];
    }

    for(int i = 1; i < 20; i++){
        for(int j = 0; j < n+1; j++){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }

    while(q--){
        int x,k; cin >> x >> k;
        for(int i = 19; i > -1; i--){
            if(k & (1<<i)) x = up[x][i];
        }
        cout << ((x == 0) ? -1 : x) << endl;
    }

    return 0;
}