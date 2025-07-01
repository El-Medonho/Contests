#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long ll;
typedef long double ld;

int main(){
  fastio;
  //Complexidade O(ai*n)
  int n; cin >> n;
  vector<int> lista(n);
  
  int resposta = 0,maior = 0,menor = 200;

  for(int i = 0; i < n; i++){
    cin >> lista[i];
    maior = max(maior,lista[i]);
    menor = min(menor,lista[i]);
  }

  while(menor != maior){ // O(ai) no pior caso
    int proximo_menor = 200;
    for(int i = 0; i < n; i++){ // O(n)
        if(lista[i] == menor){ 
        if(i+1 == n || lista[i+1] != lista[i]) resposta++; //Encontramos um bloco
        lista[i] += 1;
        }
        proximo_menor = min(proximo_menor,lista[i]);
    }
    menor = proximo_menor;
  }

  cout <<  resposta << '\n';
  return 0;
}