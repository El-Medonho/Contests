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

vii pai(0), peso(0);
set<int> pais; int pesos = 1;

int ff(int x){
    if(pai[x]==x) return x;
    return pai[x]=ff(pai[x]);
}

void uu(int x, int y){
    x=ff(x), y=ff(y);
    if(x==y) return;
    if(peso[y]>peso[x]) swap(x, y);
    pais.erase(y);
    pai[y]=x;
    peso[x]+=peso[y];
    pesos = max(pesos, peso[x]);
}

void init(int szsz){
    for(int i=0; i<szsz; i++){
        pai[i]=i;
        pais.insert(i);
        peso[i]=1;
    }
}

int main(){
    fastio;

    int n,m; cin >> n >> m;
    pai.resize(n); peso.resize(n);
    init(n);

    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        uu(a,b);

        cout << pais.size() << esp << pesos << endl;
    }

    return 0;
}