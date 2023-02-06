#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define vii vector<int>
#define vss vector<string>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int c,n;
// vss ans;

int main(){
    fastio;

    while(true){
        cin >> c >> n;
        if(c == 0 && n == 0) break;
        vii apareceu(c,-1);
        vii casas(n);
        int end = -1;
        int comeco, final;

        for(int i = 0; i < n; i++) cin >> casas[i];

        vll casas_acumulado(n,0);
        ll soma = 0;
        for(int i = 0; i < n; i++){
            soma += casas[i];
            casas_acumulado[i] = soma;
        }
        for(int i = 0; i < n; i++){
            casas_acumulado[i] %= c;
            if(casas_acumulado[i] == 0){
                end = i; break;
            }
            if(apareceu[casas_acumulado[i]] != -1){comeco = apareceu[casas_acumulado[i]]; final = i;}
            else{apareceu[casas_acumulado[i]] = i;}
        }
        if(end != -1){ 
            for(int i = 0; i < end; i++) cout << i+1 << esp; cout << end+1 << endl;
            continue;
        }

        for(int i = comeco+1; i < final; i++) cout << to_string(i+1) << esp;

        cout << final+1 << endl;

        // ans.pb(endl);
    }
    // for(auto x:ans) {if(x == endl) cout << x; else cout << x << esp;}

    return 0;
}