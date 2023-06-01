#include <bits/stdc++.h>
using namespace std;

int main(){
   
    int n; cin >> n;

    map<int,int> inicial; //dicionario
    map<int,int> soma;
    set<int> amigos;
    int tempo = 0;
    while(n--){
        char c;
        cin >> c;

        if(c == 'R'){
            tempo+=1;

            int aux; cin >> aux;
            amigos.insert(aux);
            inicial[aux] = tempo;
        }
        else if(c == 'E'){
            tempo+=1;

            int aux; cin >> aux;
            soma[aux] += tempo - inicial[aux];
            inicial[aux] = -1;
        }
        else{
            int aux; cin >> aux;
            tempo += aux-1; 
        }
    }

    for(int i: amigos){
        cout << i << ' ';
        if(inicial[i] == -1) cout << soma[i] << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}