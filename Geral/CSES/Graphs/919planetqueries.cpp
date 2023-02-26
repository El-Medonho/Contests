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
    vii graph(n,0);

    for(int i = 0; i < n; i++) {cin >> graph[i]; graph[i]--;}

    vector<vii> up(32, vii(n,0));
    for(int i = 0; i < n; i++) up[0][i] = graph[i];

    for(int i = 1; i < 32; i++){
        for(int j = 0; j < n; j++){
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    while(q--){
        int curr,k; cin >> curr >> k; curr--;

        for(int i = 31; i >= 0; i--){
            if(k & (1<<i)){
                curr = up[i][curr];
            }
        }
        cout << curr+1 << endl;
    }

    return 0;
}