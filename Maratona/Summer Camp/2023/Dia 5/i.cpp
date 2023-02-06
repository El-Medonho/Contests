#include <bits/stdc++.h>

#define MOD 1000000007
#define mod(x) (((x%MOD)+MOD)%MOD)
#define mxn 505
#define mxm 100005
#define pb push_back
#define f first
#define s second
typedef long long ll;
#define vii vector<int> 
#define vll vector<ll>
#define sz(x) (int)x.size()
#define es " "
#define endl "\n"
#define pip pair<int, pair<int, int> >
#define pii pair<int, int>
#define INF 0x3f3f3f3f


using namespace std;

vector<vll> mult_matriz(vector<vll> a, vector<vll> b){
    vector<vll> z(a.size());
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            ll sum = 0;
            for(int k = 0; k < a[0].size(); k++){
                sum += mod(a[i][k]*b[k][j]);
                sum=mod(sum);
            }
            z[i].pb(mod(sum));
        }
    }
    return z;
}

ll expo; vector<vll> base; vector<vll> A;

vector<vll> recorrencia_matriz(){
    vll digits(0);

    while(expo>1){
        digits.pb(expo%2); expo/=2;
    }
    digits.pb(expo);

    vector<vll> id = {{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}}; //n eh
    for(auto x: digits){
        if(x == 1){
            id = mult_matriz(id,A);
        }
        A = mult_matriz(A,A);
    }
    id = mult_matriz(id,base);

    return id;
}



int main(){
    ll n;
    ll ans;
    ans = 0;
    n = 0; //n eh
    expo = 0; //n eh
    cin >> n;
    if(n < 10) {cout << 1 << endl; return 0;}
    if(n < 20) {cout << 17 << endl; return 0;}    
    if(n < 30) {cout << 282 << endl; return 0;}
    if(n < 40) {cout << 4670 << endl; return 0;}
    // if(n < 45) {cout << 77328 << endl; return 0;}
    // if(n < 50) {cout << 77327 << endl; return 0;}

    A.resize(5);
    A = {{16,9,4,1,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0}};
    base = {{72658},{4388},{265},{16},{1}};
    ll alt = n;
    if(n%10>=5) alt+=5;
    expo = (alt/10)-4;
    vector<vll> res = recorrencia_matriz();
    if((n)%10>=5) {for(int i = 1; i < 5; i++) ans+=res[i][0]; ans=mod(ans);}
    else{for(int i = 0; i < 5; i++) ans+=res[i][0]; ans=mod(ans);}
    cout << ans << endl;
    return 0;
}