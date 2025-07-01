// Hotel
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long ll;
typedef long double ld;

int main(){
  fastio;
  //Complexidade O(n log n)
  int n,d; ll w; cin >> n >> d >> w;

  vector<ll> soma_pref(n+1);
  soma_pref[0] = 0;

  for(int i = 1; i <= n; i++){
    cin >> soma_pref[i]; soma_pref[i] += soma_pref[i-1];
  }

  int l = 1,r = d,resp = 0;
  multiset<ll> soma_d;
  soma_d.insert(-(soma_pref[r]));

  while(r <= n){ //O(n)
    ll custo = (soma_pref[r] - soma_pref[l-1]) + *(soma_d.begin());
    if(custo <= w){
      //Contabilizo a resposta
      resp = max(resp,(r-l)+1);
      //Aumento r e adiciono a nova soma de r a (r-d+1)de tamanho D
      r++;
      if(r <= n) soma_d.insert(-(soma_pref[r] - soma_pref[r-d])); //O(log n)
    }
    else{
      //Se não, retiro a soma de l a l+d-1 e aumento l
      soma_d.erase(soma_d.find(-(soma_pref[(l+d)-1] - soma_pref[l-1]))); // O(log n)
      l++;
    }
  }

  cout << resp << '\n';
  return 0;
}