#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define mod(x, m) (((x % m) + m) % m)
#define mxn 1000005
#define mxm 1000005
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
 
int t, n_primo[mxn];
void crivo(){
    n_primo[1]=1;
    for(int i=2; i<1e6; i++){
        if(n_primo[i]) continue;
        for(int j=2; i*j<1e6; j++){
            n_primo[i*j]=1;
        }
    }
}

ll expo(ll b, ll e, ll m){
    ll res=1;
    while(e){
        if(e&1){
            res=mod(res*b, m);
        }
        b=mod(b*b, m);
        e>>=1;
    }
    return res;
}

void file(string name){
    freopen((name+".txt").c_str(), "r", stdin);
    freopen((name+"_out.txt").c_str(), "w", stdout);
}

int main(){
    fastio;
    file("pen");
    cin >> t;
    crivo();
    vector<int> primos(0);
    for(int i=3; i<=1e6; i++) if(!n_primo[i]) primos.pb(i);
    // cout << primos.size() << endl;
    while(t--){
        int k;
        cin >> k;
        bool pass = false;
        for(int gg = 0; gg < primos.size(); gg++){
            int i = primos[gg];
            if(i>k) break; 
            ll agr = 1;
            // agr=expo(2, i, i);
            ll b = 2, m = i, e = i;
            while(e){
                if(e&1){
                    agr=mod(agr*b, m);
                }
                b=mod(b*b, m);
                e>>=1;
            }
            
            agr+=(k%i);
            agr%=i;
            if(!agr && pass) {cout << es << i;}
            if(!agr && !pass) {cout << i; pass = true;}
        }
        if(!pass) cout << -1 << endl;
        else cout << endl;
    }
    return 0;
}