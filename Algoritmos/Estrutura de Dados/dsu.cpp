#include "bits/stdc++.h"

using namespace std;

vector<int> pai(0), peso(0);

int ff(int x){
    if(pai[x]==x) return x;
    return pai[x]=ff(pai[x]);
}

void uu(int x, int y){
    x=ff(x), y=ff(y);
    if(x==y) return;
    if(peso[y]>peso[x]) swap(x, y);
    pai[y]=x;
    peso[x]+=peso[y];
}

void init(int n){
    for(int i=0; i<n; i++){
        pai[i]=i;
        peso[i]=1;
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;

    vector<int> pai(n), peso(n, 1);
    for(int i = 0; i < n; i++){
        pai[i] = i;
    }

    function<int(int)> ff;

    ff = [&](int x){
        if(pai[x]==x) return x;
        return pai[x]=ff(pai[x]);
    };

    function<void(int,int)> uu;

    uu = [&](int x, int y){
        x=ff(x), y=ff(y);
        if(x==y) return;
        if(peso[y]>peso[x]) swap(x, y);
        pai[y]=x;
        peso[x]+=peso[y];
    };

    return 0;
}