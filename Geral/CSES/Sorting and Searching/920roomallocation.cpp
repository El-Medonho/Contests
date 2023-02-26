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

    int n; cin >> n;
    vector<pii> arr(n); vii guests(n,-1), ans(n,0);
    priority_queue<pii, vector<pii>, greater<pii>> entradas, saidas;
    priority_queue<int, vii, greater<int>> quartos;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        arr[i] = {a,b};

        entradas.push({a,i});
        saidas.push({b,i});
        quartos.push(i);
    }

    int occ = 0, k = 0;
    while(!saidas.empty()){
        if(!entradas.empty() && entradas.top().f <= saidas.top().f){
            pii curr = entradas.top();
            entradas.pop();

            ans[curr.s] = quartos.top();
            quartos.pop();
            occ++;
        }
        else{
            pii curr = saidas.top();
            saidas.pop();

            occ--;
            quartos.push(ans[curr.s]);
        }
        k = max(occ, k);
    }

    cout << k << endl;
    for(int i = 0; i < n-1; i++) cout << ans[i]+1 << esp;
    cout << *ans.rbegin()+1 << endl;

    return 0;
}