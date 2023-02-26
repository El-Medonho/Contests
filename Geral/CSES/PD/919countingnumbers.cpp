#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<ll,ll>
#define pll pair<long long,long long>
#define vii vector<ll>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

int main(){
    fastio;

    ll a, b; cin >> a >> b;
    ll bog = b;
    vector<vll> dp(19, vll(11, 0));
    for(ll i = 0; i < 11; i++) dp[0][i] = 1;

    for(ll i = 1; i < 19; i++){
        for(ll j = 0; j < 10; j++){
            for(ll k = 0; k < 10; k++){
                if(k == j) continue;        //problema com os 0s (0 a esquerda n conta)
                dp[i][j] += dp[i-1][k];
            }
        }
        for(ll j = 0; j < i; j++){
            for(ll k = 1; k < 10; k++){
                dp[i][10] += dp[j][k];
            }
        }
        dp[i][10]++;
    }

    ll ansb = 0, ansa = 0;

    ll auxb = 1, digb = 0, diga = 0, auxa = 1; 

    while((b/auxb) >= 10) {auxb*=10; digb++;}
    while((a/auxa) >= 10) {auxa*=10; diga++;}

    bool first = true;
    ll last = -1;
    while(b > 0){
        for(ll i = 0; b > 0 && i < b/auxb; i++){
            if(first){
                first = false;
                ansb += dp[digb][10];
                continue;
            }
            if(i == last) continue;
            ansb += dp[digb][i];
        }
        if(b/auxb == last) break;
        last = b/auxb;
        digb--;
        b%=auxb;
        auxb/=10;
    }

    first = true; last = -1;
    while(a > 0){
        for(ll i = 0; a > 0 && i < a/auxa; i++){
            if(first){
                first = false;
                ansa += dp[diga][10];
                continue;
            }
            if(i == last) continue;
            ansa += dp[diga][i];
        }
        if(a/auxa == last) break;
        last = a/auxa;
        diga--;
        a%=auxa;
        auxa/=10;
    }

    last = -1; bool raise = true;
    while(bog > 0){
        ll curr = bog%10;
        if(curr == last){
            raise = false;
            break;
        }
        last = curr;
        bog/=10;
    }

    if(raise) ansb++;

    ll ans = ansb-ansa;
    // if(a == 0 && b != 0) ans++;

    cout << ans << endl;

    return 0;
}