#include "bits/stdc++.h"
using namespace std;
#define MOD 13371337
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;


vector<vector<ll>> mult_matriz(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> C;
    C.resize(A.size());
    for(ll i = 0; i < A.size(); i++){
        C[i].resize(B[i].size(), 0);
        for (ll j = 0; j < B[i].size(); j++){
            ll sum = 0;
            for (ll k = 0; k < A[i].size(); k++){
                sum += A[i][k]*B[k][j];
            }
            C[i][j] = mod(sum, MOD);
        }
    }
    return C;
}

int main(){
    ll n;
    vector<ll> ans;
    while (cin >> n){
        if(n == 0) break;
        n-=4;
        vector<ll> inp;
        for(ll i=0;i<4;i++){
            ll k;
            cin >> k;
            inp.push_back(k);
        }
        ll quarto = (inp[0] + inp[1] + inp[2] + inp[3]);
        vector<vector<ll>> A;
        vector<vector<ll>> base;
        vector<vector<ll>> U;

        A = {{1,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
        U = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        base = {{quarto}, {inp[3]}, {inp[2]},{inp[1]}};

        vector<ll> digits = {};
        while(n>1){
            digits.push_back(mod(n,2));
            n/=2;
        }
        digits.push_back(n);

        for (auto i: digits){
            if (i == 1) U = mult_matriz(U,A);
            A = mult_matriz(A,A);
        }
        U = mult_matriz(U, base);
        ans.push_back(U[0][0]);
    }
    for(auto i: ans) cout << i << endl;
}