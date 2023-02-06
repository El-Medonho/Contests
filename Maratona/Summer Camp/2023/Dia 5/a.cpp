#include <bits/stdc++.h>

#define MOD 1000000007
#define mod(x, mv) (((x%mv)+mv)%mv)
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
#define pii pair<long long, long long>
#define INF 0x3f3f3f3f

using namespace std;

ll f0,f1,f2,g1,g2,g0, m, bs1, bs2,c1,c2;
vll queries;
vector<vll> base; vector<vector<vll>> Aquerry; vector<vector<vll>> Bquerry; vector<vll> A; vector<vll> B; vector<vll> b1,b2;


vector<vll> mult_matriz(vector<vll> a, vector<vll> b){
    vector<vll> z(a.size());
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            ll sum = 0;
            for(int k = 0; k < a[0].size(); k++){
                sum += mod(a[i][k]*b[k][j],m);
                sum=mod(sum,m);
            }
            z[i].pb(mod(sum,m));
        }
    }
    return z;
}

pair<ll,ll> recorrencia_matriz(ll penis){
    if(penis == 0) return(make_pair(mod(f0,m),mod(g0,m)));
    // cout << f0 << es << f1 << es << f2 << endl;
    // cout << g0 << es << g1 << es << g2 << endl;
    if(penis == 1) return(make_pair(mod(f1,m),mod(g1,m)));
    penis -=2; ll expo = penis;
    vll digits(0);

    while(expo>1){
        digits.pb(expo%2); expo/=2;
    }
    digits.pb(expo);

    vector<vll> id = {{1,0,0},{0,1,0},{0,0,1}};
    int ind = 0;
    for(auto x: digits){
        if(x == 1){
            id = mult_matriz(id, Aquerry[ind]);
        }
        ind++;
    } ind = 0;
    id = mult_matriz(id,b1);
    ll ans1 = id[0][0];   

    expo = penis;
    digits.resize(0);

    while(expo>1){
        digits.pb(expo%2); expo/=2;
    }
    digits.pb(expo);

    id = {{1,0,0},{0,1,0},{0,0,1}};
    for(auto x: digits){
        if(x == 1){
            id = mult_matriz(id,Bquerry[ind]);
        }
        ind++;
    }
    id = mult_matriz(id,b2);
    ll ans2 = id[0][0];   
    return (make_pair(ans1,ans2));
}





int main(){
    int t = 0; cin >> t;
    ll a1,a2,q;
    int tat=t;
    int cont = 0;
    vector<pii> resp[55];
    string sla;
    while(t--){
        //getline(cin, sla);
        //cout << "Case " << cont++ << ":" << endl;
        cont++;
        f0 = 0; f1 = 0; f2 = 0; g0 = 0; g1 = 0; g2 = 0;
        cin >> a1 >> bs1 >> c1;
        cin >> a2 >> bs2 >> c2;
        cin >> f0 >> f1 >> f2;
        cin >> g0 >> g1 >> g2;
        cin >> m;
        cin >> q;
        a1 = mod(a1,m); bs1 = mod(bs1,m); c1 = mod(c1,m);
        a2 = mod(a2,m); bs2 = mod(bs2,m); c2 = mod(c2,m);
        f2 = mod(f2,m); f1 = mod(f1,m); f0 = mod(f0,m);
        g2 = mod(g2,m); g1 = mod(g1,m); g0 = mod(g0,m);
        queries.resize(0); queries.resize(q);
        for(int i = 0; i < q; i++) cin >> queries[i];
        A = {{a1,bs1,c1},{1,0,0},{0,1,0}};
        B = {{a2,bs2,c2},{1,0,0},{0,1,0}};
        b1 = {{f2},{f1},{f0}}; 
        b2 = {{g2},{g1},{g0}};

        Aquerry.resize(0); Bquerry.resize(0); Aquerry.resize(40); Bquerry.resize(40);
        for(int i = 0; i < 40; i++){
            Aquerry[i] = A;
            Bquerry[i] = B;
            A = mult_matriz(A,A);
            B = mult_matriz(B,B);
        }
        for(auto x : queries){
            pair<ll,ll> ans = recorrencia_matriz(x);
            resp[cont].pb({ans.f, ans.s});
        }
        // cout << Aquerry[1][0][0] << es << Aquerry[2][0][0] << Aquerry[3][0][0] << endl;
    }
    for(int i=1; i<=tat; i++){
        cout << "Case " << i << ":" << endl;
        for(pii j:resp[i]){
            cout << mod(j.f, m) << es << mod(j.s, m) << endl;
        }
    }
}