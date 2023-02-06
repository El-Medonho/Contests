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

ll mmod, q;
ll a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2;
vector<vll> base, A;
vector<vector<vll>> Aq;

// função para multiplicar matrizes (MOD opcional) (uso de ll é possível)
vector<vll> mult_matriz(vector<vll> a, vector<vll> b){    //possivel usar "&"
    vector<vll> z(a.size());
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            ll sum = 0;
            for(int k = 0; k < a[0].size(); k++){
                sum += mod(a[i][k]*b[k][j],MOD);
                sum=mod(sum,MOD);
            }
            z[i].pb(mod(sum,MOD));
        }
    }
    return z;
}


pll recorrencia_matriz(int expo){
    if (expo == 0) return (make_pair(base[2][0],base[5][0]));
    if (expo == 1) return (make_pair(base[1][0],base[4][0])); expo -= 2;
    vll digits(0);

    while(expo>1){
        digits.pb(expo%2); expo/=2;
    }
    digits.pb(expo);

    vector<vll> id = {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
    int index = 0;
    for(auto x: digits){
        if(x == 1){
            id = mult_matriz(id,Aq[index]);
        } index++;
    }
    id = mult_matriz(id,base);

    return (make_pair(mod(id[0][0],mmod), mod(id[3][0],mmod)));
}



int main(){
    fastio;

    int t = 0; cin >> t; int count = 1;

    while(t--){
        cout << "Case " << count << ":" << endl; count++;
        base.resize(0); A.resize(0); Aq.resize(0);
        cin >> a1 >> b1 >> c1;
        cin >> a2 >> b2 >> c2;
        cin >> f0 >> f1 >> f2;
        cin >> g0 >> g1 >> g2;
        cin >> mmod; a1 = mod(a1,mmod); b1 = mod(b1,mmod); c1 = mod(c1,mmod); a2 = mod(a2,mmod); b2 = mod(b2,mmod); c2 = mod(c2,mmod);
        base = {{mod(f2,mmod)}, {mod(f1,mmod)}, {mod(f0,mmod)}, {mod(g2,mmod)}, {mod(g1,mmod)}, {mod(g0,mmod)}};
        A = {{a1,b1,0,0,0,c1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,c2,a2,b2,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
        vector<vll> Atemp = A;
        Aq.resize(34);
        for(int i = 0; i < 34; i++){
            Aq[i] = Atemp;
            Atemp = mult_matriz(Atemp, Atemp);
        }
        int q; vll querries;
        cin >> q; querries.resize(q);
        for(int i = 0; i < q; i++) cin >> querries[i];
        for(auto x: querries){
            pll answ = recorrencia_matriz(x);
            cout << answ.f << esp << answ.s << endl;
        } 
    }

    return 0;
}