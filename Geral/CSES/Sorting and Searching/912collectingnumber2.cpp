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

    int n,m; cin >> n >> m;
    vii arr(n,0), pos(n,0), inicia(n,0), termina(n,0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i]; arr[i]--;
        pos[arr[i]] = i;
    }

    int loops = 1;
    inicia[0] = 1; termina[n-1] = 1;
    for(int i = 0; i < n; i++){
        if(i != 0 && pos[i-1] > pos[i]) {
            loops++;
            termina[i-1] = 1;
            inicia[i] = 1;
        }
    }

    while(m--){
        int a,b; cin >> a >> b; a--; b--;
        if(a == b) {cout << loops << endl; continue;}
        int p,q;
        int cup = arr[a];
        p = arr[a]; q = arr[b];
        arr[a] = arr[b]; arr[b] = cup;
        a = pos[p]; b = pos[q];
        cup = a;
        pos[p] = b; pos[q] = cup;
    
        if(abs(p-q) > 1){
            for(int i = 0; i < 2; i++){
                int ind;
                if(i == 1){ind = q;}
                else {ind = p;}

                if(ind != 0){       
                    if(pos[ind-1] < pos[ind] && termina[ind-1] == 1){termina[ind-1] = 0; inicia[ind] = 0; loops--;}
                    else if(pos[ind-1] > pos[ind] && termina[ind-1] == 0) {termina[ind-1] = 1; inicia[ind] = 1; loops++;}
                }
                if(ind != n-1){
                    if(pos[ind+1] > pos[ind] && termina[ind] == 1){termina[ind] = 0; inicia[ind+1] = 0; loops--;}
                    else if(pos[ind+1] < pos[ind] && termina[ind] == 0){termina[ind] = 1; inicia[ind+1] = 1; loops++;}
                }
            }
        }

        else{
            int d,e; e = max(p,q); d = min(p,q);

            if(e != n-1 && pos[e+1] > pos[e] && termina[e] == 1){termina[e] = 0; inicia[e+1] = 0; loops--;}
            else if(e != n-1 && pos[e+1] < pos[e] && termina[e] == 0){termina[e] = 1; inicia[e+1] = 1; loops++;}

            if(pos[e] > pos[d] && termina[d] == 1){termina[d] = 0; inicia[e] = 0; loops--;}
            else if(pos[e] < pos[d] && termina[d] == 0){termina[d] = 1; inicia[e] = 1; loops++;}

            if(d != 0 && pos[d-1] < pos[d] && termina[d-1] == 1){termina[d-1] = 0; inicia[d] = 0; loops--;}
            else if(d != 0 && pos[d-1] > pos[d] && termina[d-1] == 0) {termina[d-1] = 1; inicia[d] = 1; loops++;}
        }

        cout << loops << endl;
    }

    return 0;
}