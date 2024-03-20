#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define endl '\n'
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn=2e3+5;
const int mxm=1e5+5;
const int MOD=1e9+7;

int n, memo[mxn][mxn];
ll resp;
array<ll, 4> v[mxn];
array<ll, 2> pass[mxn];

void dj(){
    priority_queue<array<ll, 3> > fila;

    fila.push({0, 0, v[0][0]}); //i, cont, t

    while(!fila.empty()){
        ll u = -fila.top()[0], d = fila.top()[2], cont = -fila.top()[1];
        fila.pop();

        resp=max(resp, cont);

        if(u==n || memo[u][cont]) continue;
        memo[u][cont] = 1;

        if(d-v[u][3]>=0){
            fila.push({-(u+1), -(cont+1), d - v[u][3] + pass[u][1]});
        }
        fila.push({-(u+1), -cont, d+pass[u][0]});
    }
}

void cases(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
    }
    sort(v, v+n);
    for(int i=0; i<n-1; i++){
        //pass[i][0] nao passei e pass[i][1] passei

        pass[i][0] = v[i+1][0] - v[i][2];
        pass[i][1] = v[i+1][0] - v[i][1];
    }
    dj();
    cout << resp << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t=1;

    // cin >> t;

    for(int i=1; i<=t; i++){
        // cout << "Case #" << i << ": ";
        cases();
    }
    return 0;
}