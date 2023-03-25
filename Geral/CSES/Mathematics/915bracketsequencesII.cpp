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
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

ll expo(ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1)res = mod(res*b,MOD);
        b = mod(b*b, MOD);
        e>>=1;
    }
    return res;
}

int main(){
    fastio;

    int n; cin >> n;

    int stk = 0;
    string str; cin >> str;

    if(n%2 == 1){
        cout << 0 << endl;
        return 0;
    }
    n>>=1;

    for(char c: str){
        if(c == '('){
            stk++;
        }else{
            if(stk == 0){
                cout << 0 << endl;
                return 0;
            }
            stk--;
            n--;
        }
    }
    if(stk > n){
        cout << 0 << endl;
        return 0;
    }
    if(n == 0){
        cout << 1 << endl;
        return 0;
    }

    vll fact(4*n,1);
    for(int i = 1; i < 4*n; i++){
        fact[i] = mod(fact[i-1]*i, MOD);
    }

    ll k = stk;
    n-=k;

    ll ans = mod((k+1)*fact[2*n+k], MOD);
    ll den = mod((n+k+1)*fact[n],MOD);
    den = mod(den*fact[n+k],MOD);
    den = expo(den,MOD-2);

    cout << mod(ans*den,MOD) << endl;

    return 0;
}