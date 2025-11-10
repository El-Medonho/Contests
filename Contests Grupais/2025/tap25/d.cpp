#include "bits/stdc++.h"

#define endl '\n'

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int soma = 0;
    map<string, int > mapa;
    set<string> sla;
    for(int i=0; i<n+m; i++){
        int v, w;
        string p, q;

        cin >> v >> p >> w >> q;

        sla.insert(p);
        sla.insert(q);

        if(p == q){
            soma += (v>w ? 1:-1);
        }else{
            soma += 1;
            mapa[q]++;
        }
    }
    for(string i:sla){
        if(soma - 2*mapa[i] == n-m){
            cout << i << endl;
         //return 0;
        }
    }
    cout << '*' << endl;
    return 0;
}