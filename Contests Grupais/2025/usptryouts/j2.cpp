#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int mxn = 1e6+5;
const int MOD = 1e9+7;

vector<int> vec[mxn];

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }


    vector<int> memo(n+1);
    vector<array<int, 2> > resp(n+1);
    queue<int> fila;
    fila.push(s);
    resp[s][0] = 1;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        
        if(memo[u] != 1) memo[u]++;

        if(memo[u] == 3 && u == t){
            cout << resp[u][1]%MOD << endl;
        }

        if(memo[u] == 3) continue;

        cout << u << ' ' << resp[u][0] << ' ' << resp[u][1] << endl;
        for(int i:vec[u]){
            if(!memo[i]){
                memo[i] = 1;
                resp[i][0] += resp[u][0];
                fila.push(i);
            }else if(memo[i]==1 || memo[i]==2){
                memo[i] = 2;
                resp[i][1] += resp[u][0];
                fila.push(i);
            }
        }
    }

    return 0;
}