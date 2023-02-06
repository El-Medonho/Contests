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

vector<int> fatoracao(int n){
    vector<int> fatores(0);
    if(!(n&1)) fatores.push_back(2);
    while(!(n&1)){
        n>>=1;
    }
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) fatores.push_back(i);
        while(n%i==0){
            n/=i;
        }
    }
    if(n != 1) fatores.push_back(n);
    return fatores;
}

int main(){
    fastio;
    vii k = fatoracao(90);
    for(int x:k) cout << x << endl;
    return 0;
}