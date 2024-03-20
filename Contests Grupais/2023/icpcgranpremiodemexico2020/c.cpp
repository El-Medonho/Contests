//MEDONHO APENAS

#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define vld vector<long double>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void mul_matriz(vector<vld> &a, vector<vld> &b, int op = 1){
    vector<vld> z(a.size(), vld(b.size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            ld sum = 0;
            for(int k = 0; k < a[0].size(); k++){
                sum += a[i][k]*b[k][j];
            }
            z[i][j] = (sum);
        }
    }

    if(op){
        for(int i = 0; i < b.size(); i++){
            for(int j = 0; j < b[0].size(); j++){
                b[i][j] = z[i][j];
            }
        }
    }else{
        a = z;
    }

    return;
}

vector<vld> recorrencia(int expo, vector<vld> base, vector<vld> A){
    vll digits(0);

    while(expo > 1){
        digits.pb(expo%2); expo>>=1;
    }
    digits.pb(expo);

    vector<vld> id(A.size(), vld(A.size(),0));
    for(int i = 0; i < A.size(); i++) id[i][i] = 1;

    for(auto x: digits){
        if(x == 1){
            mul_matriz(A,id);
        }
        mul_matriz(A,A);
    }
    mul_matriz(base,id,0);

    return base;
}

int main(){
    fastio;

    int n, m; cin >> n >> m;

    vector<vld> grid(n, vld(n));
    vector<vld> gg(n, vld(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> gg[i][j];
    }

    vector<vld> base(1, vld(n,0));
    base[0][0] = 1;

    vector<vld> ans = recorrencia(m,base,grid);

    for(int i = 0; i < n; i++) cout << ans[0][i] << endl;

    return 0;
}