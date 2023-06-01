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

int t = 0;

int main(){
    fastio;

    cin >> t;

    for(int g = 0; g < t; g++){
        int n,m,limit; vector<int> relacao, blocos, torres;
        cin >> n >> m >> limit;
        relacao.resize(n); blocos.resize(n); torres.resize(m,0);

        for(int i = 0; i < n; i++){
            int a = 0;
            cin >> a;
            blocos[i] = a;
            
        }
    }

    return 0;
}