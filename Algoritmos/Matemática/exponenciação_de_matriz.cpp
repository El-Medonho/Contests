#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;


// função para multiplicar matrizes (MOD opcional) (uso de ll é possível)
vector<vector<ll>> mult_matriz(vector<vector<ll>> a, vector<vector<ll>> b){    //possivel usar "&"
    vector<vector<ll>> z(a.size(), vector<ll>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            ll sum = 0;
            for(int k = 0; k < a[0].size(); k++){
                sum += mod(a[i][k]*b[k][j],MOD);
                sum=mod(sum,MOD);
            }
            z[i][j] = (mod(sum,MOD));
        }
    }
    return z;
}


vector<vector<ll>> recorrencia_matriz(ll expo, vector<vector<ll>> base, vector<vector<ll>> A){
    //exponenciação de matriz (dim 3 no exemplo)
    //id - matriz identidade; A - matriz de recorrência; base - vetor base; expo - expoente da matriz
    //base = {{1},{1},{1}}; - formato da base
    //retorna o vetor resultante
    vector<ll> digits(0);

    while(expo>1){
        digits.push_back(expo%2); expo/=2;
    }
    digits.push_back(expo);

    vector<vector<ll>> id = {{1,0,0},{0,1,0},{0,0,1}};
    for(auto x: digits){
        if(x == 1){
            id = mult_matriz(id,A);
        }
        A = mult_matriz(A,A);
    }
    id = mult_matriz(id,base);

    return id;
}