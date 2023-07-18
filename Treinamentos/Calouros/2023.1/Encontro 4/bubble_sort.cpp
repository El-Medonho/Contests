#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> v(n);
    for(int i = 0; i<n; i++) cin >> v[i];
    
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }


    return 0;
}