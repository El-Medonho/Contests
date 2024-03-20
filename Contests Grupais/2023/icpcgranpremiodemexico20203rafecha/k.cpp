#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define mod(x, m) (((x % m) + m) % m)
#define mxn 100005
#define mxm 100005
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
typedef pair<pii, int> pip;
 
int t;
ll fact[2*mxn];

ll exp(ll x, ll n) {
    if (n == 0) return 1;
    long long u = exp(x,n/2);
    u = mod((u*u), MOD);
    if (n%2 == 1) u = mod((u*x), MOD);
    return u;
}

ll escolhe(int a, int b){
    ll mult=fact[a];
    ll div=mod(fact[b]*fact[a-b], MOD);
    div=mod(div, MOD);
    div=exp(div, MOD-2);
    return mod(mult*div, MOD);
}

int main(){
    fastio;
    fact[0]=1;
    for(int i=1; i<=200002; i++){
        fact[i]=mod(fact[i-1]*i, MOD);
        fact[i]=mod(fact[i], MOD);
    }
    cin >> t;
    while(t--){
        int A, B, C, k, c;
        cin >> A >> B >> C >> k >> c;
        ll resp = 0;
        if(k > c) resp=escolhe(C, c);
        if(k == c) {
            cout << 0 << endl;
            continue;
        }
        if(k-c <=1) {
            cout << 0 << endl;
            continue;
        }
        ll ans=0;
        if(A+B>=k-c){
            ans+=escolhe(A+B, k-c);
        }else{
            cout << 0 << endl;
            continue;
        }
        if(A>=k-c){
            ans-=escolhe(A, k-c);
        }
        if(B>=k-c){
            ans-=escolhe(B, k-c);
        }
        resp=mod(resp*ans, MOD);
        resp=mod(resp, MOD);
        cout << resp << endl;
    }
    return 0;
}