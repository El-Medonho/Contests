#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
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

int main(){
    fastio;

    ll n,g; cin >> n >> g;
    vll arr(n,0);
    vll bigger(0);
    vll occur(24,0);

    ll sum = 0;
    for(ll &i: arr) {cin >> i; sum += i;}

    ll sz = 1, gg = n;
    while(gg--) sz*=2;

    ll m = n;

    for(int i = 1; i < sz; i++){
        ll caras = 0, preco = 0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                preco += arr[j];
                caras++;
            }
        }
        if((preco*100)/sum >= g){
            m = min(m, caras);
            bigger.pb(i);
            occur[caras]++;
        }
    }

    cout << m << esp << occur[m] << endl;
    vii jjg(m,0);

    for(int i: bigger){
        ll caras = 0, preco = 0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                preco += arr[j];
                caras++;
            }
        }
        if(caras == m){
            cout << (preco*100)/sum << esp;
            int ind = 0;
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){
                    jjg[ind++] = j+1;
                }
            }
            for(int cv = 0; cv < m-1; cv++){
                cout << jjg[cv] << esp;
            }
            cout << jjg[m-1] << endl;
        }
    }


    return 0;
}