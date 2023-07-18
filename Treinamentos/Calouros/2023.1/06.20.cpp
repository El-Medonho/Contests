#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;

    int n; cin >> n;        //tamanho da lista

    vector<int> lista;

    for(int i = 0; i < n; i++){     //pegar os valores da lista
        int x; cin >> x;
        lista.push_back(x);
    }

    int val; cin >> val;

    int ans = -1;
    // for(int i = 0; i < n; i++){     //O(n)
    //     if(lista[i] == val){
    //         ans = i;
    //         break;
    //     }
    // } 

    int l = 0, r = n-1;

    while( l <= r ){
        int meio = (l+r)/2;

        if(lista[meio] < val){
            l = meio+1;
        }
        else if(lista[meio] > val){
            r = meio-1;
        }
        else{
            ans = meio;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}