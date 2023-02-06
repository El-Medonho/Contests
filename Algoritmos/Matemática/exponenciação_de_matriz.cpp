#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
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


vector<vll> recorrencia_matriz(int expo, vector<vll> base, vector<vll> A){
    //exponenciação de matriz (dim 3 no exemplo)
    //id - matriz identidade; A - matriz de recorrência; base - vetor base; expo - expoente da matriz
    //base = {{1},{1},{1}}; - formato da base
    //retorna o vetor resultante
    vll digits(0);

    while(expo>1){
        digits.pb(expo%2); expo/=2;
    }
    digits.pb(expo);

    vector<vll> id = {{1,0,0},{0,1,0},{0,0,1}};
    for(auto x: digits){
        if(x == 1){
            id = mult_matriz(id,A);
        }
        A = mult_matriz(A,A);
    }
    id = mult_matriz(id,base);

    return id;
}