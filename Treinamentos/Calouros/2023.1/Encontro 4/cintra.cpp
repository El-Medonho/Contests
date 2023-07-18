#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    int x;
    cin >> n >> x;
    int v[n];
    int k[x];
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<x;i++){
        cin >> k[i];
    }
    for(int i=0; i<x; i++){
        int l= 0, r= n-1;
        int meio;
        int resp = -1;
        while(l<=r){
            meio = (l+r)/2;
            if (v[meio] == k[i]){
                resp = meio;
                
            }
            if (v[meio]>= k[i]){
                r = meio - 1;
            }
            if (v[meio]< k[i]){
                l = meio + 1;
            }
        }
        cout << resp << '\n';
    }   
    return 0;
}