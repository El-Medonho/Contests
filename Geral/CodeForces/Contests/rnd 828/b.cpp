#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int main(){
    fastio;
    int t = 0;
    vector<ll> ans;
    cin >> t;
    ans.resize(t,0);
    for(int g = 0; g<t; g++){
        int n,q;
        cin >> n >> q;
        vector<int> arr;
        bool juncao = false;
        arr.resize(n,0);
        for (int i = 0; i<n; i++) {int u = 0; cin >> u; arr[i] = u;}

        ll par = 0; ll impar = 0; ll total = 0;
        int numspar = 0; int numsimpar = 0; int currpar = 0;
        
        for (int i = 0; i<n; i++){
            if (arr[i] % 2 == 0){
                numspar++; par += arr[i];
            }
            else { numsimpar++; impar += arr[i];}
        }

        if(numsimpar == 0) {juncao = true; currpar = 0;}
        if(numspar == 0) {juncao = true; currpar = 1;}

        total = par + impar;

        for (int i = 0; i < q; i++){
            int paridade = 0, val = 0; 
            cin >> paridade >> val;

            if (juncao) {
                if (currpar == paridade) {
                total += val * n;
                if (val % 2 == 1) currpar = (currpar + 1) % 2;}
            }
            else{
                if (paridade == 0){
                    par += val * numspar;
                    if (val % 2 == 1) {juncao = true; currpar = 1;}
                }
                else{
                    impar += val * numsimpar;
                    if (val % 2 == 1) {juncao = true; currpar = 0;}
                }
                total = par + impar;
            }
            cout << total << endl;
        }
    }
}